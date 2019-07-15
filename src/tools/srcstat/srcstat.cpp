#include <stdio.h>
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#include <Windows.h>
#elif defined(__linux__)
#include <boost/filesystem.hpp>
#endif
#include <filelist.hpp>
#include "languages.h"
using namespace std;

int main(int argc,char *argv[])
{
    #ifdef __linux__
    printf("\033[94m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    #endif
    puts("Objective Shell Sources Statistical Tool");
    #ifdef __linux__
    printf("\033[33m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);
    #endif
    puts("(C)2019 CodesBuilder");
    #ifdef __linux__
    printf("\033[0m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    #endif
    puts("Statisticing...");
    file_list finddata(L"*.c");
    finddata.attach(L"*.h");
    
    printf("C:");
}