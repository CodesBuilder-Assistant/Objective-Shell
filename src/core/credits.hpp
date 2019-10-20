#ifndef CREDITS_HPP
#define CREDITS_HPP

#ifdef _WIN32
#include <Windows.h>
#include <windows/font.hpp>
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"winmm.lib")

HWND credits_window;
UINT frame=0;
HANDLE update_window_thread;
WNDCLASSW credits_window_class;

DWORD UpdateWindowThread(LPVOID param) noexcept
{
    while(1)
    {
        RECT client_rect;
        GetClientRect(credits_window,&client_rect);
        InvalidateRect(credits_window,&client_rect,false);
    }
    return 0;
}

DWORD BackgroundMusicThread(LPVOID param) noexcept
{
    while(1)
        PlaySoundW(L"res/credits.wav",NULL,SND_FILENAME|SND_NODEFAULT|SND_SYNC);
    return 0;
}

LRESULT CALLBACK CreditsWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam) noexcept
{
    switch(uMsg)
    {
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc=BeginPaint(hwnd,&ps);
            RECT client_rect;
            GetClientRect(hwnd,&client_rect);
            FillRect(hdc,&client_rect,CreateSolidBrush(RGB(15,130,220)));
            switch(frame)
            {
                case 0:

                    FontOutW(hdc,)
                    break;
                case 1:

                    break;
            }
            frame++;
            EndPaint(hwnd,&ps);
            break;
        }
        case WM_CLOSE:
            PostQuitMessage(0);
            break;
    }
    return DefWindowProc(hwnd,uMsg,wParam,lParam);
}

void InitizationCreditsWindow(void)
{
    credits_window_class={};
    credits_window_class.lpszClassName=L"Objective Shell Credits";
    credits_window_class.hCursor=LoadCursorW(NULL,(LPCWSTR)IDC_ARROW);
}
#endif

#endif