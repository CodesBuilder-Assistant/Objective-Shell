#include "lang.hpp"
#include "res.h"
#include <string>
#include <Vfw.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <dwmapi.h>
#include <windows/font.hpp>
#include <windows/latest_control.h>

using std::wstring;

#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"msimg32.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"dwmapi.lib")

/* These variables used for visual effects */
UINT bg_r=100;
UINT bg_g=100;
UINT bg_b=100;
UINT text_r=255;
UINT text_g=255;
UINT text_b=255;
UINT bg_loop_cnt=0;
UINT fg_loop_cnt=0;
bool bg_reserve_gradient=false;
bool fg_reserve_gradient=false;
bool extend_frame_to_client_area=false;

/* Windows and controls. */
HWND main_window;
HWND button_install;
HWND button_upgrade;
HWND install_path_input;
HWND button_next;
HWND button_back;
HWND button_exit;
HWND button_about;
HWND feedback_window;

/* License contents */

/*
* status_check_thread:Exit setup when status is a error value.
*/
HANDLE colorful_bg_thread;
HANDLE status_check_thread;
HANDLE background_music_thread;

#define TEXT_COLOR RGB(255,255,255)

/* Controls' return values */
#define BUTTON_INSTALL 201
#define BUTTON_UPGRADE 202
#define INPUT_INSTALL_PATH 203
#define BUTTON_NEXT 204
#define BUTTON_BACK 205
#define BUTTON_EXIT 206
#define BUTTON_ABOUT 207

bool visual_effects=false;
bool installing=false;
bool refresh=false;
/*
* sizeof(wchar_t)*16384=2 Byte*16384=32768=32KB
*/
wchar_t install_path[16384];
/* Instance. */
HINSTANCE hinstance;

/* Installer status */

enum statuses
{
    FIRST_STEP=0,
    READ_LICENSE,
    SELECT_INSTALL_PATH,
    SELECT_MODULES_TO_INSTALL,
    INSTALLING,
    INSTALL_DONE
};

BYTE status=0;

/* Cancel install */

void CancelInstall(void)
{
    wstring install_p=install_path;
}

bool IsNeedExtendFrameIntoClientArea(void)
{
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    OSVERSIONINFOW os_verinfo;
    GetVersionExW(&os_verinfo);
    if(os_verinfo.dwMajorVersion==6)
    {
        BOOL IsAeroEnabled;
        DwmIsCompositionEnabled(&IsAeroEnabled);
        if(IsAeroEnabled==FALSE)
            return false;
        else
            return true;
    }
    else
        return false;
}

/* Draw background */

void DrawDefaultBackground(HDC hdc)
{
	RECT client_rect;
	GetClientRect(main_window,&client_rect);
	BYTE current_r=210;
	BYTE current_g=210;
	BYTE current_b=255;
	for(int y=client_rect.bottom,loop_cnt=0;y>=client_rect.top;y--,loop_cnt++)
	{
		RECT draw_rect=client_rect;
		draw_rect.bottom=y;
		draw_rect.top=y-1;
		FillRect(hdc,&draw_rect,CreateSolidBrush(RGB(current_r,current_g,current_b)));
		if(loop_cnt%5==0&&current_r!=50&&current_g!=40)
			current_r-=2,current_g-=2;
		if(loop_cnt%11==0&&current_b!=128)
			current_b--;
	}
}

void DrawSolidColorBackground(HDC hdc,COLORREF color) noexcept
{
    RECT client_rect;
    GetClientRect(main_window,&client_rect);
    FillRect(hdc,&client_rect,CreateSolidBrush(color));
}

void DrawGradientBackground(HDC hdc,COLORREF start_color,COLORREF end_color) noexcept
{
    TRIVERTEX vertex[2];
    GRADIENT_RECT gradient_rect;
    gradient_rect.UpperLeft=0;
    gradient_rect.LowerRight=1;
    RECT client_rect;
    GetClientRect(main_window,&client_rect);
    vertex[0].x=0;
    vertex[0].y=0;
    vertex[0].Red=GetRValue(start_color);
    vertex[0].Green=GetGValue(start_color);
    vertex[0].Blue=GetBValue(start_color);
    vertex[0].Alpha=255;
    vertex[1].x=client_rect.right;
    vertex[1].y=client_rect.bottom;
    vertex[1].Red=GetRValue(end_color);
    vertex[1].Green=GetGValue(end_color);
    vertex[1].Blue=GetBValue(end_color);
    vertex[1].Alpha=255;
    GradientFill(hdc,vertex,2,NULL,0,GRADIENT_FILL_RECT_V);
}

