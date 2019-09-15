#include "interpreter.hpp"
#include <algorithm>
using std::fill;

unsigned int user_input_buffer_size=4096;
wchar_t *user_input_buffer=new wchar_t[4096];

int main(unsigned int argc,char **argv)
{
    if(argc>1)
    {
        for(unsigned int i=0;i<argc;i++)
            if(argv[i]=="-h"||argv[i]=="--help")
            {
                puts("Objective Shell Help");
            }
    }

    while(true)
    {
        wprintf(L"[OBJSHELL] %ls>",current_dir);
        fgetws(user_input_buffer,user_input_buffer_size,stdin);
        ExecuteCommand(SeprateArguments(user_input_buffer));
        fill(user_input_buffer,user_input_buffer+user_input_buffer_size*sizeof(wchar_t),L'\0');
    }
}