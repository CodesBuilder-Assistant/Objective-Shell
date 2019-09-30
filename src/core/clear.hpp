#ifndef CLEAR_HPP
#define CLEAR_HPP
#ifdef _WIN32
#include <Windows.h>
#endif
void ClearScreen(void)
{
    #ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO buffer_info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&buffer_info);
    COORD cur_ret_coord={0,0};
    DWORD buffer_size=buffer_info.dwSize.X*buffer_info.dwSize.Y;
    FillConsoleOutputCharacterW(GetStdHandle(STD_OUTPUT_HANDLE),L' ',buffer_size,{0,0},&buffer_size);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
    #endif
}
#endif