COLORREF GetEndColor(COLORREF start_color) noexcept
{
    bool direction_r=false;
    bool direction_g=false;
    bool direction_b=false;
    BYTE current_r=GetRValue(start_color);
    BYTE current_g=GetGValue(start_color);
    BYTE current_b=GetBValue(start_color);
    RECT client_rect;
    GetClientRect(main_window,&client_rect);
    if(current_r<255/2)
        direction_r=true;
    if(current_g<255/2)
        direction_g=true;
    if(current_b<255/2)
        direction_b=true;
    for(UINT y=0;y<client_rect.bottom;y++)
    {
        if(direction_r)
            if(current_r!=255)
                current_r++;
        else
            if(current_r!=0)
                current_r--;
        if(direction_g)
            if(current_g!=255)
                current_g++;
        else
            if(current_g!=0)
                current_g--;
        if(direction_b)
            if(current_b!=255)
                current_b++;
        else
            if(current_b!=0)
                current_b--;
    }
    return RGB(current_r,current_g,current_b);
}

DWORD WINAPI DrawColourfulBackgroundThread(LPVOID param) noexcept
{
    while(true)
    {
        RECT client_rect;
        GetClientRect(main_window,&client_rect);
        InvalidateRect(main_window,&client_rect,true);
        Sleep(30);
    }
    return 0;
}

DWORD WINAPI StatusCheckThread(LPVOID param)
{
    while(true)
        if(status>INSTALL_DONE)
        {
            MessageBoxW(NULL,L"Invalid status detected",L"Error",MB_OK|MB_ICONERROR);
            exit(1);
        }
    return 0;
}

/* I don't know why this function make installer crash. */
void IsVisualEffectEnabled(void) noexcept
{
    FILE *fp;
    if((fp=fopen("./isvisualeffectenabled","r"))!=NULL)
        visual_effects=true;
    fclose(fp);
}

