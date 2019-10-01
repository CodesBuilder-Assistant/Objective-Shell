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
#include "dir.hpp"

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

void ClearArguments(void)
{
    arguments.clear();
}

void ExecuteCommand(void)
{
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
    else if(arguments[0]==L"dir")
    {
        if(arguments.size()==1)
            dir(current_dir);
        else
            dir(arguments[1].c_str());
    }
    else if(arguments[0]==L"exit")
    {
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
                puts("]Too large return value.");
            }
            exit((int)return_value);
        }
    }
    else
        puts("Unknown command");
}

#endif