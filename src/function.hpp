#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <stdio.h>
#include <wchar.h>
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
#include <string>
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
        string function_name;
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
        size_t offset(void)
        {
            return this->start_offset;
        }
        ~function(void)
        {
            delete[] this->function_name;
        }
};
#endif