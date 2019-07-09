#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <termios.h>
#include <stdbool.h>
enum languages
{
    en_us,
    zh_hans,
    zh_hant
};
struct termios terminal_old,terminal_current;
int main(int argc,char *argv[])
{
    bool auto_install=false;
    unsigned short language;
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
    puts("\033[0m[\033[32mOK\033[0m]Started Objective Shell Installer");
    setlocale(LC_ALL,"");
    puts("\033[0m[\033[32mOK\033[0m]Locale detected");
    printf("\033[2J");
    tcgetattr(0,&terminal_old);
    
    int key;
    unsigned short selected=0;
    while(1)
    {
        puts("\033[94;4m  Objective Shell Installer  \033[0m");
        puts("Select your language:");
        printf("[");
        if(selected==0)
            puts("*]English");
        else
            puts(" ]English");
        printf("[");
        if(selected==1)
            wprintf(L"*]简体中文");
        else
            wprintf(L" ]简体中文");
        printf("[");
        if(selected==2)
            wprintf(L"*]繁體中文\u000a");
        else
            wprintf(L" ]繁體中文\u000a");
        
        printf("\033[2J");
    }
    
    tcsetattr(0,TCSANOW,&terminal_old);
    tcsetattr(0,TCSANOW,&terminal_current);
}