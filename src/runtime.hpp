#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#include "keyword.hpp"
#include "stack.hpp"
#include <string>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <new>
#include <string.h>
#include <list>
using namespace std;
#ifdef __linux
#include <unistd.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
#define elif else if
constexpr char comment_char1='#';
bool IsInvalidIdentifier(char *identifier)
{
    for(int i=0;i<strlen(identifier);i++)
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
constexpr char op_plus='+',op_minus='-',op_multi='*',op_division='/',op_or='|',op_and='&',op_xor='^';

char *errbuffer_line="@$LINE$@",*errbuffer_column="@$COLUMN@$";

struct error_info
{
    unsigned int line;
    unsigned int column;
    string error_info;
}errbuffer;
void ShowErrorMessage(void)
{
    
}

//Return buffers.
long long *value_return=NULL;
unsigned long long exvalue_return=NULL;
char *str_return=NULL;
wchar_t *wstr_return=NULL;

short ExecCommand(char *one_line_of_command,unsigned short line_in_file)
{
    /* Separation parameters. */
    unsigned int part_count=0;
    unsigned int ops_count=0;
    string *cmdparts;
    string cmdpart;
    _operator *ops;
    if(strlen(one_line_of_command)==0)
        return false;
    for(int i=0;i<strlen(one_line_of_command);i++)
        if(one_line_of_command[i]==' ')
        {
            if(cmdpart=="")
                continue;
            cmdparts=new string[1];
            part_count++;
            cmdparts[part_count-1]=cmdpart;
            cmdpart.clear();
        }
        else
            switch(one_line_of_command[i])
            {
                case op_plus:
                    if(part_count==0)
                    {
                        errbuffer.error_info="";
                    }
                    ops=new _operator[1];
                    ops_count++;
                    ops[ops_count-1].operator_char=one_line_of_command[i];
                default:
                    cmdpart+=one_line_of_command[i];
            }
    list<int>last_commands;
    /* Execute command. */
    for(int i=0,command_ptr=0;i<part_count;i++)
    {
        //TODO:Add show error messages code and syntax check code.
        //I cannot finish it today,but we have the tomorrow.
        if(cmdparts[i]=="int")
            last_commands.push_back(TYPE_INT);
        elif(cmdparts[i]=="short")
            last_commands.push_back(TYPE_SHORT);
        elif(cmdparts[i]=="long")
            last_commands.push_back(TYPE_LONG);
        elif(cmdparts[i]=="byte")
            last_command.push_back(TYPE_BYTE);
        elif(cmdparts[i]=="boolean")
            last_command.push_back(TYPE_BOOLEAN);
        elif(cmdparts[i]=="var")
            last_command.push_back(TYPE_VAR);
        elif(cmdparts[i]=="exception")
            last_command.push_back(TYPE_EXCEPTION);
        elif(cmdparts[i]=="typename")
            last_command.push_back(TYPE_TYPENAME);
        elif(cmdparts[i]=="str")
            last_command.push_back(TYPE_STR);
        elif(cmdparts[i]=="unsigned")
        {
            if(last_commands[i-1]==MODIFIER_SIGNED)
            {
                last_commands.remove(i-1);
                command_ptr--;
            }
            command_ptr.push_back(MODIFIER_UNSIGNED);
        }
        elif(cmdparts[i]=="signed")
        {
            if(last_commands[i-1]==MODIFIER_UNSIGNED)
            {
                last_commands.remove(i-1);
                command_ptr--;
            }
            command_ptr.push_back(MODIFIER_SIGNED);
        }
        elif(cmdparts[i]=="ptr")
            last_command.push_back(MODIFIER_PTR);
        command_ptr++;
    }
}
#endif