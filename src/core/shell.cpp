#include "interpreter.hpp"
unsigned int user_input_buffer_size=4096;
wchar_t *user_input_buffer=new wchar_t[4096];
int main(unsigned int argc,char **argv)
{
    if(argc>1)
    {
        for(unsigned int i;i<argc;i++)
            if(argv[i]=="-h"||argv[i]=="--help")
            {
                puts("Objective Shell Help");
            }
    }
    while(true)
    {
        printf("[OBJSHELL] >");
        fgetws(user_input_buffer,user_input_buffer_size,stdin);

    }
}