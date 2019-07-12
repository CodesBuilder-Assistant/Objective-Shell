#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include <stdio.h>
#include <wchar.h>
#if defined(_WIN32)||defined(_WIN64)
#include <Windows.h>
#endif
#include <string>
#include <vector>
#include "type.hpp"
using namespace std;
typedef struct
{
    unsigned short type_id;
    wchar_t *arg_name;
}argument;
class function
{
    private:
        size_t start_offset;
        wstring function_name;
        vector<wchar_t *> args;
        function(void)
        {
        };
    public:
        function(size_t __start_offset,wchar_t *func_name)
        {
            this->start_offset=__start_offset;
            this->function_name=func_name;
        }
        //Explame:
        //funtcion func(0,L"explame",L"arg_a,arg_b,arg_c");
        function(size_t __start_offset,wchar_t *func_name,wchar_t *args)
        {
            this->start_offset=__start_offset;
            this->function_name=func_name;
            wstring arg_name;
            for(int i=0;i<wcslen(args);i++)
            {
                if(args[i]==L',')
                {
                    this->args.push_back(arg_name.c_str);
                    arg_name.clear();
                }
                else
                    arg_name+=args[i];
            }
        }
        size_t offset(void)
        {
            return this->start_offset;
        }
        ~function(void)
        {
        }
};
#endif