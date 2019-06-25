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
#include <vector>
#include <fstream>
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
wstring valid_spec_char=L"r";

#define ERROR_TOO_MANY_TYPES "Too many types."

bool error_actived=false;
string error_info;
wstring werror_info;

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
const wchar_t *keyword_int=L"int";
const wchar_t *keyword_short=L"short";
const wchar_t *keyword_long=L"long";
const wchar_t *keyword_byte=L"byte";
const wchar_t *keyword_boolean=L"boolean";
const wchar_t *keyword_exception=L"exception";
const wchar_t *keyword_typename=L"typename";
const wchar_t *keyword_str=L"str";
const wchar_t *keyword_ptr=L"ptr";
const wchar_t *keyword_signed=L"signed";
const wchar_t *keyword_unsigned=L"unsigned";
const wchar_t *keyword_extern=L"extern";
const wchar_t *keyword_global=L"global";
const wchar_t *keyword_local=L"local";
const wchar_t *keyword_const=L"const";
const wchar_t *keyword_type_const=L"type_const";
const wchar_t *keyword_disable=L"disable";
const wchar_t *keyword_enable=L"enable";
const wchar_t *keyword_scope=L"scope";
const wchar_t *keyword_interrupt=L"interrupt";
const wchar_t *keyword_new=L"new";
const wchar_t *keyword_delete=L"delete";
const wchar_t *keyword_port_in=L"port_in";
const wchar_t *keyword_port_out=L"port_out";
const wchar_t *keyword_reg=L"reg";
const wchar_t *keyword_swap=L"swap";
const wchar_t *keyword_import=L"import";
const wchar_t *keyword_unexport=L"unexport";
const wchar_t *keyword_export=L"export";
const wchar_t *keyword_function=L"function";
const wchar_t *keyword_class=L"class";
const wchar_t *keyword_public=L"public";
const wchar_t *keyword_private=L"private";
const wchar_t *keyword_protected=L"protected";
const wchar_t *keyword_final=L"final";
const wchar_t *keyword_inherited=L"inherited";
const wchar_t *keyword_def=L"def";
const wchar_t *keyword_return=L"return";
const wchar_t *keyword_throw=L"throw";
const wchar_t *keyword_catch=L"catch";
const wchar_t *keyword_sizeof=L"sizeof";
const wchar_t *keyword_typeof=L"typeof";
const wchar_t *keyword_call=L"call";
const wchar_t *keyword_goto=L"goto";
const wchar_t *keyword_if=L"if";
const wchar_t *keyword_elif=L"elif";
const wchar_t *keyword_else=L"else";
const wchar_t *keyword_switch=L"switch";
const wchar_t *keyword_for=L"for";
const wchar_t *keyword_loop=L"loop";
const wchar_t *keyword_while=L"while";
const wchar_t *keyword_end=L"end";
const wchar_t *keyword_defined=L"defined";
const wchar_t *keyword_spush=L"spush";
const wchar_t *keyword_spop=L"spop";
const wchar_t *keyword_type_cast=L"type_cast";
const wchar_t *keyword_enum=L"enum";
const wchar_t *keyword_reversed_enum=L"reversed_enum";
const wchar_t *keyword_using=L"using";
const wchar_t *keyword_inited=L"inited";
const wchar_t *keyword_null=L"null";
const wchar_t *keyword_map=L"map";
const wchar_t *keyword_unmap=L"unmap";

const wchar_t *cmd_echo=L"echo";
const wchar_t *cmd_sleep=L"sleep";
const wchar_t *cmd_pause=L"pause";
const wchar_t *cmd_input=L"input";
const wchar_t *cmd_getline=L"getline";
const wchar_t *cmd_mkdir=L"mkdir";
const wchar_t *cmd_rmdir=L"rmdir";
const wchar_t *cmd_del=L"del";
const wchar_t *cmd_mkfile=L"mkfile";
const wchar_t *cmd_cpuid=L"cpuid";
const wchar_t *cmd_help=L"help";
const wchar_t *cmd_pvf=L"pvf";
const wchar_t *cmd_diff=L"diff";
const wchar_t *cmd_cd=L"cd";
const wchar_t *cmd_dir=L"dir";
const wchar_t *cmd_sort=L"sort";
const wchar_t *cmd_alert=L"alert";

