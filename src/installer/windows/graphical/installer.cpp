#include "lang.hpp"
#include <string>
#include <latest_control.h>
using namespace std;

#pragma comment(lib,"User32.lib")
#pragma comment(lib,"Gdi32.lib")

UINT bg_r=120;
UINT bg_g=120;
UINT bg_b=255;
ULONG64 loop_cnt=0;

HWND main_window;
HWND button_install;
HWND button_upgrade;
HWND install_path_input;
HWND button_next;
HWND button_back;
HWND button_exit;
HWND button_about;

LOGFONTW title_font;
LOGFONTW text_font;

HFONT hfont;
bool setfont_done=false;

HANDLE colorful_bg_thread;
bool reserve_gradient=false;

#define TEXT_COLOR RGB(255,255,255)

#define BUTTON_INSTALL (HMENU)201
#define BUTTON_UPGRADE (HMENU)202
#define INPUT_INSTALL_PATH (HMENU)203
#define BUTTON_NEXT (HMENU)204
#define BUTTON_BACK (HMENU)205
#define BUTTON_EXIT (HMENU)206
#define BUTTON_ABOUT (HMENU)207

bool installing=false;
bool refresh=false;
wchar_t install_path[16384];
HINSTANCE hinstance;

enum stats
{
    FIRST_STEP=0,
    SELECT_INSTALL_PATH,
    SELECT_MODULES_TO_INSTALL,
    INSTALLING,
    INSTALL_DONE,
};

BYTE state=0;

void CancelInstall(void) noexcept
{
    wstring install_p=install_path;
}

void DrawBackground(HDC hdc) noexcept
{
    RECT client_rect;
    GetClientRect(main_window,&client_rect);
    BYTE BG_R=200;
    BYTE BG_G=200;
    BYTE BG_B=255;
    UINT loop_cnt=0;
    for(int y=0;y<=client_rect.bottom/2;y++,loop_cnt++)
    {
        RECT draw_rect=client_rect;
        draw_rect.top=y-1;
        draw_rect.bottom=y;
        FillRect(hdc,&draw_rect,CreateSolidBrush(RGB(BG_R,BG_G,BG_B)));
        if(BG_R!=0)
            BG_R-=2;
        if(loop_cnt%2==0&&BG_G!=0)
            BG_G--;
        if(loop_cnt%5==0&&BG_B!=30)
            BG_B--;
    }
    for(int y=client_rect.bottom/2+1;y<=client_rect.bottom;y++,loop_cnt--)
    {
        RECT draw_rect=client_rect;
        draw_rect.top=y-1;
        draw_rect.bottom=y;
        FillRect(hdc,&draw_rect,CreateSolidBrush(RGB(BG_R,BG_G,BG_B)));
        if(BG_R!=0)
            BG_R+=2;
        if(loop_cnt%2==0)
            BG_G++;
        if(loop_cnt%5==0)
            BG_B++;
    }
}

void DrawSolidColorBackground(HDC hdc,COLORREF color)
{
    RECT client_rect;
    GetClientRect(main_window,&client_rect);
    FillRect(hdc,&client_rect,CreateSolidBrush(color));
}

void DrawTestingVersionWatermark(HDC hdc)
{
    SelectObject(hdc,(HFONT)GetStockObject(SYSTEM_FONT));
    RECT client_rect;
    GetClientRect(main_window,&client_rect);
    TextOutW(hdc,1,client_rect.bottom-15,L"For testing purposes only",wcslen(L"For testing purposes only"));
    SelectObject(hdc,hfont);
}

DWORD WINAPI DrawColorfulBackgroundThread(LPVOID lParam)
{
    while(1)
    {
        RECT client_rect;
        GetClientRect(main_window,&client_rect);
        InvalidateRect(main_window,&client_rect,false);
        Sleep(45);
    }
    return 0;
}

