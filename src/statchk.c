#ifdef __linux
#include <unistd.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
void CrashMessage(void)
{
    #ifdef __linux
    puts("\033[0m[\033[31mError\033[0m]We are sorry,but Objective Shell has been crashed\nSelect an option to continue");
    char opt_buffer[5];
    select:
    puts("(Yes/No)");
    fgets(opt_buffer,5,stdin);
    if(opt_buffer=="Yes"||opt_buffer=="yes"||opt_buffer=="YES")
        if(fork()==0)
            execl("objshell",NULL);
    else if(opt_buffer=="No"||opt_buffer=="no"||opt_buffer=="NO")
        exit(0);
    else
    {
        puts("Invalid option");
        goto select;
    }
    #elif defined(_WIN32)||defined(_WIN64)
    if(MessageBoxA(NULL,"We are sorry,but Objective Shell has been crashed\nSelect an option to continue","Objective Shell has been crashed",MB_RETRYCANCEL|MB_ICONWARNING)==IDRETRY)
        ShellExecuteW(NULL,L"open",L"objshell.exe",NULL,NULL,NULL);
    #endif
}
int main(void)
{
    #ifdef __linux
    printf("\033[0m[\033[32mOK\033[0m]Started Objective Shell status check program\n");
    #elif defined(_WIN32)||defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    printf("[");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
    printf("OK");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    puts("]Started Objective Shell status check program");
    #endif
}