const wchar_t operator_add=L'+';
const wchar_t operator_sub=L'-';
const wchar_t operator_mul=L'*';
const wchar_t operator_div=L'/';
const wchar_t operator_xor=L'^';
const wchar_t operator_and=L'&';
const wchar_t operator_or=L'|';
const wchar_t operator_subscript_left=L'[';
const wchar_t operator_subscript_right=L']';
const wchar_t operator_mov=L'=';
const wchar_t operator_mod=L'%';
const wchar_t operator_not=L'!';
const wchar_t operator_str_a=L'"';
const wchar_t operator_str_b=L'\'';
const wchar_t operator_member_access=L'.';
const wchar_t operator_more=L'>';
const wchar_t operator_less=L'<';
const wchar_t operator_var_access=L'$';
const wchar_t operator_bin_reserve=L'~';
const wchar_t operator_ternary_part_a=L'?';
const wchar_t operator_ternary_part_b=L':';
const wchar_t operator_case_start=operator_ternary_part_b;
const wchar_t *operator_equ=L"==";
const wchar_t *operator_notequ=L"!=";
const wchar_t *operator_inc=L"++";
const wchar_t *operator_dec=L"--";
const wchar_t *operator_moreequ=L">=";
const wchar_t *operator_lessequ=L"<=";
const wchar_t *operator_double_or=L"||";
const wchar_t *operator_double_and=L"&&";
const wchar_t *operator_double_more=L">>";
const wchar_t *operator_double_less=L"<<";

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
    COMPILED_OPERATOR_SUBSCRIPT_LEFT,
    COMPILED_OPERATOR_SUBSCRIPT_RIGHT,
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

extern wstring CurrentPath;

enum errmsg_types_and_colors
{
    RED=1001,
    GREEN,
    BLUE,
    GREY,
    WHITE,
    PURPLE,
    YELLOW,
    CYAN,
    ERRMSG_ERROR,
    ERRMSG_WARNING,
    ERRMSG_NOTE
};

void PrintErrorMessage(char *error_message,unsigned short msg_type_color,char *errmsg)
{
    #ifdef __linux
    printf("\033[0m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    #endif
    printf("[");
    switch(msg_type_color)
    {
        case RED:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
            break;
        case GREEN:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
            break;
        case BLUE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
            break;

    }
}

short ExecCommand(wstring one_line_of_command)
{
    /* Separation parameters. */
    bool IsOperator=false;
    vector<wstring>cmdpts;
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
                PrintErrorMessage
            }
        }
        else
        {
            if(cmdpts[i]==cmd_cd)
            {
                if((cmdpts.size()-1)-i>1)
                {
                    #ifdef __linux
                    printf("\033[0m[\033[31mError\033[0m]Too much arguments.\n");
                    #elif defined(_WIN32)||defined(_WIN64)
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                    printf("[");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                    printf("Error");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                    printf("]");
                    puts("Too much arguments.");
                    #endif
                }
                #ifdef __linux
                wstring check_file_name=cmdpts[i];
                check_file_name+=L".__DIRECTORY_EXIST_CHECK__";
                wfstream dirchk;
                dirchk.open(check_file_name.c_str(),ios_base::app);
                #elif defined(_WIN32)||defined(_WIN64)
                int folderattribute=GetFileAttributesW(cmdpts[i].c_str());
                if(folderattribute!=FILE_ATTRIBUTE_DIRECTORY)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                    printf("[");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                    printf("Error");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                    wstring error_message=L"]'";
                    error_message+=cmdpts[i];
                    error_message+=L"' not a directory or directory is not exist.";
                    wprintf(error_message.c_str());
                    puts("");
                }
                #endif
            }
        }
    }
}
#endif
