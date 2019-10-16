#ifndef FONT_HPP
#define FONT_HPP
#include <Windows.h>
LOGFONTW CurrentFontW;
LOGFONTA CurrentFontA;
HFONT font;

void SetFontW(HDC hdc,UINT font_size,bool bold,bool underline,bool italic,LPCWSTR font_name) noexcept
{
    DeleteObject(font);
    CurrentFontW.lfCharSet=DEFAULT_CHARSET;
    CurrentFontW.lfItalic=italic;
    CurrentFontW.lfHeight=font_size;
    CurrentFontW.lfWidth=font_size/2;
    CurrentFontW.lfEscapement=0;
    if(bold)
        CurrentFontW.lfWeight=FW_BOLD;
    else
        CurrentFontW.lfWeight=FW_NORMAL;
    CurrentFontW.lfUnderline=underline;
    CurrentFontW.lfStrikeOut=false;
    CurrentFontW.lfQuality=PROOF_QUALITY;
    lstrcpyW(CurrentFontW.lfFaceName,font_name);
    CurrentFontW.lfPitchAndFamily=FF_DONTCARE;
    CurrentFontW.lfClipPrecision=CLIP_CHARACTER_PRECIS;
    CurrentFontW.lfOutPrecision=OUT_CHARACTER_PRECIS;
    font=CreateFontIndirectW(&CurrentFontW);
    SelectObject(hdc,font);
}
void SetFontA(HDC hdc,UINT font_size,bool bold,bool underline,bool italic,LPCSTR font_name) noexcept
{
    DeleteObject(font);
    CurrentFontA.lfCharSet=DEFAULT_CHARSET;
    CurrentFontA.lfItalic=italic;
    CurrentFontA.lfHeight=font_size;
    CurrentFontA.lfWidth=font_size/2;
    CurrentFontA.lfEscapement=0;
    if(bold)
        CurrentFontW.lfWeight=FW_BOLD;
    else
        CurrentFontW.lfWeight=FW_NORMAL;
    CurrentFontA.lfUnderline=underline;
    CurrentFontA.lfStrikeOut=false;
    CurrentFontA.lfQuality=PROOF_QUALITY;
    lstrcpyA(CurrentFontA.lfFaceName,font_name);
    CurrentFontA.lfPitchAndFamily=FF_DONTCARE;
    CurrentFontA.lfClipPrecision=CLIP_CHARACTER_PRECIS;
    CurrentFontA.lfOutPrecision=OUT_CHARACTER_PRECIS;
    font=CreateFontIndirectA(&CurrentFontA);
    SelectObject(hdc,font);
}
void DeleteFont(void) noexcept
{
    DeleteObject(font);
}
void FontOutW(HDC hdc,UINT x,UINT y,UINT font_size,bool bold,bool underline,bool italic,LPCWSTR font_name,LPCWSTR output_str) noexcept
{
    SetFontW(hdc,font_size,bold,underline,italic,font_name);
    TextOutW(hdc,x,y,output_str,wcslen(output_str));
    DeleteFont();
}
void FontOutA(HDC hdc,UINT x,UINT y,UINT font_size,bool bold,bool underline,bool italic,LPCSTR font_name,LPCSTR output_str) noexcept
{
    SetFontA(hdc,font_size,bold,underline,italic,font_name);
    TextOutA(hdc,x,y,output_str,strlen(output_str));
    DeleteFont();
}
#endif