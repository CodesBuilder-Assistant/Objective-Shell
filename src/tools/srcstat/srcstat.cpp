#include <stdio.h>
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#include <Windows.h>
#elif defined(__linux__)
#include <sys/io.h>
#include <sys/stat.h>
#endif
#include "languages.h"
using namespace std;

unsigned int current_lang_srcsize=0;
unsigned int current_lang_srclines=0;

wstring current_file_name;

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
    puts("Copyright(C)2019 CodesBuilder");
    #ifdef __linux__
    printf("\033[0m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    #endif
    puts("Statisticing...");
    #if defined(_WIN32)||defined(_WIN64)
    HANDLE finddata_handle;
    WIN32_FIND_DATAW wfinddata;
    for(int i=0;i<7;i++)
    {
        if((finddata_handle=FindFirstFileW(cpp[i],&wfinddata))==INVALID_HANDLE_VALUE)
            continue;
        current_file_name=wfinddata.cFileName;
        HANDLE current_file_handle;
        if((current_file_handle=CreateFileW(current_file_name.c_str(),GENERIC_READ,NULL,NULL,OPEN_EXISTING,NULL,NULL))==INVALID_HANDLE_VALUE)
        {
            CloseHandle(current_file_handle);
            continue;
        }
    }
    #elif defined(__linux__)
    #endif
    #ifdef __linux__
    printf("\033[94m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    #endif
    printf("C++:");
}