#include "lang.hpp"
#include "res.h"
#include <string>
#include <latest_control.h>
#include <Vfw.h>
#include <stdio.h>

using std::wstring;

#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"msimg32.lib")

UINT bg_r=100;
UINT bg_g=110;
UINT bg_b=255;
UINT text_r=255;
UINT text_g=255;
UINT text_b=255;
UINT bg_loop_cnt=0;
UINT fg_loop_cnt=0;
UINT installation_progress_gloss_start=0;
const UINT installation_progress_gloss_length=8;
bool bg_reserve_gradient=false;
bool fg_reserve_gradient=false;

HWND main_window;
HWND button_install;
HWND button_upgrade;
HWND install_path_input;
HWND button_next;
HWND button_back;
HWND button_exit;
HWND button_about;
HWND feedback_window;

HANDLE colorful_bg_thread;
HANDLE status_check_thread;

LPCWSTR installation_progress=L" Select Install Path > ";

#define TEXT_COLOR RGB(255,255,255)

#define BUTTON_INSTALL (HMENU)201
#define BUTTON_UPGRADE (HMENU)202
#define INPUT_INSTALL_PATH (HMENU)203
#define BUTTON_NEXT (HMENU)204
#define BUTTON_BACK (HMENU)205
#define BUTTON_EXIT (HMENU)206
#define BUTTON_ABOUT (HMENU)207

bool visual_effects=false;
bool installing=false;
bool refresh=false;
wchar_t install_path[16384];
HINSTANCE hinstance;

enum statuses
{
    FIRST_STEP=0,
    SELECT_INSTALL_PATH,
    SELECT_MODULES_TO_INSTALL,
    INSTALLING,
    INSTALL_DONE
};

BYTE status=0;

LOGFONTW CurrentFont;
HFONT font;

void SetFont(HDC hdc,UINT font_size,LPCWSTR font_name)
{
    DeleteObject(font);
    CurrentFont.lfCharSet=DEFAULT_CHARSET;
    CurrentFont.lfItalic=false;
    CurrentFont.lfHeight=font_size;
    CurrentFont.lfWidth=font_size/2;
    CurrentFont.lfEscapement=0;
    CurrentFont.lfWeight=FW_NORMAL;
    CurrentFont.lfUnderline=false;
    CurrentFont.lfStrikeOut=false;
    CurrentFont.lfQuality=PROOF_QUALITY;
    lstrcpyW(CurrentFont.lfFaceName,font_name);
    CurrentFont.lfPitchAndFamily=FF_DONTCARE;
    CurrentFont.lfClipPrecision=CLIP_CHARACTER_PRECIS;
    CurrentFont.lfOutPrecision=OUT_CHARACTER_PRECIS;
    font=CreateFontIndirectW(&CurrentFont);
    SelectObject(hdc,font);
}
void DeleteFont(void)
{
    DeleteObject(font);
}
void FontOut(HDC hdc,UINT x,UINT y,UINT font_size,LPCWSTR font_name,LPCWSTR output_str)
{
    SetFont(hdc,font_size,font_name);
    TextOutW(hdc,x,y,output_str,wcslen(output_str));
    DeleteFont();
}

void CancelInstall(void)
{
    wstring install_p=install_path;
}

void DrawSolidColorBackground(HDC hdc,COLORREF color)
{
    RECT client_rect;
    GetClientRect(main_window,&client_rect);
    FillRect(hdc,&client_rect,CreateSolidBrush(color));
}

bool IsObjectiveShellInstallationDirectory(void)
{
    wstring install_path_string=install_path;
    wstring current_chkfile=install_path_string;
    return true;
}

DWORD WINAPI DrawColorfulBackgroundThread(LPVOID lParam)
{
    while(true)
    {
        RECT client_rect;
        GetClientRect(main_window,&client_rect);
        InvalidateRect(main_window,&client_rect,false);
        Sleep(60);
    }
    return 0;
}

DWORD WINAPI StatusCheckThread(LPVOID lParam)
{
    while(true)
        if(status>INSTALL_DONE)
        {
            MessageBoxW(NULL,L"Invalid status detected",L"Error",MB_OK|MB_ICONERROR);
            exit(1);
        }
    return 0;
}

