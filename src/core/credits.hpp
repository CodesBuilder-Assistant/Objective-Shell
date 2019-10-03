#ifndef CREDITS_HPP
#define CREDITS_HPP

#ifdef _WIN32
#include <Windows.h>
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"winmm.lib")

HWND credits_window;
UINT frame=0;

DWORD BackgroundMusicThread(LPVOID param)
{
    while(1)
        PlaySoundW(L"res/credits.wav",NULL,SND_FILENAME|SND_NODEFAULT|SND_SYNC);
    return 0;
}

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
            switch(frame)
            {
                case 0:
                    FillRect(hdc,&client_rect,CreateSolidBrush(RGB(0,0,0)));

                    break;
                case 1:
                    FillRect(hdc,&client_rect,CreateSolidBrush(RGB(3,3,3)));
                    break;
            }
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