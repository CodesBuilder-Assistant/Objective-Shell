#include "cpuid.h"
#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN32)
#include <Windows.h>
#endif
int main(int argc,wchar_t *argv[])
{
    if(argc>1)
    {
        for(register int i=0;i<argc;i++)
            if(argv[i]==L"cpuid")
            {
                cpuid();
            }
            else
            {
                #ifdef __linux
                printf("\033[0m[\033[31mError\033[0m]Invalid option '%s'",argv[i]);
                #elif defined(_WIN32)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("[");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                printf("Error");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("]Invalid option '%s'",argv[i]);
                #endif
                exit(1);
            }
    }
}