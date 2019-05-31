#include <stdio.h>
int main(int argc,char *argv[])
{
    if(argc>1)
        for(int i=0;i<argc;i++)
            if(argv[i]=="-h")
            {
                puts("Syntax:rename [options] [original file name] [target file name]");
                puts("Options:");
                puts("  -h      Show this list.");
                puts("  -d      Set the next target to a directory.");
                return 0;
            }
    show_syntax_info:
    puts("Error:Invalid syntax.");
    puts("Enter rename -h to get help.");
    return 0;
}