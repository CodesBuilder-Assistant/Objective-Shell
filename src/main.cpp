/*
* Copyright(C)2019 CodesBuilder
* This software publish under the GPL
*/
#include "runtime.hpp"
#include <locale>

wstring CurrentPath;
char CurrentLocale[4];
wchar_t *initial_path_buf=new wchar_t[1024];

#define UNLOCKED_FALG2_VALUE 53245
#define UNLOCKED_FALG2_VALUE 781915

int main(int argc,char *argv[])
{
    memset(initial_path_buf,'\0',sizeof(wchar_t)*1024);
    GetCurrentDirectoryW(1024,initial_path_buf);
    CurrentPath=initial_path_buf;
    delete[] initial_path_buf;
    setlocale(LC_ALL,CurrentLocale);
    #if defined(_WIN32)||defined(_WIN64)
    SetConsoleCP(CP_UTF8);
    #endif
    #if defined(_WIN32)||defined(_WIN64)
    SetConsoleTitleA("Objective Shell");
    #endif
    if(argc>1)
    {
        for(register int i=0;i<argc;i++)
            if(argv[i]=="help")
            {
                puts("Objective Shell");
                puts("Syntax:objsh [options] [script] [args]");
                puts("Options:");
                puts("-v            Show version info");
                puts("-h/--help     Show this list");
                puts("-c            Compile a script");
                puts("  -t [type]   Set output file type");
                puts("  -o [level]  Set optimization level");
                puts("-pe [command] Pre-execute a command");
                puts("-s            Show setting interface");
                puts("-var [name]   Pre-define a variable");
                puts("-array [name] Pre-define an array.");
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
        wcin.getline(user_input);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
        ExecCommand(user_input);
    }
}