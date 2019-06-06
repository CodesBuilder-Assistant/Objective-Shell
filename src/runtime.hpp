#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#include "stack.hpp"
#include "var.hpp"
#include "algorithm.hpp"
#include "register.hpp"
#include "interrupt.hpp"
#include "gotofunc.hpp"
#include <algorithm>
#include <string>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <new>
#include <list>
#include <iostream>
using namespace std;
#ifdef __linux
#include <unistd.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
#define elif else if
constexpr char comment_char1='#';
bool IsInvalidIdentifier(string identifier)
{
    for(int i=0;i<identifier.length();i++)
        if((identifier[i]<'A'||identifier[i]>'Z')&&(identifier[i]<'a'||identifier[i]>'z')&&identifier[i]!='_'||identifier[0]<='0'&&identifier[0]>='9')
            return false;
    return true;
}
struct _operator
{
    char operator_char;
    unsigned int after_part_number;
};
/* Operators */
string valid_spec_char="+-*/!^&|=[]',.<>~:?()#";

char *errbuffer_line="##LINE##",*errbuffer_column="##COLUMN##";

#define ERROR_TOO_MANY_TYPES "Too many types."

bool error_actived=false;
string error_info;
wstring werror_info;
char info_type=-1;

constexpr char infotype_error='1',

void PrintErrorInfo(bool outwerrinfo)
{
    if(outwerrinfo)
    {

        wcout<<werror_info<<endl;
    }
}

long long value_return=NULL;
unsigned long long exvalue_return=NULL;
char str_return=NULL;
wchar_t wstr_return=NULL;

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
char *cmd_int="int";
char *cmd_short="short";
char *cmd_long="long";
char *cmd_byte="byte";
char *cmd_boolean="boolean";
char *cmd_exception="exception";
char *cmd_typename="typename";
char *cmd_str="str";
char *cmd_ptr="ptr";
char *cmd_signed="signed";
char *cmd_unsigned="unsigned";
char *cmd_extern="extern";
char *cmd_global="global";
char *cmd_local="local";
char *cmd_const="const";
char *cmd_type_const="type_const";
char *cmd_disable="disable";
char *cmd_enable="enable";
char *cmd_scope="scope";
char *cmd_interrupt="interrupt";
char *cmd_new="new";
char *cmd_delete="delete";
char *cmd_port_in="port_in";
char *cmd_port_out="port_out";
char *cmd_reg="reg";
char *cmd_swap="swap";
char *cmd_import="import";
char *cmd_unexport="unexport";
char *cmd_export="export";
char *cmd_function="function";
char *cmd_class="class";
char *cmd_public="public";
char *cmd_private="private";
char *cmd_protected="protected";
char *cmd_final="final";
char *cmd_inherited="inherited";
char *cmd_def="def";
char *cmd_return="return";
char *cmd_throw="throw";
char *cmd_catch="catch";
char *cmd_sizeof="sizeof";
char *cmd_typeof="typeof";
char *cmd_call="call";
char *cmd_goto="goto";
char *cmd_if="if";
char *cmd_elif="elif";
char *cmd_else="else";
char *cmd_switch="switch";
char *cmd_for="for";
char *cmd_loop="loop";
char *cmd_while="while";
char *cmd_end="end";
char *cmd_defined="defined";
char *cmd_spush="spush";
char *cmd_spop="spop";
char *cmd_type_cast="type_cast";
char *cmd_enum="enum";
char *cmd_reversed_enum="reversed_enum";
char *cmd_using="using";
char *cmd_inited="inited";

short ExecCommand(string one_line_of_command,unsigned short line_in_file)
{
    /* Separation parameters. */
    bool IsOperator=false;
    list<string>cmdpts;
    string CurrentString;
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
            for(int i=0;i<one_line_of_command.length;i++)
                for(int j=0;j<valid_spec_char.length;j++)
                    if(one_line_of_command[i]==valid_spec_char[i])
                    {
                        IsOperator=true;
                        cmdpts.push_back(CurrentString);
                        CurrentString.clear;
                        break;
                    }
                if(IsOperator)
                    continue;
                CurrentString+=one_line_of_command[i];
        }
    }
    /* Main process */
    for(int i=0;i<cmdpts.size();i++)
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