#ifndef STACK_HPP
#define STACK_HPP
#include <stack>
#include <stdio.h>
using std::stack;
extern wchar_t *shell_path;
stack<long long>value_stack;
stack<unsigned long long>exvalue_stack;
stack<char *>str_stack;
stack<wchar_t *>wstr_stack;
stack<wchar_t *>path_stack;
void pop_path(void)
{
    if(path_stack.size()==0)
    {
        puts("Error:Unable to restore path from stack.");
        return;
    }
    shell_path=path_stack.top();
    path_stack.pop();
}
#endif