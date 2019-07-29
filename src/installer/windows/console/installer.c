#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>
#include <locale.h>
#include "lang.h"
bool installing=false;
bool install_log=false;
DWORD WINAPI InstallLogEnableThread(void)
{
    int key;
    while(1)
    {
        key=_kbhit();
        if(key!=0)
        {
            key=_getch();
            if(key==VK_ESCAPE)
            {
                puts("Install log enabled");
                install_log=true;
                break;
            }
        }
    }
    return 0;
}

int main(int argc,char *argv[])
{
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
    puts("Press ESC to enable install log");
    HANDLE install_log_enable_thread=CreateThread(NULL,NULL,InstallLogEnableThread,NULL,NULL,NULL);
    Sleep(500);
    CloseHandle(install_log_enable_thread);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    system("cls");
    setlocale(LC_ALL,"");
    unsigned short language_id=0;
    while(1)
    {
        puts("Select your language:\n");
        for(int i=EN_US;i<LANGID_END;i++)
        {
            printf("[");
            if(language_id==i)
                printf("*]");
            else
                printf(" ]");
            wprintf(L"%ls\n",language_select_show[i]);
        }
        switch(getch())
        {
            case VK_RETURN:
                goto select_instpath;
                break;
            case 72:
                if(language_id!=0)
                    language_id--;
                break;
            case 80:
                if(language_id!=LANGID_END-1)
                    language_id++;
                break;
        }
        system("cls");
    }
    switch(language_id)
    {
        case EN_US:
            installer_title=installer_title_en_us;

            break;
    }
    select_instpath:
    system("cls");
    printf("Install Path:");
    wchar_t *install_path;
    install_path=malloc(sizeof(wchar_t)*16384);
    if(install_path==NULL)
    {
        system("cls");
        printf("[");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        printf("Error");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        puts("]Out of memory!");
        return 0;
    }
    bool auto_install=false;
    unsigned char key;
    unsigned short buf_unit_current=0;
    while((key=getch())!=VK_RETURN)
    {
        if(key>='!'&&key<='z')
        {
            install_path[buf_unit_current]=L'\0';
            buf_unit_current++;
            printf("%c",key);
        }
        else if(key==VK_BACK)
        {
            if(buf_unit_current!=0)
            {
                printf("\b \b");
                install_path[buf_unit_current]=L"\0";
                buf_unit_current--;
            }
        }
    }
    return 0;
}
