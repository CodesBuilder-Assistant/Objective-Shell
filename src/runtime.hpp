#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#include "stack.hpp"
#include "var.hpp"
#include "algorithm.hpp"
#include "register.hpp"
#include "interrupt.hpp"
#include "gotofunc.hpp"
#include <string>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <new>
#include <list>
#include <iostream>
#include <sys/io.h>
#include <wchar.h>
using namespace std;
#ifdef __linux
#include <unistd.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif

#define elif else if
constexpr wchar_t comment_char1='#';
bool IsInvalidIdentifier(string identifier)
{
    for(int i=0;i<identifier.length();i++)
        if((identifier[i]<'A'||identifier[i]>'Z')&&(identifier[i]<'a'||identifier[i]>'z')&&identifier[i]!='_'||identifier[0]<='0'&&identifier[0]>='9')
            return false;
    return true;
}
struct _operator
{
    wchar_t operator_char;
    unsigned int after_part_number;
};
/* Operators */
wstring valid_spec_char=L"+-*/!^&|=[]',.<>~:?()#";

wchar_t *errbuffer_line=L"##LINE##",*errbuffer_column=L"##COLUMN##";

#define ERROR_TOO_MANY_TYPES "Too many types."

bool error_actived=false;
string error_info;
wstring werror_info;
unsigned short info_type=-1;

constexpr wchar_t infotype_error='1';

void PrintErrorInfo(bool outwerrinfo)
{
    if(outwerrinfo)
    {

        wcout<<werror_info<<endl;
    }
}

long long value_return=NULL;
unsigned long long exvalue_return=NULL;
char *str_return=NULL;
wchar_t *wstr_return=NULL;

/*
* Range of values:
* int:–2147483648-4294967295
* short:–32768-65535
* long:–9223372036854775808-18446744073709551615
* byte:-128-256
* boolean:0-1
* var:auto
* The interpreter will auto set the variable is signed or unsigned.
*/
wchar_t *cmd_int=L"int";
wchar_t *cmd_short=L"short";
wchar_t *cmd_long=L"long";
wchar_t *cmd_byte=L"byte";
wchar_t *cmd_boolean=L"boolean";
wchar_t *cmd_exception=L"exception";
wchar_t *cmd_typename=L"typename";
wchar_t *cmd_str=L"str";
wchar_t *cmd_ptr=L"ptr";
wchar_t *cmd_signed=L"signed";
wchar_t *cmd_unsigned=L"unsigned";
wchar_t *cmd_extern=L"extern";
wchar_t *cmd_global=L"global";
wchar_t *cmd_local=L"local";
wchar_t *cmd_const=L"const";
wchar_t *cmd_type_const=L"type_const";
wchar_t *cmd_disable=L"disable";
wchar_t *cmd_enable=L"enable";
wchar_t *cmd_scope=L"scope";
wchar_t *cmd_interrupt=L"interrupt";
wchar_t *cmd_new=L"new";
wchar_t *cmd_delete=L"delete";
wchar_t *cmd_port_in=L"port_in";
wchar_t *cmd_port_out=L"port_out";
wchar_t *cmd_reg=L"reg";
wchar_t *cmd_swap=L"swap";
wchar_t *cmd_import=L"import";
wchar_t *cmd_unexport=L"unexport";
wchar_t *cmd_export=L"export";
wchar_t *cmd_function=L"function";
wchar_t *cmd_class=L"class";
wchar_t *cmd_public=L"public";
wchar_t *cmd_private=L"private";
wchar_t *cmd_protected=L"protected";
wchar_t *cmd_final=L"final";
wchar_t *cmd_inherited=L"inherited";
wchar_t *cmd_def=L"def";
wchar_t *cmd_return=L"return";
wchar_t *cmd_throw=L"throw";
wchar_t *cmd_catch=L"catch";
wchar_t *cmd_sizeof=L"sizeof";
wchar_t *cmd_typeof=L"typeof";
wchar_t *cmd_call=L"call";
wchar_t *cmd_goto=L"goto";
wchar_t *cmd_if=L"if";
wchar_t *cmd_elif=L"elif";
wchar_t *cmd_else=L"else";
wchar_t *cmd_switch=L"switch";
wchar_t *cmd_for=L"for";
wchar_t *cmd_loop=L"loop";
wchar_t *cmd_while=L"while";
wchar_t *cmd_end=L"end";
wchar_t *cmd_defined=L"defined";
wchar_t *cmd_spush=L"spush";
wchar_t *cmd_spop=L"spop";
wchar_t *cmd_type_cast=L"type_cast";
wchar_t *cmd_enum=L"enum";
wchar_t *cmd_reversed_enum=L"reversed_enum";
wchar_t *cmd_using=L"using";
wchar_t *cmd_inited=L"inited";

short ExecCommand(wstring one_line_of_command)
{
    /* Separation parameters. */
    bool IsOperator=false;
    list<wstring>cmdpts;
    wstring CurrentString;
    for(int i=0;i<one_line_of_command.length();i++)
    {
        if(IsOperator)
            for(int i=0;i<one_line_of_command.length();i++)
            {
                for(int j=0;j<valid_spec_char.length();j++)
                    if(one_line_of_command[i]!=valid_spec_char[j])
                    {
                        IsOperator=false;
                        cmdpts.push_back(CurrentString);
                        CurrentString.clear();
                        break;
                    }
                if(!IsOperator)
                    continue;
                CurrentString+=one_line_of_command[i];
            }
        else
        {
            for(int i=0;i<one_line_of_command.length();i++)
                for(int j=0;j<valid_spec_char.length();j++)
                    if(one_line_of_command[i]==valid_spec_char[i])
                    {
                        IsOperator=true;
                        cmdpts.push_back(CurrentString);
                        CurrentString.clear();
                        break;
                    }
                if(IsOperator)
                    continue;
                CurrentString+=one_line_of_command[i];
        }
    }
    /* Main process */
    for(unsigned int i=0;i<cmdpts.size();i++)
    {
        if(cmdpts[i]==cmd_boolean)
        {
            if(IsInvalidIdentifier(cmdpts[i+1]))
            {
                //TODO:Add the print error info codes.
            }
        }
    }
}
#endif