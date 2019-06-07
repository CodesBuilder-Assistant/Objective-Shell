/*
* Copyright(C)2019 CodesBuilder
* This software publish under the GPL.
*/
#include "runtime.hpp"

wstring CurrentPath;

int main(int argc,char *argv[])
{
    if(argc>1)
    {
        for(int i=0;i<argc;i++)
            if(argv[i]=="HE110W0R1D")
            {
                #ifdef __linux
                puts("\033[33mH\033[34me\033[36ml\033[38ml\033[92mo\033[0m,\033[93mW\033[94mo\033[95mr\033[96ml\033[97md\033[0m");
                #else
                puts("This program don't have Easter Egg.");
                #endif
                return 0;
            }
    }
    while(true)
    {
        wstring user_input;
        wcout<<CurrentPath;
        wcin>>user_input;
        ExecCommand(user_input);
    }
}