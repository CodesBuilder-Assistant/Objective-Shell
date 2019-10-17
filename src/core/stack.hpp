#ifndef STACK_HPP
#define STACK_HPP
#include <new>
#include <effects.hpp>
#include <stdio.h>
using std::bad_alloc;
char *stack_ptr;
unsigned int stack_size;
unsigned int used_stack_size;
void ClearStack(void)
{
    for(int i=0;i<stack_size;i++)
        stack_ptr[i]=0;
}
bool InitializationStack(unsigned int _stack_size)
{
    if(stack_size==0)
        return false;
    try
    {
        stack_ptr=new char[_stack_size];
    }
    catch(bad_alloc)
    {
        SetConsoleTextColor(WHITE);
        printf("[");
        SetConsoleTextColor(RED);
        printf("Error");
        SetConsoleTextColor(WHITE);
        puts("]No enough memory to create stack");
        return false;
    }
    stack_size=_stack_size;
    used_stack_size=0;
    ClearStack();
    return true;
}
template<class type>bool PushToStack(type push_data)
{
    if(sizeof(type)+used_stack_size>stack_size)
        return false;
    for(char *current_data_ptr=&stack_ptr+stack_size,current_push_data_ptr=&push_data;current_data_ptr;current_data_ptr<=stack_ptr+used_stack_size+sizeof(type);current_data_ptr++,current_push_data_ptr++)
        *current_data_ptr=*current_push_data_ptr;
    used_stack_size+=sizeof(type);
    return true;
}
void DestroyStack(void)
{
    delete[] stack_ptr;
    stack_size=NULL;
    used_stack_size=NULL;
}
#endif