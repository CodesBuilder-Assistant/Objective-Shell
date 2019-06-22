#ifndef GOTOFUNC_HPP
#define GOTOFUNC_HPP
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#elif defined(__linux)
#include <unistd.h>
#endif
void ShowRandomContent(void)
{
    srand(2147483647);
    unsigned short random_id=rand();
    if(random_id%2==1)
    {
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        #elif defined(__linux)
        printf("\033[2J\033[0m");
        #endif
        printf("C:>");
        #if defined(_WIN32)||defined(_WIN64)
        Sleep(2250);
        #elif defined(__linux)
        sleep(3);
        #endif
        printf("ob");
        #ifdef __linux
        sleep(1);
        #elif defined(_WIN32)||defined(_WIN64)
        Sleep(60);
        #endif
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        #elif defined(__linux)
        printf("\033[2J");
        #endif
        printf("C:>ob");
        #ifdef __linux
        sleep(1);
        #elif defined(_WIN32)||defined(_WIN64)
        Sleep(60);
        #endif
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        #elif defined(__linux)
        printf("\033[2J");
        #endif
        printf("C:>objs");
        #ifdef __linux
        sleep(1);
        #elif defined(_WIN32)||defined(_WIN64)
        Sleep(60);
        #endif
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        #elif defined(__linux)
        printf("\033[2J");
        #endif
        printf("C:>objshe");
        #ifdef __linux
        sleep(1);
        #elif defined(_WIN32)||defined(_WIN64)
        Sleep(60);
        #endif
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        #elif defined(__linux)
        printf("\033[2J");
        #endif
        printf("C:>objshell");
        #ifdef __linux
        sleep(1);
        #elif defined(_WIN32)||defined(_WIN64)
        Sleep(60);
        #endif
        puts("");
        #if defined(_WIN32)||defined(_WIN64)
        system("cls");
        #elif defined(__linux)
        printf("\033[2J");
        #endif
        return;
    }
}
void ASCIITable(void)
{
    for(char i=0;i<127;i++)
    {
        puts(" Character  Value");
        printf("  %c          %d\n",i,(int)i);
    }
}
#endif