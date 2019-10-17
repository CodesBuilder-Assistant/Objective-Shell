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
#include <effects.hpp>
#include <stdlib.h>
#include <fs.hpp>

/* Modules */
#include "clear.hpp"
#include "ls.hpp"
#include "alias.hpp"
#include "version.hpp"

#ifdef _WIN32
#pragma comment(lib,"shell32.lib")
#endif

using std::vector;
using std::wstring;

wchar_t current_dir[16384];
int return_value=0;
wstring *find_dirs;

unsigned int argument_count=0;
vector<wstring>arguments;

void PartitionArguments(const wchar_t *args)
{
    wstring current_arg;
    for(int i=0;i<wcslen(args);i++)
        if(args[i]==L' '||args[i+1]==L'\0')
        {
            if(current_arg==L"\0")
            {
                current_arg.clear();
                continue;
            }
            wstring push_string=current_arg;
            current_arg.clear();
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
    else if(arguments[0]==L"clear")
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
    else if(arguments[0]==L"ls")
    {
        if(arguments.size()==1)
            ls(current_dir);
        else
            ls(arguments[1].c_str());
    }
    else if(arguments[0]==L"echo")
    {
        for(int i=1;i<arguments.size();i++)
            wprintf(L"%ls",arguments[i].c_str());
        puts("");
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
        puts("\nCommand list:");
        puts("help - Show this list");
        puts("cd - Change current directory");
        puts("clear - Clear screen");
        puts("ls - List files");
        puts("exit - Exit\n");
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
    else
        puts("Unknown command");
}

#endif