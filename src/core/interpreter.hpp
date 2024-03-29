/*
* interpreter.hpp
* The most important module.
*/
#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP
#include <vector>
#include <string>
#include <wchar.h>
#include <stdio.h>
#include <time.h>
#include <effects.hpp>
#include <stdlib.h>
#include <fs.hpp>

/* Modules */
#include "clear.hpp"
#include "ls.hpp"
#include "alias.hpp"
#include "shutdown.hpp"
#include "version.hpp"
#include "hardware.hpp"
#include "hostname.hpp"

#ifdef _WIN32
#pragma comment(lib,"shell32.lib")
#endif

using std::vector;
using std::wstring;

wchar_t current_dir[16384];
int return_value=0;
wstring *find_dirs;

unsigned int argument_count=0;
vector<wstring> arguments;

void PartitionArguments(const wchar_t *args)
{
    wstring current_arg;
    for(int i=0;i<wcslen(args);i++)
        if(args[i]==L' '||args[i+1]==L'\0')
        {
            if(current_arg==L"\0")
            {
                current_arg=L"";;
                continue;
            }
            wstring push_string=current_arg;
            current_arg=L"";;
            arguments.push_back(push_string);
        }
        else
            current_arg+=args[i];
}

bool IsOperator(wchar_t *cmpstr) noexcept
{
    for(int i=0;i<wcslen(cmpstr);i++)
        switch(cmpstr[i])
        {
            case L'+':
                continue;
            case L'-':
                continue;
            case L'*':
                continue;
            case L'/':
                continue;
            case L'!':
                continue;
            case L'=':
                continue;
            case L'&':
                continue;
            case L'^':
                continue;
            case L'%':
                continue;
            case L'$':
                continue;
            case L'@':
                continue;
            case L'~':
                continue;
            case L'<':
                continue;
            case L'>':
                continue;
            case L':':
                continue;
            case L'?':
                continue;
            case L'|':
                continue;
            default:
                return false;
        }
}

void ClearArguments(void)
{
    for(int i=0;i<arguments.size();i++)
        arguments[i]=L"";
    vector<wstring>empty_vector;
    arguments.swap(empty_vector);
}

extern void ExecuteCommand(void);

char ExecuteScript(const wchar_t *filename)
{
    FILE *script_fp;
    #ifdef _WIN32
    if((script_fp=_wfopen(filename,L"r"))==NULL)
    #endif
    {
        fclose(script_fp);
        SetConsoleTextColor(WHITE);
        printf("[");
        SetConsoleTextColor(RED);
        printf("Error");
        SetConsoleTextColor(WHITE);
        wprintf(L"Unable to execute script '%ls'\n",filename);
        return 0;
    }
    unsigned int current_line=1;
    wstring current_line_command;
    wchar_t current_character;
    while(!feof(script_fp))
    {
        current_character=fgetwc(script_fp);
        if(current_character==L'\n')
        {
            PartitionArguments(current_line_command.c_str());
            current_line_command=L"";;
            current_line++;
            ExecuteCommand();
        }
        current_line_command+=current_character;
    }
    return 1;
}

