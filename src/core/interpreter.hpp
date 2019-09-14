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
using std::vector;
using std::wstring;
vector<wchar_t *> SeprateArguments(wchar_t *command)
{
    vector<wchar_t *> ret_vector;
    wstring current_part;
    for(unsigned int i=0;i<wcslen(command);i++)
        if(command[i]!=L' ')
            current_part+=command[i];
        else
            if(current_part!=L"")
            {
                ret_vector.push_back((wchar_t *)current_part.c_str());
                current_part.clear();
            }
    return ret_vector;
}
void *ExecuteCommands(vector<wchar_t *> args)
{

}
#endif