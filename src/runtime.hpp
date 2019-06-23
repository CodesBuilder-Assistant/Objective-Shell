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
#include <iostream>
#ifdef __linux
#include <sys/io.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <io.h>
#endif
#include <wchar.h>
using namespace std;
#ifdef __linux
#include <unistd.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif

constexpr wchar_t comment_char1='#';
bool IsInvalidIdentifier(wstring identifier)
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

constexpr wchar_t *errbuffer_line=L"##LINE##",*errbuffer_column=L"##COLUMN##";

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
        #ifdef __linux
        printf("\033[0m[\033[31mError\033[0m]");
        #elif defined(_WIN32)||defined(_WIN64)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf("[");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        printf("Error");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf("]");
        #endif
        wprintf(werror_info.c_str());
        puts("");
    }
}

long long value_return=NULL;
unsigned long long exvalue_return=NULL;
char *str_return=NULL;
constexpr wchar_t *wstr_return=NULL;

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
constexpr wchar_t *keyword_int=L"int";
constexpr wchar_t *keyword_short=L"short";
constexpr wchar_t *keyword_long=L"long";
constexpr wchar_t *keyword_byte=L"byte";
constexpr wchar_t *keyword_boolean=L"boolean";
constexpr wchar_t *keyword_exception=L"exception";
constexpr wchar_t *keyword_typename=L"typename";
constexpr wchar_t *keyword_str=L"str";
constexpr wchar_t *keyword_ptr=L"ptr";
constexpr wchar_t *keyword_signed=L"signed";
constexpr wchar_t *keyword_unsigned=L"unsigned";
constexpr wchar_t *keyword_extern=L"extern";
constexpr wchar_t *keyword_global=L"global";
constexpr wchar_t *keyword_local=L"local";
constexpr wchar_t *keyword_const=L"const";
constexpr wchar_t *keyword_type_const=L"type_const";
constexpr wchar_t *keyword_disable=L"disable";
constexpr wchar_t *keyword_enable=L"enable";
constexpr wchar_t *keyword_scope=L"scope";
constexpr wchar_t *keyword_interrupt=L"interrupt";
constexpr wchar_t *keyword_new=L"new";
constexpr wchar_t *keyword_delete=L"delete";
constexpr wchar_t *keyword_port_in=L"port_in";
constexpr wchar_t *keyword_port_out=L"port_out";
constexpr wchar_t *keyword_reg=L"reg";
constexpr wchar_t *keyword_swap=L"swap";
constexpr wchar_t *keyword_import=L"import";
constexpr wchar_t *keyword_unexport=L"unexport";
constexpr wchar_t *keyword_export=L"export";
constexpr wchar_t *keyword_function=L"function";
constexpr wchar_t *keyword_class=L"class";
constexpr wchar_t *keyword_public=L"public";
constexpr wchar_t *keyword_private=L"private";
constexpr wchar_t *keyword_protected=L"protected";
constexpr wchar_t *keyword_final=L"final";
constexpr wchar_t *keyword_inherited=L"inherited";
constexpr wchar_t *keyword_def=L"def";
constexpr wchar_t *keyword_return=L"return";
constexpr wchar_t *keyword_throw=L"throw";
constexpr wchar_t *keyword_catch=L"catch";
constexpr wchar_t *keyword_sizeof=L"sizeof";
constexpr wchar_t *keyword_typeof=L"typeof";
constexpr wchar_t *keyword_call=L"call";
constexpr wchar_t *keyword_goto=L"goto";
constexpr wchar_t *keyword_if=L"if";
constexpr wchar_t *keyword_elif=L"elif";
constexpr wchar_t *keyword_else=L"else";
constexpr wchar_t *keyword_switch=L"switch";
constexpr wchar_t *keyword_for=L"for";
constexpr wchar_t *keyword_loop=L"loop";
constexpr wchar_t *keyword_while=L"while";
constexpr wchar_t *keyword_end=L"end";
constexpr wchar_t *keyword_defined=L"defined";
constexpr wchar_t *keyword_spush=L"spush";
constexpr wchar_t *keyword_spop=L"spop";
constexpr wchar_t *keyword_type_cast=L"type_cast";
constexpr wchar_t *keyword_enum=L"enum";
constexpr wchar_t *keyword_reversed_enum=L"reversed_enum";
constexpr wchar_t *keyword_using=L"using";
constexpr wchar_t *keyword_inited=L"inited";
constexpr wchar_t *keyword_null=L"null";

