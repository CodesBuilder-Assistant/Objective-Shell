#include <Windows.h>
#include <string>
#include <thread>
#include <latest_com.h>
using namespace std;

#pragma comment(lib,"User32.lib")
#pragma comment(lib,"Gdi32.lib")

HWND main_window;
HWND button_install;
HWND button_upgrade;
HWND instpath_input;
HWND button_next;
HWND button_settings;
HWND button_setting_use_gradient_background;
HWND button_back;
HWND button_exit;

UINT main_window_sz_x;
UINT main_window_sz_y;

bool transparent_effect=true;
bool gradient_background=true;

#define TEXT_COLOR RGB(65,130,170)

#define BUTTON_INSTALL (HMENU)201
#define BUTTON_UPGRADE (HMENU)202
#define INPUT_INSTALL_PATH (HMENU)203
#define BUTTON_NEXT (HMENU)204
#define BUTTON_SETTING (HMENU)205
#define BUTTON_BACK (HMENU)206
#define BUTTON_EXIT (HMENU)207

bool installing=false;
bool refresh=false;
wchar_t install_path[8192];
HINSTANCE hinstance;

enum states
{
    FIRST_STEP=0,
    SELECT_INSTALL_PATH,
    SELECT_MODULES_TO_INSTALL,
    INSTALLING,
    INSTALL_DONE,
    SETTINGS_INTERFACE
};

BYTE state=0;

void CancelInstall(void)
{
    wstring install_p=install_path;
}

void CreateFrameWork(void)
{

}

void DrawGradientBackground(HDC hdc)
{
    BYTE BG_R=180;
    BYTE BG_G=180;
    BYTE BG_B=240;
    UINT loop_cnt=0;
    for(int y=0;y<400;y++,loop_cnt++)
    {
        for(int x=0;x<500;x++)
            SetPixel(hdc,x,y,RGB(BG_R,BG_G,BG_B));
        if(BG_R!=0)
            BG_R-=2;
        if(loop_cnt%2==0&&BG_G!=0)
            BG_G--;
        if(loop_cnt%5==0&&BG_B!=30)
            BG_B--;
    }
}

void DrawSolidColorBackground(HDC hdc,COLORREF color)
{
    for(int y=0;y<400;y++)
        for(int x=0;x<500;x++)
            SetPixel(hdc,x,y,color);
}


