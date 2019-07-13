#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>
int main(int argc,char *argv[])
{
    bool auto_install=false;
    WORD language;
    if(argc>1)
    {
        for(int i=0;i<argc;i++)
            if(argv[i]=="-h"||argv[i]=="--help")
            {
                puts("Objective Shell Installer\n");
                puts("Syntax:[Installer file name] <options>");
                puts("The usable options:");
                puts("-l            Set installer language");
                puts("-a            Auto install Objective Shell");
                puts("-d            Set install directory");
                puts("-m            Set modules to install");
                puts("modules:");
                puts("  core        The core of Objective Shell(must install this module)");
                puts("  boot        Objective Shell Boot Media");
                puts("  lib         Objective Shell Library");
                puts("  cp          Objective Shell Script Compiler");
                puts("  tk          Objective Shell Toolkit");
                puts("  docs        Objective Shell Documents");
                puts("  all         All modules(normal)");
                puts("-u            Auto upgrade Objective Shell");
                puts("-h/--help     Show this list");
            }
    }
}