void IsVisualEffectEnabled(void)
{
    FILE *fp;
    if((fp=fopen("./isvisualeffectenabled","r"))!=NULL)
        visual_effects=true;
    fclose(fp);
}

LRESULT CALLBACK MainWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case BUTTON_INSTALL:
                    status++;
                    refresh=true;
                    DestroyWindow(button_install);
                    DestroyWindow(button_upgrade);
                    DestroyWindow(button_exit);
                    DestroyWindow(button_about);
                    install_path_input=CreateWindowW(L"EDIT",L"C:\\Program Files\\Objective Shell\\",WS_CHILD|WS_VISIBLE,10,100,370,20,hwnd,INPUT_INSTALL_PATH,hinstance,NULL);
                    button_next=CreateWindowW(L"BUTTON",L"Next >",WS_CHILD|WS_VISIBLE,390,100,80,20,hwnd,BUTTON_NEXT,hinstance,NULL);
                    UpdateWindow(main_window);
                    break;
                case BUTTON_UPGRADE:
                    MessageBoxW(NULL,L"This is the first version!",L"Error",MB_OK|MB_ICONERROR);
                    break;
                case BUTTON_NEXT:
                    switch(status)
                    {
                        case SELECT_INSTALL_PATH:
                            GetWindowTextW(install_path_input,install_path,16384);

                            break;
                    }
                    break;
                case BUTTON_BACK:
                    switch(status)
                    {
                        case SELECT_INSTALL_PATH:
                            DestroyWindow(button_back);
                            DestroyWindow(button_next);
                            DestroyWindow(install_path_input);
                            button_install=CreateWindowW(L"BUTTON",L"Install",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,BUTTON_INSTALL,hinstance,NULL);
                            button_upgrade=CreateWindowW(L"BUTTON",L"Upgrade",WS_CHILD|WS_VISIBLE,10,80,150,25,main_window,BUTTON_UPGRADE,hinstance,NULL);
                            button_about=CreateWindowW(L"BUTTON",L"About",WS_CHILD|WS_VISIBLE,10,110,150,25,main_window,BUTTON_ABOUT,hinstance,NULL);
                            button_exit=CreateWindowW(L"BUTTON",L"Exit",WS_CHILD|WS_VISIBLE,10,140,150,25,main_window,BUTTON_EXIT,hinstance,NULL);
                            status=FIRST_STEP;
                            refresh=true;
                            UpdateWindow(hwnd);
                            break;
                    }
                    break;
                case BUTTON_ABOUT:
                    MessageBoxW(main_window,L"Objective Shell\nCopyright(C)2019 CodesBuilder\n\nVersion:1.0.0.0001\nCodename:(to be determined)\nFor testing purposes only",L"About Objective Shell",MB_OK|MB_ICONINFORMATION);
                    break;
                case BUTTON_EXIT:
                    SendMessageW(hwnd,WM_CLOSE,NULL,NULL);
                    break;
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
            SetBkMode(hdc,TRANSPARENT);
            if(visual_effects)
            {
                DrawSolidColorBackground(hdc,RGB(bg_r,bg_g,bg_b));
                if(bg_loop_cnt==3)
                    bg_reserve_gradient=false;
                if(bg_loop_cnt==255)
                    bg_reserve_gradient=true;
                if(!bg_reserve_gradient)
                {
                    if(bg_r!=50)
                        bg_r-=2;
                    if(bg_g!=50&&bg_loop_cnt%2==0)
                        bg_g-=5;
                    if(bg_b!=120&&bg_loop_cnt%3==0)
                        bg_b--;
                    bg_loop_cnt++;
                }
                else
                {
                    if(bg_r!=170)
                        bg_r+=2;
                    if(bg_g!=170&&bg_loop_cnt%2==0)
                        bg_g+=5;
                    if(bg_b!=220&&bg_loop_cnt%3==0)
                        bg_b++;
                    bg_loop_cnt--;
                }
                if(!bg_reserve_gradient)
                {
                    if(fg_loop_cnt%7==0&&text_r!=30)
                        text_r-=2;
                    if(fg_loop_cnt%3==0&&text_g!=20)
                        text_g-=5;
                    if(fg_loop_cnt%9==0&&text_b!=35)
                        text_b-=5;
                    fg_loop_cnt++;
                }
                else
                {
                    if(fg_loop_cnt%2==0&&text_r!=255)
                        text_r+=2;
                    if(fg_loop_cnt%3==0&&text_g!=255)
                        text_g+=5;
                    if(fg_loop_cnt%5==0&&text_b!=255)
                        text_b+=5;
                    fg_loop_cnt--;
                }
            }
            else
                DrawSolidColorBackground(hdc,RGB(10,127,255));
            if(visual_effects)
                SetTextColor(hdc,RGB(text_b,text_b,text_g));
            else
                SetTextColor(hdc,TEXT_COLOR);
            switch(status)
            {
                case FIRST_STEP:
                    FontOut(hdc,10,10,20,L"Courier New",L"Objective Shell Installer");
                    //SendMessage(button_install,WM_SETFONT,NULL,(LPARAM)hfont);
                    break;
                case SELECT_INSTALL_PATH:
                    FontOut(hdc,10,10,20,L"Courier New",L"Select Install Path");
                    SetTextColor(hdc,TEXT_COLOR);
                    FontOut(hdc,10,80,15,L"Courier New",L"Install Path:");
                    break;
            }
            if(refresh)
            {
                ReleaseDC(hwnd,hdc);
                refresh=false;
            }
            else
                EndPaint(hwnd,&ps);
            break;
        }
        case WM_CREATE:
            if(visual_effects)
            {
                SetWindowLongW(hwnd,GWL_EXSTYLE,WS_EX_LAYERED);
                SetLayeredWindowAttributes(hwnd,NULL,240,LWA_ALPHA);
            }
            break;
        case WM_CLOSE:
            if(installing)
                if(MessageBoxW(hwnd,L"Do you want to exit?",L"",MB_YESNO|MB_ICONQUESTION)==IDYES)
                {
                    CancelInstall();
                    DestroyWindow(hwnd);
                }
            if(visual_effects)
                for(int i=239;i>=0;i--)
                {
                    for(volatile register ULONG64 i=0;i<600000;i++)
                        i=i;
                    SetLayeredWindowAttributes(hwnd,NULL,i,LWA_ALPHA);
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
    mainclass.hIcon=LoadIconW(hInstance,IDI_LOGO);
    RegisterClassW(&mainclass);
    main_window=CreateWindowW(mainclass_name,L"Objective Shell Installer",WS_OVERLAPPEDWINDOW,5,25,500,400,NULL,NULL,hInstance,NULL);
    if(main_window==NULL)
    {
        MessageBoxW(NULL,L"Create window failed!",L"Error",MB_OK|MB_ICONERROR);
        return 1;
    }
    //visual_effects=true;
    ShowWindow(main_window,nShowCmd);
    //IsVisualEffectEnabled();
    button_install=CreateWindowW(L"BUTTON",L"Install",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,BUTTON_INSTALL,hInstance,NULL);
    button_upgrade=CreateWindowW(L"BUTTON",L"Upgrade",WS_CHILD|WS_VISIBLE,10,80,150,25,main_window,BUTTON_UPGRADE,hInstance,NULL);
    button_about=CreateWindowW(L"BUTTON",L"About",WS_CHILD|WS_VISIBLE,10,110,150,25,main_window,BUTTON_ABOUT,hInstance,NULL);
    button_exit=CreateWindowW(L"BUTTON",L"Exit",WS_CHILD|WS_VISIBLE,10,140,150,25,main_window,BUTTON_EXIT,hInstance,NULL);
    if(visual_effects)
        colorful_bg_thread=CreateThread(NULL,0,DrawColorfulBackgroundThread,NULL,NULL,NULL);
    status_check_thread=CreateThread(NULL,0,StatusCheckThread,NULL,NULL,NULL);
    MSG msg={};
    while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
    return 0;
}