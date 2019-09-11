#ifndef STACK_HPP
#define STACK_HPP
#include <stack>
#include <stdio.h>
#include <string>
using std::stack;
extern wstring CurrentPath;
stack<long long>value_stack;
stack<unsigned long long>exvalue_stack;
stack<char *>str_stack;
stack<wchar_t *>wstr_stack;
stack<wstring>path_stack;
void pop_path(void)
{
    if(path_stack.size()==0)
    {
        puts("Error:Unable to restore path from stack.");
        return;
    }
    CurrentPath=path_stack.top();
    path_stack.pop();
}
void push_path(wchar_t *push_dir)
{
    wstring push_class=push_dir;
    path_stack.push(push_class);
}
void push_path(wstring push_dir)
{
    path_stack.push(push_dir);
}
#endif