LRESULT CALLBACK MainWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam) noexcept
{
    switch(uMsg)
    {
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case BUTTON_INSTALL:
                    state++;
                    refresh=true;
                    RECT client_rect;
                    GetClientRect(hwnd,&client_rect);
                    DestroyWindow(button_install);
                    DestroyWindow(button_upgrade);
                    DestroyWindow(button_exit);
                    DestroyWindow(button_about);
                    install_path_input=CreateWindowW(L"EDIT",L"C:\\Program Files\\Objective Shell\\",WS_CHILD|WS_VISIBLE,10,100,400,20,hwnd,INPUT_INSTALL_PATH,hinstance,NULL);
                    button_next=CreateWindowW(L"BUTTON",L"Next >",WS_CHILD|WS_VISIBLE,client_rect.left+2,client_rect.bottom+2,40,20,hwnd,BUTTON_NEXT,hinstance,NULL);
                    button_back=CreateWindowW(L"BUTTON",L"< Back",WS_CHILD|WS_VISIBLE,client_rect.right-42,client_rect.bottom+2,40,20,hwnd,BUTTON_BACK,hinstance,NULL);
                    UpdateWindow(main_window);
                    break;
                case BUTTON_UPGRADE:
                    MessageBoxW(NULL,L"This is the first version!",L"Error",MB_OK|MB_ICONERROR);
                    break;
                case BUTTON_NEXT:
                    switch(state)
                    {
                        case SELECT_INSTALL_PATH:
                            GetWindowTextW(install_path_input,install_path,16384);
                            WIN32_FIND_DATAW finddata;
                            wchar_t *install_path_original=new wchar_t[wcslen(install_path)+1];
                            wcscpy(install_path_original,install_path);
                            if(install_path[wcslen(install_path)]!=L'\\')
                                install_path[wcslen(install_path)+1]=L'\\';
                            install_path[wcslen(install_path)+1]=L'*';
                            HANDLE find_handle=FindFirstFileW(install_path,&finddata);
                            if(find_handle==INVALID_HANDLE_VALUE)
                                RemoveDirectoryW(install_path_original);
                            delete[] install_path_original;
                            break;
                    }
                    break;
                case BUTTON_BACK:
                    switch(state)
                    {
                        case SELECT_INSTALL_PATH:
                            DestroyWindow(button_back);
                            DestroyWindow(button_next);
                            DestroyWindow(install_path_input);
                            button_install=CreateWindowW(L"BUTTON",L"Install",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,BUTTON_INSTALL,hinstance,NULL);
                            button_upgrade=CreateWindowW(L"BUTTON",L"Upgrade",WS_CHILD|WS_VISIBLE,10,80,150,25,main_window,BUTTON_UPGRADE,hinstance,NULL);
                            button_about=CreateWindowW(L"BUTTON",L"About",WS_CHILD|WS_VISIBLE,10,110,150,25,main_window,BUTTON_ABOUT,hinstance,NULL);
                            button_exit=CreateWindowW(L"BUTTON",L"Exit",WS_CHILD|WS_VISIBLE,10,140,150,25,main_window,BUTTON_EXIT,hinstance,NULL);
                            state=FIRST_STEP;
                            refresh=true;
                            UpdateWindow(hwnd);
                            break;
                    }
                    break;
                case BUTTON_ABOUT:
                    MessageBoxW(main_window,L"Objective Shell\nCopyright(C)2019 CodesBuilder\n\nVersion:1.0.0.0001\nCodename:(to be determined)\nFor testing purposes only",L"About Objective Shell",MB_OK|MB_ICONINFORMATION);
                    break;
                case BUTTON_EXIT:
                    PostQuitMessage(0);
            }
            break;
        case WM_DESTROY:
            CloseHandle(colorful_bg_thread);
            PostQuitMessage(0);
            break;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc;
            if(refresh)
                hdc=GetDC(hwnd);
            else
                hdc=BeginPaint(hwnd,&ps);
            //DrawBackground(hdc);
            if(loop_cnt==3)
                reserve_gradient=false;
            if(loop_cnt==255)
                reserve_gradient=true;
            if(!reserve_gradient)
            {
                if(bg_r!=50)
                    bg_r-=2;
                if(bg_g!=50&&loop_cnt%2==0)
                    bg_g-=5;
                if(bg_b!=120&&loop_cnt%3==0)
                    bg_b--;
                loop_cnt++;
            }
            else
            {
                if(bg_r!=170)
                    bg_r+=2;
                if(bg_g!=170&&loop_cnt%2==0)
                    bg_g+=5;
                if(bg_b!=220&&loop_cnt%3==0)
                    bg_b++;
                loop_cnt--;
            }
            DrawSolidColorBackground(hdc,RGB(bg_r,bg_g,bg_b));
            if(!setfont_done)
            {
                title_font={0};
                title_font.lfCharSet=GB2312_CHARSET;
                title_font.lfItalic=false;
                title_font.lfHeight=20;
                title_font.lfWidth=10;
                title_font.lfEscapement=0;
                title_font.lfWeight=FW_NORMAL;
                title_font.lfUnderline=false;
                title_font.lfStrikeOut=false;
                title_font.lfQuality=PROOF_QUALITY;
                lstrcpyW(title_font.lfFaceName,L"Unifont");
                title_font.lfPitchAndFamily=FF_DONTCARE;
                title_font.lfClipPrecision=CLIP_CHARACTER_PRECIS;
                title_font.lfOutPrecision=OUT_CHARACTER_PRECIS;
                text_font=title_font;
                text_font.lfHeight=16;
                text_font.lfWidth=8;
                setfont_done=true;
            }
            hfont=CreateFontIndirectW(&title_font);
            SelectObject(hdc,hfont);
            SetBkMode(hdc,TRANSPARENT);
            SetTextColor(hdc,TEXT_COLOR);
            switch(state)
            {
                case FIRST_STEP:
                    TextOutW(hdc,10,10,L"Objective Shell Installer",wcslen(L"Objective Shell Installer"));
                    //SendMessage(button_install,WM_SETFONT,NULL,(LPARAM)hfont);
                    break;
                case SELECT_INSTALL_PATH:
                    TextOutW(hdc,10,10,L"Select Install Path",wcslen(L"Select Install Path"));
                    DeleteObject(hfont);
                    hfont=CreateFontIndirectW(&text_font);
                    SelectObject(hdc,hfont);
                    SetTextColor(hdc,TEXT_COLOR);
                    TextOutW(hdc,10,80,L"Install Path:",wcslen(L"Install Path:"));
                    break;
                default:
                    MessageBoxW(hwnd,L"Invalid state detected",L"Error",MB_OK|MB_ICONWARNING);
                    PostQuitMessage(1);
            }
            DeleteObject(hfont);
            if(refresh)
            {
                ReleaseDC(hwnd,hdc);
                refresh=false;
            }
            else
                EndPaint(hwnd,&ps);
            break;
        }
        case WM_CLOSE:
            if(installing)
                if(MessageBoxW(hwnd,L"Do you want to exit?",L"",MB_YESNO|MB_ICONQUESTION)==IDYES)
                {
                    CancelInstall();
                    DestroyWindow(hwnd);
                }
            break;
    }
    return DefWindowProcW(hwnd,uMsg,wParam,lParam);
}
int WINAPI wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int nShowCmd)
{
    hinstance=hInstance;
    LPCWSTR mainclass_name=L"Objective Shell Installer";
    WNDCLASSW mainclass={};
    mainclass.lpszClassName=mainclass_name;
    mainclass.hInstance=hInstance;
    mainclass.lpfnWndProc=MainWindowProc;
    mainclass.hCursor=LoadCursorW(NULL,(LPCWSTR)IDC_ARROW);
    RegisterClassW(&mainclass);
    main_window=CreateWindowW(mainclass_name,L"Objective Shell Installer",WS_OVERLAPPEDWINDOW,5,25,500,400,NULL,NULL,hInstance,NULL);
    if(main_window==NULL)
    {
        MessageBoxW(NULL,L"Create window failed!",L"Error",MB_OK|MB_ICONERROR);
        return 1;
    }
    ShowWindow(main_window,nShowCmd);
    button_install=CreateWindowW(L"BUTTON",L"Install",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,BUTTON_INSTALL,hInstance,NULL);
    button_upgrade=CreateWindowW(L"BUTTON",L"Upgrade",WS_CHILD|WS_VISIBLE,10,80,150,25,main_window,BUTTON_UPGRADE,hInstance,NULL);
    button_about=CreateWindowW(L"BUTTON",L"About",WS_CHILD|WS_VISIBLE,10,110,150,25,main_window,BUTTON_ABOUT,hInstance,NULL);
    button_exit=CreateWindowW(L"BUTTON",L"Exit",WS_CHILD|WS_VISIBLE,10,140,150,25,main_window,BUTTON_EXIT,hInstance,NULL);
    colorful_bg_thread=CreateThread(NULL,0,DrawColorfulBackgroundThread,NULL,NULL,NULL);
    MSG msg={};
    while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
    return 0;
}