#ifndef EFFECTS_HPP
#define EFFECTS_HPP

#ifdef _WIN32
#include <Windows.h>
#elif defined(__linux__)
#include <stdio.h>
#endif

enum colors
{
    RED=10,
    GREEN,
    BLUE,
    LIGHTRED,
    LIGHTGREEN,
    LIGHTBLUE,
    WHITE,
    HIGHLIGHT,
    YELLOW,
    PURPLE,
    LIGHTYELLOW,
    LIGHTPURPLE,
    CYAN
};

void SetConsoleTextColor(char color_id)
{
    switch(color_id)
    {
        case RED:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
            #elif defined(__linux__)
            printf("\033[31m");
            #endif
            break;
        case GREEN:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
            #elif defined(__linux__)
            printf("\033[32m");
            #endif
            break;
        case BLUE:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
            #elif defined(__linux__)
            printf("\033[34m");
            #endif
            break;
        case LIGHTRED:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
            #elif defined(__linux__)
            printf("\033[91m");
            #endif
            break;
        case LIGHTGREEN:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            #elif defined(__linux__)
            printf("\033[92m");
            #endif
            break;
        case LIGHTBLUE:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            #elif defined(__linux__)
            printf("\033[94m");
            #endif
            break;
        case WHITE:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            #elif defined(__linux__)
            printf("\033[37m");
            #endif
            break;
        case HIGHLIGHT:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            #elif defined(__linux__)
            printf("\033[97m");
            #endif
            break;
        case YELLOW:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);
            #elif defined(__linux__)
            printf("\033[33m");
            #endif
            break;
        case PURPLE:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE);
            #elif defined(__linux__)
            printf("\033[35m");
            #endif
            break;
        case LIGHTYELLOW:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
            #elif defined(__linux__)
            printf("\033[93m");
            #endif
            break;
        case LIGHTPURPLE:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            #elif defined(__linux__)
            printf("\033[95m");
            #endif
            break;
        case CYAN:
            #ifdef _WIN32
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            #elif defined(__linux__)
            printf("\033[96m");
            #endif
            break;
    }
}

#endif