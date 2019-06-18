#ifndef GOTOFUNC_HPP
#define GOTOFUNC_HPP
#include "var.hpp"
#include "stack.hpp"
#include <stdio.h>
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#include <conio.h>
#elif defined(__linux)
#endif
void ShowExitWindow(void)
{
    #ifdef __linux

    #elif defined(_WIN32)||defined(_WIN64)
    while(true)
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf("%-24s"," Do you want to exit? ");
        bool selected_else=false;
        if(!selected_else)
        {
            printf(" ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
            printf("%-22s","Yes");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            puts(" ");
            printf("%-24s\n"," No");
        }
        else
        {

            printf("%-24s"," Yes");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf(" ");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
            printf("%-22s\n","No");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            puts(" ");
        }
        int gotkey=getch();
        if(gotkey==72||gotkey==80)
            gotkey?gotkey=0:gotkey=1;
        else if(gotkey==VK_RETURN)
            if(!selected_else)
                exit(0);
            else
                return;
    }
    #endif
}
#endif