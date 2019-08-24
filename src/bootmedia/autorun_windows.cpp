#include <Windows.h>

HWND main_window;

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

}
int WINAPI wWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int nShowCmd)
{
    WNDCLASSW wndclass={};
    wndclass.hInstance=hInstance;
    wndclass.hCursor=LoadCursorW(hInstance,IDC_ARROW);

}