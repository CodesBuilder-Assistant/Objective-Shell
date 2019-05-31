#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#include "keyword.hpp"
#include <string.h>
#include <string>
using namespace std;
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
struct error_info
{
    unsigned int line;
    unsigned int column;
    unsigned short error_number_in_file;
};
char *errlog_filename=".__ObJEctIvEsHelL_eRrOR_lOG__";
void ShowErrorMessage(error_info err_struct)
{
    FILE *errlog=fopen(errlog_filename,"r");
    
    printf("In line:%u column:%u\n",err_struct.line,err_struct.column);
}
short ExecCommand(char *one_line_of_command,unsigned short line_in_file)
{
    FILE *errlog=fopen(errlog_filename,"w");
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
                    ops=new _operator[1];
                    ops_count++;
                    ops[ops_count-1].operator_char=one_line_of_command[i];
                    if(part_count==0)

                default:
                    cmdpart+=one_line_of_command[i];
            }
    /* Execute command. */

}
#endif