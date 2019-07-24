#include <Windows.h>
#include <string>

#pragma comment(lib,"User32.lib")
#pragma comment(lib,"Gdi32.lib")

#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

HWND main_window;
HWND button_install;
HWND button_upgrade;
HWND instpath_input;
HWND button_next;

#define BACKGROUND_COLOR RGB(23,32,64)
#define TEXT_COLOR RGB(20,50,182)

#define BUTTON_INSTALL (HMENU)201
#define BUTTON_UPGRADE (HMENU)202
#define INPUT_INSTALL_PATH (HMENU)203
#define BUTTON_NEXT (HMENU)204

using namespace std;

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
    INSTALL_DONE
};

BYTE state=0;

void CancelInstall(void)
{
    wstring install_p=install_path;
}

LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
                    UpdateWindow(main_window);
                    instpath_input=CreateWindowW(L"EDIT",L"C:\\Program Files\\Objective Shell\\",WS_CHILD|WS_VISIBLE,10,100,400,20,hwnd,INPUT_INSTALL_PATH,hinstance,NULL);
                    button_next=CreateWindowW(L"BUTTON",L"Next",WS_CHILD|WS_VISIBLE,375,300,40,20,hwnd,BUTTON_NEXT,hinstance,NULL);
                    break;
                case BUTTON_UPGRADE:
                    MessageBoxW(NULL,L"This is the first version!",L"Error",MB_OK|MB_ICONERROR);
                    break;
                case BUTTON_NEXT:
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
            if(refresh)
            {
                hdc=GetDC(hwnd);
                switch(state)
                {
                    case SELECT_INSTALL_PATH:
                        for(int y=0;y<30;y++)
                            for(int x=0;x<180;x++)
                                SetPixel(hdc,x,y,BACKGROUND_COLOR);
                        break;
                }
            }
            else
                hdc=BeginPaint(hwnd,&ps);
            switch(state)
            {
                case FIRST_STEP:
                    SetTextColor(hdc,TEXT_COLOR);
                    SetBkMode(hdc,TRANSPARENT);
                    TextOutW(hdc,10,10,L"Objective Shell Installer",wcslen(L"Objective Shell Installer"));
                    TextOutW(hdc,0,344,L"objshell 1.0.1",wcslen(L"objshell 1.0.1"));
                    break;
                case SELECT_INSTALL_PATH:
                    SetTextColor(hdc,TEXT_COLOR);
                    SetBkMode(hdc,TRANSPARENT);
                    TextOutW(hdc,10,80,L"Install Path:",wcslen(L"Install Path:"));
                    break;
                default:
                    MessageBoxW(hwnd,L"Invalid state detected",L"Error",MB_OK|MB_ICONWARNING);
                    PostQuitMessage(1);
            }
            EndPaint(hwnd,&ps);
            break;
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
    mainclass.hbrBackground=CreateSolidBrush(BACKGROUND_COLOR);
    RegisterClassW(&mainclass);
    main_window=CreateWindowW(mainclass_name,L"Objective Shell Installer",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,500,400,NULL,NULL,hInstance,NULL);
    button_install=CreateWindowW(L"BUTTON",L"Install",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,BUTTON_INSTALL,hInstance,NULL);
    button_upgrade=CreateWindowW(L"BUTTON",L"Upgrade",WS_CHILD|WS_VISIBLE,10,80,150,25,main_window,BUTTON_UPGRADE,hInstance,NULL);
    if(main_window==NULL)
    {
        MessageBoxW(NULL,L"Create window failed!",L"Error",MB_OK|MB_ICONERROR);
        return 1;
    }
    ShowWindow(main_window,nShowCmd);
    MSG msg={};
    while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
    return 0;
}