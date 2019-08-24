/*
* (C)2019 CodesBuilder
* This software publish under the GPL
*/
#include "runtime.hpp"
#include <locale>

#define _CRT_SECURE_NO_WARNINGS

wstring CurrentPath;
char CurrentLocale[4];
wchar_t *initial_path_buf=new wchar_t[1024];

#define UNLOCKED_FALG1_VALUE 53245
#define UNLOCKED_FALG2_VALUE 781915

int main(int argc,wchar_t *argv[])
{
    if(version_type==secret_test)
    {
        FILE *lock_flag_file_check;
        #ifdef __linux__
        if((lock_flag_file_check=fopen("/etc/oslock.bi_","r"))!=NULL)
        {
            fclose(lock_flag_file_check);
            puts("\033[0m[\033[31mError\033[0m]Objective Shell has been disabled");
            return 0;
        }
        #elif defined(_WIN32)
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
                #ifdef __linux__
                puts("\033[0m[\033[31mError\033[0m]Objective Shell has been locked.You can't use it later.");
                #elif defined(_WIN32)
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
                #ifdef __linux__
                puts("\033[0m[\033[31mError\033[0m]Password wrong.");
                #elif defined(_WIN32)
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
    #if defined(_WIN32)
    SetConsoleCP(CP_UTF8);
    #endif
    #if defined(_WIN32)
    SetConsoleTitleA("Objective Shell");
    #endif
    if(argc>1)
    {
        for(register int i=0;i<argc;i++)
            if(argv[i]==L"help")
            {
                #ifdef __linux__
                printf("\033[92m");
                #elif defined(_WIN32)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                #endif
                puts("Objective Shell");
                #ifdef __linux__
                printf("\033[93m");
                #elif defined(_WIN32)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
                #endif
                puts("(C)2019 CodesBuilder");
                #ifdef __linux__
                printf("\033[0m");
                #elif defined(_WIN32)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                #endif
                puts("Syntax:objshell [options] [script] [args]");
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
                puts("-key [key]    Check the key when Objective Shell startup(secret test only)");
            }
            else if(argv[i]==L"-v")
            {
                ShowVersionInfo();
                return 0;
            }
            else if(argv[i]==L"reseted_by_old_objshell_terminal")
            {
                #ifdef __linux__
                puts("\033[0m[\033[32mOK\033[0m]Reseted Objective Shell");
                puts("Good Luck!");
                #elif defined(_WIN32)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("[");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
                printf("OK");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                puts("]Reseted Objective Shell");
                puts("Good Luck!");
                #endif
            }
    }
    while(true)
    {
        wstring user_input;
        #ifdef __linux__
        printf("\033[92m");
        #elif defined(_WIN32)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        #endif
        wcout<<L"objshell|"<<CurrentPath<<">";
        #ifdef __linux__
        printf("\033[0m");
        #elif defined(_WIN32)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_RED);
        #endif
        ExecCommand(user_input);
    }
}