#ifndef CREDITS_HPP
#define CREDITS_HPP

#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__

#elif defined(_WIN32)

#include <Windows.h>

#pragma comment(lib,"winmm.lib")

WNDCLASSW CreditsWindowClass;


LOGFONTW CurrentFont;
HFONT font;

void SetFont(HDC hdc,UINT font_size,LPCWSTR font_name)
{
    DeleteObject(font);
    CurrentFont.lfCharSet=DEFAULT_CHARSET;
    CurrentFont.lfItalic=false;
    CurrentFont.lfHeight=font_size;
    CurrentFont.lfWidth=font_size/2;
    CurrentFont.lfEscapement=0;
    CurrentFont.lfWeight=FW_NORMAL;
    CurrentFont.lfUnderline=false;
    CurrentFont.lfStrikeOut=false;
    CurrentFont.lfQuality=PROOF_QUALITY;
    lstrcpyW(CurrentFont.lfFaceName,font_name);
    CurrentFont.lfPitchAndFamily=FF_DONTCARE;
    CurrentFont.lfClipPrecision=CLIP_CHARACTER_PRECIS;
    CurrentFont.lfOutPrecision=OUT_CHARACTER_PRECIS;
    font=CreateFontIndirectW(&CurrentFont);
    SelectObject(hdc,font);
}
void DeleteFont(void)
{
    DeleteObject(font);
}
void FontOut(HDC hdc,UINT x,UINT y,UINT font_size,LPCWSTR font_name,LPCWSTR output_str)
{
    SetFont(hdc,font_size,font_name);
    TextOutW(hdc,x,y,output_str,wcslen(output_str));
    DeleteFont();
}

int RefreshWindowThreadProc(LPVOID lpParam)
{
    while(true)
    {

    }
    return 0;
}

LRESULT CALLBACK CreditsWindowProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    case WM_PAINT:
        HDC hdc;
        PAINTSTRUCT ps;
        hdc=BeginPaint(hwnd,&ps);

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