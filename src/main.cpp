/*
* Copyright(C)2019 CodesBuilder
* This software publish under the GPL.
*/

/*
* Objective Shell runtime module.
*/
#if defined(_WIN32)||defined(_WIN64)
#include "res.h"
#endif
#include "runtime.hpp"

wstring CurrentPath;

int main(int argc,char *argv[])
{
    #if defined(_WIN32)||defined(_WIN64)
    SetConsoleTitleA("Objective Shell");
    #endif
    if(argc>1)
    {
        for(int i=0;i<argc;i++)
            if(argv[i]=="HE110W0R1D")
            {
                #ifdef __linux
                puts("\033[33mH\033[34me\033[36mll\033[92mo\033[0m,\033[93mW\033[94mo\033[95mr\033[96ml\033[97md\033[0m");
                #elif defined(_WIN32)||defined(_WIN64)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);
                printf("H");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
                printf("e");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("ll");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                printf("o");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf(",");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                printf("W");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                printf("o");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                printf("r");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                printf("l");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                printf("d\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                #endif
                return 0;
            }
    }
    while(true)
    {
        wstring user_input;
        #ifdef __linux
        #elif defined(_WIN32)||defined(_WIN64)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        #endif
        wcout<<CurrentPath;
        wcin>>user_input;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
        ExecCommand(user_input);
    }
}