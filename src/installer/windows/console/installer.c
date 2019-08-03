#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <Windows.h>
#include <locale.h>
#include "lang.h"
bool isinstalling=false;
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

void destructor(void)
{
    free(installer_title);
    free(select_install_path);
    free(select_modules_to_install);
    free(next);
    free(back);
    free(cancel);
    free(ok);
    free(yes);
    free(no);
    free(installing);
    free(installation_completed);
    free(installation_failed);
    free(errcode);
    free(invalid_install_path);
}

int main(int argc,char *argv[])
{
    if(argc>1)
    {
        for(register int i=0;i<argc;i++)
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
                puts("  sc          Objective Shell Script Compiler");
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
    unsigned short selected=0;
    while(1)
    {
        puts("Select your language:\n");
        for(register int i=EN_US;i<LANGID_END;i++)
        {
            printf("[");
            if(selected==i)
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
                if(selected!=0)
                    selected--;
                break;
            case 80:
                if(selected!=LANGID_END-1)
                    selected++;
                break;
        }
        system("cls");
    }
    switch(selected)
    {
        case EN_US:
            installer_title=malloc(sizeof(installer_title_en_us));
            installer_title=installer_title_en_us;
            select_install_path=malloc(sizeof(select_install_path_en_us));
            select_install_path=select_install_path_en_us;
            select_modules_to_install=malloc(sizeof(select_modules_to_install_en_us));
            select_modules_to_install=select_modules_to_install_en_us;
            next=malloc(sizeof(next_en_us));
            next=next_en_us;
            back=malloc(sizeof(back_en_us));
            back=back_en_us;
            cancel=malloc(sizeof(cancel_en_us));
            cancel=cancel_en_us;
            ok=malloc(sizeof(ok_en_us));
            ok=ok_en_us;
            yes=malloc(sizeof(yes_en_us));
            yes=yes_en_us;
            no=malloc(sizeof(no_en_us));
            no=no_en_us;
            installing=malloc(sizeof(installing_en_us));
            installing=installing_en_us;
            installation_completed=malloc(sizeof(installation_completed_en_us));
            installation_completed=installation_completed_en_us;
            installation_failed=malloc(sizeof(installation_failed_en_us));
            errcode=malloc(sizeof(errcode_en_us));
            errcode=errcode_en_us;
            invalid_install_path=malloc(sizeof(invalid_install_path_en_us));
            invalid_install_path=invalid_install_path_en_us;
            break;
    }
    select_instpath:
    system("cls");
    wprintf(L"%ls",select_install_path);
    wchar_t *install_path;
    install_path=malloc(sizeof(wchar_t)*8193);
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
    unsigned short buf_unit_current;
    get_install_directory:
    buf_unit_current=0;
    fgetws(install_path,8192,stdin);
    RemoveDirectoryW(install_path);
    if(!CreateDirectoryW(install_path,NULL))
    {
        switch(GetLastError())
        {
            case CS_E_INVALID_PATH:
                system("cls");
                wprintf("%ls",invalid_install_path);
                goto get_install_directory;
        }
    }
    system("cls");
    bool *install_options=malloc(16);
    bool *module_tools=&install_options[0];
    bool *module_extra_tools=&install_options[1];
    bool *module_lib=&install_options[2];
    bool *module_script_compiler=&install_options[3];
    bool *module_tk=&install_options[4];
    bool *module_docs=&install_options[5];
    selected=0;
    while(1)
    {
        wprintf("%ls\n",select_modules_to_install);
        key=getch();
    }
    return 0;
}
