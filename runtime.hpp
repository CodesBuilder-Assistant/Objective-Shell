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
using namespace std;
#ifdef __linux
#include <unistd.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
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
            cmdpart.empty();
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
    /* Execute command. */

}
#endif