/*
* interpreter.hpp
* The most important module.
*/
#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP
#include <deque>
#include <string>
#include <wchar.h>
#include <stdio.h>
#include <effects.hpp>
#include <stdlib.h>
#include <fs.hpp>

#ifdef _WIN32
#pragma comment(lib,"shell32.lib")
#endif

using std::deque;
using std::wstring;

wchar_t current_dir[16384];
int return_value=0;
wstring *find_dirs;

unsigned int argument_count=0;
deque<wstring>arguments;

void PartitionArguments(const wchar_t *args)
{
    wstring current_arg;
    for(int i=0;i<wcslen(args);i++)
        if(args[i]==L' '||args[i+1]==L'\0')
        {
            if(current_arg.c_str()==L"")
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
    for(int i=0;i<arguments.size();i++)
        wprintf(L"%ls\n",arguments[i].c_str());
    return;
    if(arguments.size()==0)
        return;
    if(arguments[0].c_str()==L"cd")
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
        wcscpy(current_dir,arguments[1].c_str());
    }
    else
        puts("Unknown command");
}

#endif