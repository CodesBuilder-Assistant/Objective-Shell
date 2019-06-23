#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <stdio.h>
#include <wchar.h>
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
#include "type.hpp"
typedef struct
{
    unsigned short type_id;
    wchar_t *arg_name;
}argument;
class function
{
    private:
        size_t start_offset;
        const wchar_t *function_name;
        argument *args;
        function(void)
        {
        };
    public:
        function(size_t __start_offset,wchar_t *func_name)
        {
            this->start_offset=__start_offset;
            this->function_name=new wchar_t[wcslen(func_name)+1];
            this->function_name=func_name;
        }
        void GotoFunction(FILE *file_ptr)
        {
            if(fseek(file_ptr,0,this->start_offset)!=0)
            {
                #ifdef __linux
                puts("\033[0m[\033[31mError\033[0m]Couldn't change file pointer to function start,Interrupted process");
                #elif defined(_WIN32)||defined(_WIN64)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("[");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                printf("Error");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("]Couldn't change file pointer to function start,Interrupted process");
                #endif
            }
        }
        ~function(void)
        {
            delete[] this->function_name;
        }
};
#endif