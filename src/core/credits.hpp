#ifndef CREDITS_HPP
#define CREDITS_HPP

#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__

#elif defined(_WIN32)

#include <Windows.h>

#pragma comment(lib,"winmm.lib")

WNDCLASSW CreditsWindowClass;

LRESULT CALLBACK CreditsWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    case WM_PAINT:
        break;
    return DefWindowProcW(hwnd,uMsg,wParam,lParam);
}

void ShowCreditsWindow(void)
{

    PlaySoundW(L"sound/credits.wav",NULL,SND_FILENAME|SND_LOOP)
}
#endif

void ShowCredits(void)
{
    while(1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        puts("Objective Shell");
        #ifdef __linux

        #elif defined(_WIN32)
        #endif
    }
}

#endif