void ExecuteCommand(void)
{
    ReplaceAliases();
    if(arguments.size()<1)
        return;
    if(arguments[0]==L"cd")
    {
        if(arguments.size()==1)
            return;
        else if(arguments.size()>2)
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]Too many arguments");
            return;
        }
        if(!IsDirectory(arguments[1].c_str()))
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]No such directory");
            return;
        }
        #ifdef _WIN32
        SetCurrentDirectoryW(arguments[1].c_str());
        GetCurrentDirectoryW(16384,current_dir);
        #endif
    }
    else if(arguments[0]==L"clear"||arguments[0]==L"cls")
    {
        if(arguments.size()>1)
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]Too many arguments");
            return;
        }
        ClearScreen();
    }
    else if(arguments[0]==L"ls"||arguments[0]==L"dir")
    {
        if(arguments.size()==1)
            ls(current_dir);
        else
            ls(arguments[1].c_str());
    }
    else if(arguments[0]==L"echo"||arguments[0]==L"print")
    {
        for(int i=1;i<arguments.size();i++)
            wprintf(L"%ls",arguments[i].c_str());
        puts("");
    }
    else if(arguments[0]==L"sysinfo")
    {
        if(arguments.size()==1)
        {
            wprintf(L"Local Host Name:%ls\n",GetLocalHostName());
            printf("CPU core count:%d\n",GetCpuCoreCount());
        }
    }
    else if(arguments[0]==L"stack")
    {

    }
    else if(arguments[0]==L"call")
    {

    }
    else if(arguments[0]==L"color")
    {
        if(arguments.size()>2)
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]Too many arguments");
            return;
        }
        else if(arguments.size()==1)
            return;
        if(arguments[1]==L"red")
            SetConsoleTextColor(RED);
        else if(arguments[1]==L"green")
            SetConsoleTextColor(GREEN);
        else if(arguments[1]==L"blue")
            SetConsoleTextColor(BLUE);
        else if(arguments[1]==L"white")
            SetConsoleTextColor(WHITE);
        else if(arguments[1]==L"lightred")
            SetConsoleTextColor(LIGHTRED);
        else if(arguments[1]==L"lightgreen")
            SetConsoleTextColor(LIGHTGREEN);
        else if(arguments[1]==L"lightblue")
            SetConsoleTextColor(LIGHTBLUE);
        else if(arguments[1]==L"yellow")
            SetConsoleTextColor(YELLOW);
        else if(arguments[1]==L"purple")
            SetConsoleTextColor(PURPLE);
        else if(arguments[1]==L"lightyellow")
            SetConsoleTextColor(LIGHTYELLOW);
        else if(arguments[1]==L"lightpurple")
            SetConsoleTextColor(LIGHTPURPLE);
        else
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]Invalid color");
            return;
        }
    }
    else if(arguments[0]==L"var")
    {

    }
    else if(arguments[0]==L"rm"||arguments[0]==L"del")
    {
        for(int i=1;i<arguments.size();i++)
        {
            #ifdef _WIN32
            if(_wremove(arguments[i].c_str())!=0)
            {
                SetConsoleTextColor(WHITE);
                printf("[");
                SetConsoleTextColor(RED);
                printf("Error");
                SetConsoleTextColor(WHITE);
                wprintf(L"]Unable to delete file:%ls\n",arguments[i].c_str());
                continue;
            }
            #endif
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(GREEN);
            printf("  OK  ");
            SetConsoleTextColor(WHITE);
            wprintf(L"]Deleted file:%ls\n",arguments[0].c_str());
            return;
        }
    }
    else if(arguments[0]==L"FFFFFFFFFFfuck")
        while(true)
        {
            srand(time(NULL));
            if(rand()%17==0)
                SetConsoleTextColor(WHITE);
            else if(rand()%3==0)
                SetConsoleTextColor(RED);
            else if(rand()%5==0)
                SetConsoleTextColor(GREEN);
            else if(rand()%7==0)
                SetConsoleTextColor(BLUE);
            else if(rand()%11==0)
                SetConsoleTextColor(PURPLE);
            else if(rand()%13==0)
                SetConsoleTextColor(YELLOW);
            else if(rand()%157==0)
                SetConsoleTextColor(LIGHTPURPLE);
            else if(rand()%137==0)
                SetConsoleTextColor(LIGHTYELLOW);
            else
                SetConsoleTextColor(LIGHTBLUE);
            printf("F");
        }
    else if(arguments[0]==L"mkfile")
    {
        for(int i=1;i<arguments.size();i++)
        {
            #ifdef _WIN32
            FILE *create_file_fp;
            if((create_file_fp=_wfopen(arguments[i].c_str(),L"w"))==NULL)
            {
                fclose(create_file_fp);
                SetConsoleTextColor(WHITE);
                printf("[");
                SetConsoleTextColor(RED);
                printf("Error");
                SetConsoleTextColor(WHITE);
                wprintf(L"]Unable to create file:%ls\n",arguments[i].c_str());
                continue;
            }
            fclose(create_file_fp);
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(GREEN);
            printf("  OK  ");
            SetConsoleTextColor(WHITE);
            wprintf(L"]Created file:%ls\n",arguments[0].c_str());
            #endif
        }
    }
    else if(arguments[0]==L"exit")
    {
        SetConsoleTextColor(WHITE);
        if(arguments.size()==1)
            exit(0);
        else if(arguments.size()>2)
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]Only need one return value");
            return;
        }
        else
        {
            long long return_value;
            for(int i=0;i<arguments[1].length();i++)
                if(!(i>=0&&i<=9))
                {
                    SetConsoleTextColor(WHITE);
                    printf("[");
                    SetConsoleTextColor(RED);
                    printf("Error");
                    SetConsoleTextColor(WHITE);
                    puts("]Invalid return value");
                    return;
                }
            for(int i=0,j=arguments[1].length();i<arguments[1].length();i++,j--)
            {
                long long multiple;
                for(int k=0;k<j;k++)
                    multiple*=10;
                return_value+=arguments[1].c_str()[i]-'0'*multiple;
            }
            if(return_value>INT32_MAX)
            {
                SetConsoleTextColor(WHITE);
                printf("[");
                SetConsoleTextColor(RED);
                printf("Error");
                SetConsoleTextColor(WHITE);
                puts("]Return value is too large.");
            }
            exit((int)return_value);
        }
    }
    else if(arguments[0]==L"exec")
    {
        for(int i=1;i<arguments.size();i++)
            ExecuteScript(arguments[i].c_str());
    }
    else if(arguments[0]==L"alias")
    {
        if(arguments.size()!=4)
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]Too few or too many arguments");
            return;
        }
        if(arguments[2]!=L"=")
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]Invalid operator");
            wprintf(L"%ls %ls ",arguments[0].c_str(),arguments[1].c_str());
            return;
        }
        AddAlias(arguments[3].c_str(),arguments[1].c_str());
    }
    else if(arguments[0]==L"help")
    {
        if(arguments.size()>1)
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]Too many arguments");
            return;
        }
        puts("\nUsable Commands:");
        puts(" help         Show this list");
        puts(" ver          Show version informations");
        puts(" color        Change console text color");
        puts(" shutdown     Shutdown your computer");
        puts(" reboot       Restart your computer");
        puts(" mkfile       Create a new file");
        puts(" rm/del       Delete a file");
        puts(" clear/cls    Clear console");
        puts(" echo/print   Output a string");
        puts(" ls/dir       List all files in a directory");
        puts(" cd           Change current directory");
        puts(" exec         Execute a script");
        puts(" alias        Define a alias");
    }
    else if(arguments[0]==L"ver")
    {
        if(arguments.size()>1)
            if(arguments.size()!=2)
            {
                SetConsoleTextColor(WHITE);
                printf("[");
                SetConsoleTextColor(RED);
                printf("Error");
                SetConsoleTextColor(WHITE);
                puts("]Too many arguments");
                return;
            }
            else if(arguments[1]!=L"CrEDItS")
            {
                SetConsoleTextColor(WHITE);
                printf("[");
                SetConsoleTextColor(RED);
                printf("Error");
                SetConsoleTextColor(WHITE);
                puts("]Too many arguments");
                return;
            }
            else
            {
                puts("Coming soon!");
                return;
            }
        ShowVersionInformation();
    }
    else if(arguments[0]==L"shutdown")
    {
        if(arguments.size()>1)
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]Too many arguments");
            return;
        }
        shutdown();
    }
    else if(arguments[0]==L"reboot")
    {
        if(arguments.size()>1)
        {
            SetConsoleTextColor(WHITE);
            printf("[");
            SetConsoleTextColor(RED);
            printf("Error");
            SetConsoleTextColor(WHITE);
            puts("]Too many arguments");
            return;
        }
        reboot();
    }
    else
        puts("Unknown command");
}

#endif
