#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
#ifdef __linux
#include <dirent.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
int main(int argc,char *argv[])
{
    char *srcname=NULL,*tarname=NULL;
    bool IsDirectory=false;
    if(argc>1)
        for(int i=0;i<argc;i++)
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

            }
    puts("Error:Invalid syntax.");
    puts("Enter 'rename -h' to get help.");
    return 0;
}