DWORD WINAPI BackgroundMusicThread(LPVOID param) noexcept
{
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
                    status=READ_LICENSE;
                    refresh=true;
                    DestroyWindow(button_install);
                    DestroyWindow(button_upgrade);
                    DestroyWindow(button_exit);
                    DestroyWindow(button_about);
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
                        case READ_LICENSE:
                            install_path_input=CreateWindowW(L"EDIT",L"C:\\Program Files\\Objective Shell\\",WS_CHILD|WS_VISIBLE,10,100,370,20,hwnd,(HMENU)INPUT_INSTALL_PATH,hinstance,NULL);
                            button_next=CreateWindowW(L"BUTTON",L"Next >",WS_CHILD|WS_VISIBLE,390,100,80,20,hwnd,(HMENU)BUTTON_NEXT,hinstance,NULL);
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
                            button_install=CreateWindowW(L"BUTTON",L"Install",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,(HMENU)BUTTON_INSTALL,hinstance,NULL);
                            button_upgrade=CreateWindowW(L"BUTTON",L"Upgrade",WS_CHILD|WS_VISIBLE,10,80,150,25,main_window,(HMENU)BUTTON_UPGRADE,hinstance,NULL);
                            button_about=CreateWindowW(L"BUTTON",L"About",WS_CHILD|WS_VISIBLE,10,110,150,25,main_window,(HMENU)BUTTON_ABOUT,hinstance,NULL);
                            button_exit=CreateWindowW(L"BUTTON",L"Exit",WS_CHILD|WS_VISIBLE,10,140,150,25,main_window,(HMENU)BUTTON_EXIT,hinstance,NULL);
                            status=READ_LICENSE;
                            refresh=true;
                            UpdateWindow(hwnd);
                            break;
                        case READ_LICENSE:
                            break;
                    }
                    break;
                case BUTTON_ABOUT:
                    MessageBoxW(main_window,L"Objective Shell\nCopyright(C)2019 CodesBuilder\n\nVersion:1.0.0.0001\nCodename:Quartz\nFor testing purposes only",L"About Objective Shell",MB_OK|MB_ICONINFORMATION);
                    break;
                case BUTTON_EXIT:
                    SendMessageW(hwnd,WM_CLOSE,NULL,NULL);
                    break;
            }
            break;
        case WM_DESTROY:
            CloseHandle(colorful_bg_thread);
            CloseHandle(status_check_thread);
            CloseHandle(background_music_thread);
            PostQuitMessage(0);
            break;
        case WM_ERASEBKGND:
            if(extend_frame_to_client_area)
            {
                HDC hdc;
                PAINTSTRUCT ps;
                if(refresh)
                    hdc=GetDC(main_window);
                else
                    hdc=BeginPaint(main_window,&ps);
                RECT client_rect;
                GetClientRect(main_window,&client_rect);
                FillRect(hdc,&client_rect,RGB(0,0,0));
                break;
            }
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc;
            if(refresh)
                hdc=GetDC(hwnd);
            else
                hdc=BeginPaint(hwnd,&ps);
            SetFontW(hdc,15,false,false,false,L"Segoe UI");
            SendMessageW(button_install,WM_FONTCHANGE,(WPARAM)font,MAKELONG(true,0));
            DeleteFont();
            SetBkMode(hdc,TRANSPARENT);
            if(extend_frame_to_client_area)
            {
                MARGINS mg={-1};
                RECT client_rect;
                GetClientRect(main_window,&client_rect);
                FillRect(hdc,&client_rect,RGB(0,0,0));
                mg.cyBottomHeight=50;
                DwmExtendFrameIntoClientArea(main_window,&mg);
            }
            else if(visual_effects)
            {
                FILE *fp=fopen(".log","a+");
                fprintf(fp,"R:%d G:%d B:%d\n",bg_r,bg_g,bg_b);
                fclose(fp);
                DrawGradientBackground(hdc,RGB(bg_r,bg_g,bg_b),GetEndColor(RGB(bg_r,bg_g,bg_b)));
                //DrawSolidColorBackground(hdc,RGB(bg_r,bg_g,bg_b));
                if(bg_loop_cnt==3)
                    bg_reserve_gradient=false;
                if(bg_loop_cnt==255)
                    bg_reserve_gradient=true;
                if(!bg_reserve_gradient)
                {
                    if(bg_r>0&&bg_loop_cnt%3==0)
                        bg_r-=2;
                    if(bg_g>0&&bg_loop_cnt%5==0)
                        bg_g-=2;
                    if(bg_b>30&&bg_loop_cnt%7==0)
                        bg_b-=2;
                    bg_loop_cnt++;
                }
                else
                {
                    if(bg_r<170)
                        bg_r+=2;
                    if(bg_g<170&&bg_loop_cnt%2==0)
                        bg_g+=2;
                    if(bg_b<220&&bg_loop_cnt%3==0)
                        bg_b+=2;
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
                DrawDefaultBackground(hdc);
            if(visual_effects)
                SetTextColor(hdc,RGB(text_b,text_b,text_g));
            else
                SetTextColor(hdc,TEXT_COLOR);
            switch(status)
            {
                case FIRST_STEP:
                    FontOutW(hdc,10,10,20,true,false,false,L"Segoe UI",L"Objective Shell Installer");
                    //SendMessage(button_install,WM_SETFONT,NULL,(LPARAM)hfont);
                    break;
                case READ_LICENSE:
                    FontOutW(hdc,10,10,20,true,false,false,L"Segoe UI",L"Read License");
                    FontOutW(hdc,10,35,18,false,false,false,L"Segoe UI",L"Please read the license:");
                    break;
                case SELECT_INSTALL_PATH:
                    FontOutW(hdc,10,10,20,true,false,false,L"Segoe UI",L"Select Install Path");
                    FontOutW(hdc,10,80,20,false,false,false,L"Segoe UI",L"Install Path:");
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
            if(visual_effects&&!extend_frame_to_client_area)
            {
                SetWindowLongW(hwnd,GWL_EXSTYLE,WS_EX_LAYERED);
                SetLayeredWindowAttributes(hwnd,NULL,0,LWA_ALPHA);
            }
            else if(extend_frame_to_client_area)
            {
                DWM_BLURBEHIND bh={0};
                bh.dwFlags=DWM_BB_ENABLE|DWM_BB_TRANSITIONONMAXIMIZED;
                bh.fEnable=true;
                bh.fTransitionOnMaximized=true;
                bh.dwFlags|=DWM_BB_BLURREGION;
            }
            break;
        case WM_CLOSE:
        {
            /* Ask user whether to exit setup or continue when
               installer is installing Objective Shell but user wants to close window. */
            if(installing)
                if(MessageBoxW(hwnd,L"Do you want to exit?",L"",MB_YESNO|MB_ICONQUESTION)==IDYES)
                {
                    CancelInstall();
                    DestroyWindow(hwnd);
                }
            if(visual_effects)
            {
                for(int i=239;i>=0;i--)
                {
                    SetLayeredWindowAttributes(hwnd,NULL,i,LWA_ALPHA);
                    Sleep(1);
                }
            }
            break;
        }
    }
    return DefWindowProcW(hwnd,uMsg,wParam,lParam);
}

/* Main function. */
int WINAPI wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int nShowCmd)
{
    extend_frame_to_client_area=IsNeedExtendFrameIntoClientArea();
    //visual_effects=true;
    hinstance=hInstance;
    /* Register window class. */
    LPCWSTR mainclass_name=L"Objective Shell Installer";
    WNDCLASSW mainclass={};
    mainclass.lpszClassName=mainclass_name;
    mainclass.hInstance=hInstance;
    mainclass.lpfnWndProc=MainWindowProc;
    mainclass.hCursor=LoadCursorW(NULL,(LPCWSTR)IDC_ARROW);
    mainclass.hIcon=LoadIconW(hInstance,IDI_LOGO);
    RegisterClassW(&mainclass);
    /* Create and show main window. */
    main_window=CreateWindowW(mainclass_name,L"Objective Shell Installer",WS_OVERLAPPEDWINDOW,5,25,500,400,NULL,NULL,hInstance,NULL);
    if(main_window==NULL)
    {
        MessageBoxW(NULL,L"Create window failed!",L"Error",MB_OK|MB_ICONERROR);
        return 1;
    }
    ShowWindow(main_window,nShowCmd);
    //IsVisualEffectEnabled();
    /* Create buttons */
    button_install=CreateWindowW(L"BUTTON",L"Install",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,(HMENU)BUTTON_INSTALL,hInstance,NULL);
    button_upgrade=CreateWindowW(L"BUTTON",L"Upgrade",WS_CHILD|WS_VISIBLE,10,80,150,25,main_window,(HMENU)BUTTON_UPGRADE,hInstance,NULL);
    button_about=CreateWindowW(L"BUTTON",L"About",WS_CHILD|WS_VISIBLE,10,110,150,25,main_window,(HMENU)BUTTON_ABOUT,hInstance,NULL);
    button_exit=CreateWindowW(L"BUTTON",L"Exit",WS_CHILD|WS_VISIBLE,10,140,150,25,main_window,(HMENU)BUTTON_EXIT,hInstance,NULL);
    /* Create threads to ensure that visual effects can work. */
    if(visual_effects)
        colorful_bg_thread=CreateThread(NULL,0,DrawColourfulBackgroundThread,NULL,NULL,NULL);
    status_check_thread=CreateThread(NULL,0,StatusCheckThread,NULL,NULL,NULL);
    background_music_thread=CreateThread(NULL,0,BackgroundMusicThread,NULL,NULL,NULL);
    if(visual_effects)
        for(int i=0;i<=236;i++)
        {
            SetLayeredWindowAttributes(main_window,NULL,i,LWA_ALPHA);
            Sleep(1);
        }
    /* Message loop. */
    MSG msg={};
    while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
    return 0;
}
