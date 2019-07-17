#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#if defined(_WIN32)||defined(_WIN64)
#include <Windows.h>
#elif defined(__linux__)
#include <unistd.h>
#include <boost/filesystem.hpp>
#endif
#include <string>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <new>
#include <iostream>
#include <vector>
#include <fstream>
#include <wchar.h>
#include "stack.hpp"
#include "var.hpp"
#include "algorithm.hpp"
#include "register.hpp"
#include "interrupt.hpp"
#include "gotofunc.hpp"
#include "ver.hpp"
#include "lock.hpp"
#include "alert.hpp"
#include "dir.hpp"
#include "port.hpp"
#include "network.hpp"
#include "locale.hpp"
#include "class.hpp"
#include "stack.hpp"
#include "system.hpp"
#include "startup.hpp"
#include "log.hpp"
#include "locale.hpp"
#include "user.hpp"
#include "hosts.hpp"
using namespace std;

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
const wchar_t *keyword_pin=L"pin";
const wchar_t *keyword_pout=L"pout";
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
const wchar_t *cmd_wait=L"wait";
const wchar_t *cmd_scan=L"scan";
const wchar_t *cmd_gl=L"gl";
const wchar_t *cmd_md=L"md";
const wchar_t *cmd_rd=L"rd";
const wchar_t *cmd_del=L"del";
const wchar_t *cmd_mkfile=L"mkfile";
const wchar_t *cmd_cpuid=L"cpuid";
const wchar_t *cmd_help=L"help";
const wchar_t *cmd_vfc=L"vfc";
const wchar_t *cmd_cd=L"cd";
const wchar_t *cmd_dir=L"dir";
const wchar_t *cmd_sort=L"sort";
const wchar_t *cmd_alert=L"alert";
const wchar_t *cmd_reset=L"reset";
const wchar_t *cmd_exec=L"exec";

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

unsigned int line=1;
unsigned int column=1;

void PrintErrorMessage(char *error_message,unsigned short msg_type_color,char *errmsg_type)
{
    printf("Line:%d Column:%d",line,column);
    #ifdef __linux__
    printf("\033[0m");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    #endif
    printf("[");
    #ifdef __linux__
    #elif defined(_WIN32)||defined(_WIN64)
    switch(msg_type_color)
    {
        case RED:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
            break;
        case GREEN:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
            break;
        case BLUE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE);
            break;
        case YELLOW:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);
            break;
        case PURPLE:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE);
            break;
        case CYAN:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    }
    #endif
}

bool IsOperator(wstring strobj)
{
    for(register int i=0;i<strobj.length();i++)
        if(strobj[i]!=L'+'&&\
        strobj[i]!=L'-'&&\
        strobj[i]!=L'*'&&\
        strobj[i]!=L'/'&&\
        strobj[i]!=L'$'&&\
        strobj[i]!=L'!'&&\
        strobj[i]!=L'='&&\
        strobj[i]!=L':'&&\
        strobj[i]!=L'?'&&\
        strobj[i]!=L'<'&&\
        strobj[i]!=L'>'&&\
        strobj[i]!=L'%'&&\
        strobj[i]!=L'^'&&\
        strobj[i]!=L'~'&&\
        strobj[i]!=L'['&&\
        strobj[i]!=L']'&&\
        strobj[i]!=L'('&&\
        strobj[i]!=L')'&&\
        strobj[i]!=L'.'&&\
        strobj[i]!=L','&&\
        strobj[i]!=L'{'&&\
        strobj[i]!=L'}')
            return false;
    return true;
}

bool IsInvalidIdentifier(wstring identifier)
{
    for(register int i=0;i<identifier.size();i++)

    return true;
}

