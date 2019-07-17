#ifndef ALERT_HPP
#define ALERT_HPP
#if defined(_WIN32)||defined(_WIN64)
#include <Windows.h>
#elif defined(__linux__)
#endif
#include <wchar.h>
enum alert_type
{
    ALERT_NOTE=11,
    ALERT_ERROR,
    ALERT_WARNING,
    ALERT_OK,
    ALERT_NORMAL=0
};

void alert(const wchar_t *alert_message,unsigned short alert_type)
{
    #ifdef __linux
    switch(alert_type)
    {
        case ALERT_NOTE:
            printf("\033[0m[\033[94mNote\033[0m]");
            break;
        case ALERT_ERROR:
            printf("\033[0m[\033[31mError\033[0m]");
            break;
        case ALERT_WARNING:
            printf("\033[0m[\033[33mWarning\033[0m]");
            break;
        case ALERT_OK:
            printf("\033[0m[\033[32m  OK  \033[0m]");
            break;
        case ALERT_NORMAL:
            printf("\033[0m[Message]")
    }
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    printf("[");
    switch(alert_type)
    {
        case ALERT_NOTE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
            printf("Note");
            break;
        case ALERT_ERROR:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
            printf("Error");
            break;
        case ALERT_WARNING:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);
            printf("Warning");
            break;
        case ALERT_OK:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
            printf("  OK  ");
            break;
        case ALERT_NORMAL:
            printf("[Message");
    }
    #endif
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    printf("]");
    wprintf(L"%ls",alert_message);
    puts("");
}
void xalert(const wchar_t *alert_message,const wchar_t *alert_title)
{
    #if defined(_WIN32)||defined(_WIN64)
    MessageBoxW(NULL,alert_message,alert_title,MB_OK|MB_ICONINFORMATION);
    #elif defined(__linux__)
    #endif
}
#endif