#include <stdio.h>
#include <memory.h>
#include <stdbool.h>
#include <wchar.h>
#ifdef __linux__
#include <io.h>
#elif defined(_WIN32)
#include <Windows.h>
#endif
int main(int argc,wchar_t *argv[])
{
    wchar_t *srcname=NULL,*target_name=NULL;
    bool IsDirectory=false;
    if(argc>1)
        for(register int i=0;i<argc;i++)
            if(argv[i]==L"-h")
            {
                puts("Syntax:rename [options] [<original file name> <target file name>]...");
                puts("Options:");
                puts("  -h      Show this list.");
                puts("  -d      Set the next target to a directory.");
                return 0;
            }
            else if(argv[i]==L"-d")
            {
                #ifdef __linux__
                #elif defined(_WIN32)
                HANDLE dir_handle=GetFileAttributesW;
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