constexpr wchar_t *cmd_echo=L"echo";
constexpr wchar_t *cmd_exec=L"exec";
constexpr wchar_t *cmd_sleep=L"sleep";
constexpr wchar_t *cmd_pause=L"pause";
constexpr wchar_t *cmd_input=L"input";
constexpr wchar_t *cmd_getline=L"getline";
constexpr wchar_t *cmd_mkdir=L"mkdir";
constexpr wchar_t *cmd_rmdir=L"rmdir";
constexpr wchar_t *cmd_del=L"del";
constexpr wchar_t *cmd_mkfile=L"mkfile";
constexpr wchar_t *cmd_cpuid=L"cpuid";
constexpr wchar_t *cmd_help=L"help";
constexpr wchar_t *cmd_pvf=L"pvf";
constexpr wchar_t *cmd_diff=L"diff";

enum COMPILED_COMMAND
{
    COMPILED_SCRIPT_HEAD_A=1024,
    COMPILED_SCRIPT_HEAD_B=1066,
    COMPILED_SCRIPT_END_A=2056,
    COMPILED_SCRIPT_END_B=2139,
    COMPILED_OPERATOR_ADD=2200,
    COMPILED_OPERATOR_SUB,
    COMPILED_OPERATOR_MUL,
    COMPILED_OPERATOR_DIV,
    COMPILED_OPERATOR_XOR,
    COMPILED_OPERATOR_AND,
    COMPILED_OPERATOR_OR,
    COMPILED_OPERATOR_MOD,
    COMPILED_OPERATOR_INC,
    COMPILED_OPERATOR_DEC,
    COMPILED_OPERATOR_NOT,
    COMPILED_OPERATOR_SUBSCRIPT,
    COMPILED_OPERATOR_EQU,
    COMPILED_OPERATOR_LESS,
    COMPILED_OPERATOR_MORE,
    COMPILED_OPERATOR_LESSEQU,
    COMPILED_OPERATOR_MOREEQU,
    COMPILED_OPERATOR_NOTEQU,
    COMPILED_OPERATOR_DOUBLE_AND,
    COMPILED_OPERATOR_DOUBLE_OR,
    COMPILED_OPERATOR_BINARY_RESERVE,
    COMPILED_OPERATOR_DOUBLE_LESS,
    COMPILED_OPERATOR_DOUBLE_MORE,
    COMPILED_KEYWORD_INT,
    COMPILED_KEYWORD_SHORT,
    COMPILED_KEYWORD_LONG,
    COMPILED_KEYWORD_BYTE,
    COMPILED_KEYWORD_BOOLEAN,
    COMPILED_KEYWORD_EXCEPTION,
    CONPILED_KEYWORD_TYPE,
    COMPILED_KEYWORD_STR,
    COMPILED_KEYWORD_PTR,
    COMPILED_KEYWORD_SIGNED,
    COMPILED_KEYWORD_UNSIGNED,
    COMPILED_KEYWORD_EXTERM,
    COMPILED_KEYWORD_GLOBAL,
    COMPILED_KEYWORD_LOCAL,
    COMPILED_KEYWORD_CONST,
    COMPILED_KEYWORD_TYPE_CONST,
    COMPILED_KEYWORD_DISABLE,
    COMPILED_KEYWORD_ENABLE,
    COMPILED_KEYWORD_SCOPE,
    COMPILED_KEYWORD_INTERRUPT,
};

short ExecCommand(wstring one_line_of_command)
{
    /* Separation parameters. */
    bool IsOperator=false;
    deque<wstring>cmdpts;
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
        if(cmdpts[i]==keyword_boolean)
        {
            if(IsInvalidIdentifier(cmdpts[i+1]))
            {
                //TODO:Add the print error info codes.
            }
        }
        else if(cmdpts[i]==cmd_exec)
        {
            #ifdef __linux
            if(fork()==0)
            {
                wstring exec_arg;
                for(int j=i+1;j<cmdpts.size();j++)
                {
                    wstring+=' ';
                    wstring+=cmdpts[j];
                }
                execlp()
            }
            else
            {
                wait()
            }
            #elif defined(_WIN32)||defined(_WIN64)
            #endif
        }
        else
        {

        }
    }
}
#endif