short ExecCommand(wstring one_line_of_command)
{
    static unsigned short need_end_count=0;
    bool is_operator=false,instr=false;
    vector<wstring>cmdpts;
    wstring CurrentString;
    for(register int i=0;i<one_line_of_command.length();i++)
    {

    }
    /* Main process */
    for(unsigned int i=0;i<cmdpts.size();i++)
    {
        if(cmdpts[i]==keyword_boolean)
        {
            if(i+1==cmdpts.size()-1)
                PrintErrorMessage("Variable name not detected",RED,"Error");
            if(IsInvalidIdentifier(cmdpts[i+1]))
            {
                //TODO:Add the print error info codes.
                PrintErrorMessage("Invalid identidier",RED,"Error");
            }
        }
        else if(cmdpts[i]==cmd_cd)
        {
            if(i==cmdpts.size()-1)
                continue;
            else if(i>cmdpts.size())
                puts("\033[0m[\033[31mError\033[0m]Too much arguments");
            #ifdef __linux__
            if(boost::filesystem::exists(cmdpts[i+1]))
                CurrentPath=cmdpts[i+1];
            else
                puts("\033[0m[\033[31mError\033[0m]No such directory");
            #elif defined(_WIN32)||defined(_WIN64)

            #endif
            i+=1;
        }
        else if(cmdpts[i]==cmd_alert)
        {
            if(cmdpts[i+1]!=L"(")
                puts("\033[0m[\033[31mError\033[0m]Couldn't find operator '('");
            if(cmdpts[i+6]!=L")")
                puts("\033[0m[\033[31mError\033[0m]Couldn't find operator ')'");
            unsigned short _alert_type;
            xalert(cmdpts[i+2].c_str(),cmdpts[i+3].c_str());
        }
        else if(cmdpts[i]==cmd_vfc)
        {
            for(i+=1;i<cmdpts.size();i++)
            {
                #ifdef __linux__
                printf("\033[94m");
                #elif defined(_WIN32)||defined(_WIN64)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
                #endif
                wprintf(L"%ls\n\n",cmdpts[i].c_str());
                #ifdef __linux__
                if(boost::filesystem::exists(cmdpts[i]))
                {
                    boost::filesystem::wfstream current_file;
                    wchar_t current_char_buf;
                    current_file.open(cmdpts[i]);
                    while((current_file.read(&current_char_buf,sizeof(wchar_t))))
                    {
                        if(current_file.eof())
                            break;
                        wprintf(L"%lc",current_char_buf);
                    }
                }
                else
                {
                    puts("\033[0m[\033[31mError\033[0m]File not found");
                    continue;
                }
                #elif defined(_WIN32)||defined(_WIN64)
                HANDLE file_handle;
                if((file_handle=CreateFileW(cmdpts[i].c_str(),GENERIC_READ,NULL,NULL,OPEN_EXISTING,NULL,NULL))==INVALID_HANDLE_VALUE)
                {
                    CloseHandle(file_handle);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                    printf("[");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                    printf("Error");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                    puts("]File not found");
                }
                wchar_t rdfile_ret;
                DWORD rdbyte_count;
                while(true)
                {
                    ReadFile(file_handle,&rdfile_ret,sizeof(wchar_t),&rdbyte_count,NULL);
                    if(rdbyte_count==0)
                        break;
                    wprintf(L"%lc",rdfile_ret);
                }
                #endif
            }
        }
        else if(cmdpts[i]==cmd_echo)
        {
            for(i+=1;i>cmdpts.size();i++)
                wprintf(L"%ls\n",cmdpts[i].c_str);
        }
        else if(cmdpts[i]==cmd_dir)
        {
            if(i==cmdpts.size()-1)
                dir(L"*");
            else
            {
                for(i+=1;i<cmdpts.size();i++)
                    dir(cmdpts[i].c_str());
            }
        }
        else if(cmdpts[i]==cmd_reset)
        {
            if(i+1==cmdpts.size())
            {
                #ifdef __linux__
                puts("\033[0m[\033[31mError\033[0m]Too much arguments");
                #elif defined(_WIN32)||defined(_WIN64)
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                printf("[");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
                printf("Error");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                puts("]Too much arguments");
                #endif
                break;
            }
            #ifdef __linux__
            if(execv("objshell",(char *const *)"reseted_by_old_objshell_terminal")==-1)
                puts("\033[0m[\033[31mError\033[0m]Reset failed");
            #elif defined(_WIN32)||defined(_WIN64)

            #endif
        }
        else
        {
            int filename_unit=i;
            wstring args=cmdpts[i+1];
            for(i+=1;i<cmdpts.size();i++)
            {
                args+=L" ";
                args+=cmdpts[i];
            }
            #ifdef __linux__
            #elif defined(_WIN32)||defined(_WIN64)
            #endif
        }
    }
}
#endif
