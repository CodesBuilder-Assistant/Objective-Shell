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
class function
{
    private:
        size_t start_offset;
        wstring function_name;
        wstring function_type;
        vector<wchar_t *> args;
        bool disabled;
        function(void)
        {
        };
    public:
        function(size_t __start_offset,wchar_t *func_name,wchar_t *func_type)
        {
            this->start_offset=__start_offset;
            this->function_name=func_name;
            this->disabled=false;
            this->function_type=func_type;
        }
        //Explame:
        //funtcion func(0,L"explame",L"arg_a,arg_b,arg_c");
        function(size_t __start_offset,wchar_t *func_name,wchar_t *args,wchar_t *func_type)
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
            this->disabled=false;
            this->function_type=func_type;
        }
        size_t offset(void)
        {
            return this->start_offset;
        }
        void undef(void)
        {
            this->disabled=true;
            this->function_name.clear();
            this->start_offset=NULL;
            this->args.clear();
        }
        void disable(void)
        {
            this->disabled=true;
        }
        void gotofunc(FILE **fp)
        {
            fseek(*fp,0L,this->start_offset);
        }
};
#endif