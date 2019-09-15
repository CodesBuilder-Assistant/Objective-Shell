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
using std::vector;
using std::wstring;

wchar_t current_dir[16384];
wchar_t operators[]={L"=+-!$%^&*(),./'\":[]{}~<>|?"};

vector<wchar_t *> SeprateArguments(const wchar_t *command)
{
    vector<wchar_t *> ret_vector;
    wstring current_part;
    for(unsigned int i=0;i<wcslen(command);i++)
        if(command[i]!=L' '&&command[i]!=L'\0')
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
    if(!args.size())
        return 0;
    unsigned int need_end_count;
    wchar_t *subject;
    subject=args[0];
    for(int i=1;i<args.size();i++)
    {
        if(args[0]==L"cd")
            if(args.size()>i+1)
            {
                SetConsoleTextColor(WHITE);
                printf("[");
                SetConsoleTextColor(RED);
                printf("Error");
                SetConsoleTextColor(WHITE);
                printf("]Too many arguments");
            }
            else
            {
                if(IsDirectory(args[i]))
                    wcscpy(current_dir,args[i]);
                else
                {
                    SetConsoleTextColor(WHITE);
                    printf("[");
                    SetConsoleTextColor(RED);
                    printf("Error");
                    SetConsoleTextColor(WHITE);
                    printf("]Directory not found.");
                }
            }
    }
    return 0;
}
#endif