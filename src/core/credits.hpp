#ifndef CREDITS_HPP
#define CREDITS_HPP

#ifdef _WIN32
#include <Windows.h>
#pragma comment(lib,"user32.lib")

HWND credits_window;
UINT frame=0;

LRESULT CALLBACK CreditsWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc=BeginPaint(hwnd,&ps);
            RECT client_rect;
            GetClientRect(hwnd,&client_rect);
            FillRect(hdc,&client_rect,CreateSolidBrush(RGB(240,240,240)));
            EndPaint(hwnd,&ps);
            break;
        }
        case WM_CLOSE:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd,uMsg,wParam,lParam);
}
#endif

#endif