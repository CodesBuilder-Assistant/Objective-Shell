#include <Windows.h>
#include <string>
#include <stdio.h>

#define DEBUG

HWND main_window;
HWND instopt_install;
HWND instopt_upgrade;
FILE *install_log;

#define BUTTON_INSTALL (HMENU)201
#define BUTTON_UPGRADE (HMENU)202

#pragma comment(lib,"User32.lib")
#pragma comment(lib,"Gdi32.lib")

#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

using namespace std;

bool installing=false;
wchar_t install_path[8192];

enum states
{
    FIRST_STEP=0,
    SELECT_INSTALL_PATH,
    SELECT_MODULES_TO_INSTALL,
    INSTALLING,
    INSTALL_DONE
};

BYTE state=0;

void CancelInstall(void)
{
    wstring install_p=install_path;
    #ifdef DEBUG
    fputs("[EVENT]Canceled install\n",install_log);
    #endif
}

LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case (UINT)BUTTON_INSTALL:
                    state=SELECT_INSTALL_PATH;
                    UpdateWindow(main_window);
                    DestroyWindow(instopt_install);
                    DestroyWindow(instopt_upgrade);
                    #ifdef DEBUG
                    fputs("[EVENT]Clicked button 'instopt_install'\n",install_log);
                    #endif
                    break;
                case (UINT)BUTTON_UPGRADE:
                    MessageBoxW(NULL,L"This is the first version",L"Error",MB_OK|MB_ICONERROR);
                    #ifdef DEBUG
                    fputs("[EVENT]Clicked button 'instopt_upgrade'\n",install_log);
                    #endif
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_CREATE:
            break;
        case WM_PAINT:
            PAINTSTRUCT ps;
            HDC hdc;
            hdc=BeginPaint(hwnd,&ps);
            switch(state)
            {
                case FIRST_STEP:
                    SetTextColor(hdc,RGB(20,50,182));
                    #ifdef DEBUG
                    fputs("[OK]Set text color\n",install_log);
                    #endif
                    SetBkMode(hdc,TRANSPARENT);
                    #ifdef DEBUG
                    fputs("[OK]Set text background to transparent\n",install_log);
                    #endif
                    TextOutW(hdc,10,10,L"Objective Shell Installer",wcslen(L"Objective Shell Installer"));
                    TextOutW(hdc,0,344,L"Copyright(C)2019 CodesBuilder",wcslen(L"Copyright(C)2019 CodesBuilder"));
                    SetTextColor(hdc,RGB(255,255,255));
                    #ifdef DEBUG
                    fputs("[OK]Refreshed client,state:FIRST_STEP\n",install_log);
                    #endif
                    break;
                case SELECT_INSTALL_PATH:
                    SetTextColor(hdc,RGB(20,50,182));
                    #ifdef DEBUG
                    fputs("[OK]Set text color\n",install_log);
                    #endif
                    SetBkMode(hdc,TRANSPARENT);
                    #ifdef DEBUG
                    fputs("[OK]Set text background to transparent\n",install_log);
                    #endif
                    TextOutW(hdc,10,10,L"Install Path:",wcslen(L"Install Path:"));
                    SetTextColor(hdc,RGB(255,255,255));
                    #ifdef DEBUG
                    fputs("[OK]Refreshed client,state:SELECT_INSTALL_PATH\n",install_log);
                    #endif
                    break;
            }
            EndPaint(hwnd,&ps);
            break;
        case WM_CLOSE:
            #ifdef DEBUG
            fputs("[EVENT]Clicked close button\n",install_log);
            #endif
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
    #ifdef DEBUG
    install_log=fopen("install.log","w");
    fputs("[OK]Started Objective Shell Installer\n",install_log);
    #endif
    LPCWSTR mainclass_name=L"Objective Shell Installer";
    WNDCLASSW mainclass={};
    mainclass.lpszClassName=mainclass_name;
    mainclass.hInstance=hInstance;
    mainclass.lpfnWndProc=MainWindowProc;
    mainclass.hbrBackground=CreateSolidBrush(RGB(23,32,64));
    RegisterClassW(&mainclass);
    #ifdef DEBUG
    fputs("[OK]Registed window class\n",install_log);
    #endif
    main_window=CreateWindowW(mainclass_name,L"Objective Shell Installer",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,500,400,NULL,NULL,hInstance,NULL);
    #ifdef DEBUG
    fputs("[OK]Created main window\n",install_log);
    #endif
    instopt_install=CreateWindowW(L"BUTTON",L"Install",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,BUTTON_INSTALL,hInstance,NULL);
    #ifdef DEBUG
    fputs("[OK]Created button 'instopt_install'\n",install_log);
    #endif
    instopt_upgrade=CreateWindowW(L"BUTTON",L"Upgrade",WS_CHILD|WS_VISIBLE,10,80,150,25,main_window,BUTTON_UPGRADE,hInstance,NULL);
    #ifdef DEBUG
    fputs("[OK]Created button 'instopt_upgrade'\n",install_log);
    #endif
    if(main_window==NULL)
    {
        MessageBoxW(NULL,L"Create window failed!",L"Error",MB_OK|MB_ICONERROR);
        return 1;
    }
    ShowWindow(main_window,nShowCmd);
    #ifdef DEBUG
    fputs("[OK]Called ShowWindow\n",install_log);
    #endif
    MSG msg={};
    while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
    #ifdef DEBUG
    fputs("[EXIT]Exited installer\n",install_log);
    fclose(install_log);
    #endif
    return 0;
}