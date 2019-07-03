/*
* Copyright(C)2019 CodesBuilder
* This software publish under the GPL
*/
#include "runtime.hpp"
#include <locale>

wstring CurrentPath;
char CurrentLocale[4];
wchar_t *initial_path_buf=new wchar_t[1024];

#define UNLOCKED_FALG1_VALUE 53245
#define UNLOCKED_FALG2_VALUE 781915

int main(int argc,char *argv[])
{
    if(version_type==secret_test)
    {
        FILE *lock_flag_file_check;
        #ifdef __linux
        if((lock_flag_file_check=fopen("/etc/oslock.bi_","r"))!=NULL)
        {
            fclose(lock_flag_file_check);
            puts("\033[0m[\033[31mError\033[0m]Objective Shell has been disabled");
            return 0;
        }
        #elif defined(_WIN32)||defined(_WIN64)
        if((lock_flag_file_check=fopen("oslck.bi_","r"))!=NULL)
        {
            fclose(lock_flag_file_check);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("[");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
            printf("Error");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            puts("]Objective Shell has been disabled");
            return 0;
        }
        #endif
        fclose(lock_flag_file_check);
        char test_passwd[128];
        bool first=true;
        printf("Please enter the test password to start Objective Shell:");
        unsigned short errcount=0;
        do
        {
            if(errcount==3)
            {
                #ifdef __linux
                puts("\033[0m[\033[31mError\033[0m]Objective Shell has been locked.You can't use it later.");
                #elif defined(_WIN32)||defined(_WIN64)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("[");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                printf("Error");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("]Objective Shell has been disabled,You can't use it later");
                #endif
                return 0;
            }
            if(!first)
            {
                #ifdef __linux
                puts("\033[0m[\033[31mError\033[0m]Password wrong.");
                #elif defined(_WIN32)||defined(_WIN64)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("[");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                printf("Error");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("]Password wrong.");
                #endif
            }
            fgets(test_passwd,128,stdin);
            first=false;
        }while(!CheckTestPassword(test_passwd));
    }
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
                puts("-array [name] Pre-define an array");
                puts("-macro [name] Pre-define a macro");
            }
            else if(argv[i]=="-v")
            {
                ShowVersionInfo();
                return 0;
            }
    }
    while(true)
    {
        wstring user_input;
        #ifdef __linux
        printf("\033[92m");
        #elif defined(_WIN32)||defined(_WIN64)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        #endif
        wcout<<CurrentPath;
        #ifdef __linux
        printf("\033[0m");
        #elif defined(_WIN32)||defined(_WIN64)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
        #endif
        ExecCommand(user_input);
    }
}