LRESULT CALLBACK MainWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case BUTTON_INSTALL:
                    state++;
                    refresh=true;
                    DestroyWindow(button_install);
                    DestroyWindow(button_upgrade);
                    DestroyWindow(button_settings);
                    DestroyWindow(button_exit);
                    instpath_input=CreateWindowW(L"EDIT",L"C:\\Program Files\\Objective Shell\\",WS_CHILD|WS_VISIBLE,10,100,400,20,hwnd,INPUT_INSTALL_PATH,hinstance,NULL);
                    button_next=CreateWindowW(L"BUTTON",L"Next",WS_CHILD|WS_VISIBLE,375,300,40,20,hwnd,BUTTON_NEXT,hinstance,NULL);
                    UpdateWindow(main_window);
                    break;
                case BUTTON_UPGRADE:
                    MessageBoxW(NULL,L"This is the first version!",L"Error",MB_OK|MB_ICONERROR);
                    break;
                case BUTTON_NEXT:
                    switch(state)
                    {
                        case SELECT_INSTALL_PATH:
                            GetWindowTextW(instpath_input,install_path,8192);
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
                case BUTTON_SETTING:
                    refresh=true;
                    state=SETTINGS_INTERFACE;
                    DestroyWindow(button_install);
                    DestroyWindow(button_upgrade);
                    DestroyWindow(button_settings);
                    DestroyWindow(button_exit);
                    button_back=CreateWindowW(L"BUTTON",L"< Back",WS_CHILD|WS_VISIBLE,1,375,20,110,hwnd,BUTTON_BACK,hinstance,NULL);
                    UpdateWindow(main_window);
                    break;
                case BUTTON_BACK:
                    switch(state)
                    {
                        case SETTINGS_INTERFACE:
                            DestroyWindow(button_back);
                            button_install=CreateWindowW(L"BUTTON",L"Install",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,BUTTON_INSTALL,hinstance,NULL);
                            button_upgrade=CreateWindowW(L"BUTTON",L"Upgrade",WS_CHILD|WS_VISIBLE,10,80,150,25,main_window,BUTTON_UPGRADE,hinstance,NULL);
                            button_settings=CreateWindowW(L"BUTTON",L"Settings",WS_CHILD|WS_VISIBLE,10,110,150,25,main_window,BUTTON_SETTING,hinstance,NULL);
                            button_exit=CreateWindowW(L"BUTTON",L"Exit",WS_CHILD|WS_VISIBLE,10,140,150,25,main_window,BUTTON_EXIT,hinstance,NULL);
                            state=FIRST_STEP;
                            refresh=true;
                            UpdateWindow(hwnd);
                            break;
                    }
                    break;
                case BUTTON_EXIT:
                    PostQuitMessage(0);
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_CREATE:
            break;
        case WM_PAINT:
        {
            if(transparent_effect)
            {
                SetWindowLong(main_window,GWL_EXSTYLE,WS_EX_LAYERED|WS_EX_TOOLWINDOW);
                SetLayeredWindowAttributes(main_window,NULL,235,LWA_ALPHA);
            }
            PAINTSTRUCT ps;
            HDC hdc;
            if(refresh)
            {
                hdc=GetDC(hwnd);
                refresh=false;
            }
            else
                hdc=BeginPaint(hwnd,&ps);
            if(gradient_background)
                DrawGradientBackground(hdc);
            else
                DrawSolidColorBackground(hdc,RGB(160,210,250));
            SetBkMode(hdc,TRANSPARENT);
            SetTextColor(hdc,TEXT_COLOR);
            switch(state)
            {
                case FIRST_STEP:
                    TextOutW(hdc,10,10,L"Objective Shell Installer",wcslen(L"Objective Shell Installer"));
                    TextOutW(hdc,0,385,L"objshell 1.0.0001",wcslen(L"objshell 1.0.0001"));
                    break;
                case SELECT_INSTALL_PATH:
                    SetTextColor(hdc,TEXT_COLOR);
                    TextOutW(hdc,10,80,L"Install Path:",wcslen(L"Install Path:"));
                    break;
                case SETTINGS_INTERFACE:
                    TextOutW(hdc,22,20,L"Settings",wcslen(L"Settings"));
                    TextOutW(hdc,22,50,L"Gradient Background",wcslen(L"Gradient Background"));
                    TextOutW(hdc,22,70,L"Transparent Effect",wcslen(L"Transparent Effect"));
                    break;
                default:
                    MessageBoxW(hwnd,L"Invalid state detected",L"Error",MB_OK|MB_ICONWARNING);
                    PostQuitMessage(1);
            }
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
    main_window=CreateWindowW(mainclass_name,L"Objective Shell Installer",WS_CLIPCHILDREN,CW_USEDEFAULT,CW_USEDEFAULT,500,400,NULL,NULL,hInstance,NULL);
    if(main_window==NULL)
    {
        MessageBoxW(NULL,L"Create window failed!",L"Error",MB_OK|MB_ICONERROR);
        return 1;
    }
    ShowWindow(main_window,nShowCmd);
    button_install=CreateWindowW(L"BUTTON",L"Install",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,BUTTON_INSTALL,hInstance,NULL);
    button_upgrade=CreateWindowW(L"BUTTON",L"Upgrade",WS_CHILD|WS_VISIBLE,10,80,150,25,main_window,BUTTON_UPGRADE,hInstance,NULL);
    button_settings=CreateWindowW(L"BUTTON",L"Settings",WS_CHILD|WS_VISIBLE,10,110,150,25,main_window,BUTTON_SETTING,hInstance,NULL);
    button_exit=CreateWindowW(L"BUTTON",L"Exit",WS_CHILD|WS_VISIBLE,10,140,150,25,main_window,BUTTON_EXIT,hInstance,NULL);
    MSG msg={};
    while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
    return 0;
}