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

#ifdef _WIN32
#pragma comment(lib,"shell32.lib")
#endif

using std::vector;
using std::wstring;

wchar_t current_dir[16384];
int return_value=0;
vector<wchar_t *>find_dirs;

char cd(vector<wchar_t *>arguments)
{
    if(arguments.size()>1)
    {
        SetConsoleTextColor(WHITE);
        printf("[");
        SetConsoleTextColor(RED);
        printf("Error");
        SetConsoleTextColor(WHITE);
        puts("]Too many arguments");
        return 2;
    }
    else if(arguments.size()==0)
        puts("Syntax:cd [directory]");
    if(!IsDirectory(arguments[0]))
    {
        SetConsoleTextColor(WHITE);
        printf("[");
        SetConsoleTextColor(RED);
        printf("Error");
        SetConsoleTextColor(WHITE);
        puts("]No such directory");
        return 1;
    }
    wcscpy(current_dir,arguments[0]);
    return 0;
}

vector<wchar_t *> GetArguments(const wchar_t *command)
{
    vector<wchar_t *> ret_vector;
    wstring current_part;
    for(unsigned int i=0;i<wcslen(command);i++)
        if(command[i]!=L' '&&command[i]!=L'\0'&&command[i]!=L'\n')
            current_part+=command[i];
        else
            if(current_part!=L"")
            {
                ret_vector.push_back((wchar_t *)current_part.c_str());
                current_part.clear();
            }
    return ret_vector;
}

void *ExecuteCommand(const vector<wchar_t *> args)
{
    if(args.size()==0)
        return 0;
    unsigned int need_end_count;
    wchar_t *subject;
    subject=args[0];
    wprintf(subject);
    vector<wchar_t *>arguments;
    for(int i=1;i<args.size();i++)
        arguments.push_back(args[i]);
    if(subject==L"cd")
        cd(arguments);
    else
    {
        wstring args_str;
        for(int i=0;i<arguments.size();i++)
        {
            args_str+=arguments[i];
            args_str+=L' ';
        }
        #ifdef _WIN32
        PROCESS_INFORMATION process_info={};
        CreateProcessW(arguments[0],(LPWSTR)args_str.c_str(),NULL,NULL,false,NULL,NULL,NULL,NULL,&process_info);
        #endif
    }
    return 0;
}
#endif