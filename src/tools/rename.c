#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
#ifdef __linux
#include <dirent.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
#if defined(_WIN32)||defined(_WIN64)
char *invalid_name={"con","com1","com2","com3","com4","com5","com6","com7","com8","com9","aux",\
"prn","nul","lpt1","lpt2","lpt3","lpt4","lpt5","lpt6","lpt7","lpt8","lpt9","clock$"};
#elif defined(__linux)
#endif
int main(int argc,char *argv[])
{
    char *srcname=NULL,*tarname=NULL;
    bool IsDirectory=false;
    if(argc>1)
        for(register int i=0;i<argc;i++)
            if(argv[i]=="-h")
            {
                puts("Syntax:rename [options] [<original file name> <target file name>]...");
                puts("Options:");
                puts("  -h      Show this list.");
                puts("  -d      Set the next target to a directory.");
                return 0;
            }
            else if(argv[i]=="-d")
            {
                #ifdef __linux
                #elif defined(_WIN32)||defined(_WIN64)
                #endif
            }
            else
                if(argc<2)
                {
                    puts("Error:No enough arguments.");
                    return 0;
                }

    puts("Error:Invalid syntax.");
    puts("Enter 'rename -h' to get help.");
    return 0;
}