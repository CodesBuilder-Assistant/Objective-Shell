#include <Windows.h>
#define SIZE_KB 1024
#define SIZE_MB SIZE_KB*1024
#define SIZE_GB SIZE_MB*1024
UWORD mainwindow_width,mainwindow_height;
bool installing=true;
wchar_t install_path[8192];

enum states
{
    FIRST_STEP=0
};

BYTE state=0;

void CancelInstall(void)
{

}

LRESULT CALLBACK MainWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_CREATE:
            mainwindow_width=LOWORD(lParam);
            mainwindow_height=HIWORD(lParam);
            break;
        case WM_PAINT:
            PAINTSTRUCT ps;
            HDC hdc;
            hdc=BeginPaint(hwnd,&ps);
            switch(state)
            {
                case FIRST_STEP:
                    FillRect(hdc,&ps.rcPaint,(HBRUSH)COLOR_WINDOW);
                    SetTextColor(hdc,RGB(49,118,175));
                    SetBkMode(hdc,TRANSPARENT);
                    TextOut(hdc,10,10,L"Objective Shell Installer",wcslen(L"Objective Shell Installer"));
                    TextOut(hdc,10,30,L"Selcet an option to continue:",wcslen(L"Select an option to continue:"));
                    SetTextColor(hdc,RGB(0,0,0));
                    break;
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
    LPCWSTR mainclass_name=L"Objective Shell Installer";
    WNDCLASS mainclass={};
    mainclass.lpszClassName=mainclass_name;
    mainclass.hInstance=hInstance;
    mainclass.lpfnWndProc=MainWindowProc;
    RegisterClass(&mainclass);
    HWND main_window=CreateWindowW(mainclass_name,L"Objective Shell Installer",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,500,400,NULL,NULL,hInstance,NULL);
    HWND install_option1 = CreateWindowW(L"BUTTON",L"Install Objective Shell",WS_CHILD|WS_VISIBLE,10,50,150,25,main_window,NULL,hInstance,NULL);
    if(main_window==NULL)
    {
        MessageBox(NULL,L"Create window failed!",L"Error",MB_OK|MB_ICONERROR);
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