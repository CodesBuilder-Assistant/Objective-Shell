#ifndef VER_HPP
#define VER_HPP
#include <stdio.h>
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
enum ver_type
{
    test=0,
    beta,
    stable,
    secret_test
};
constexpr unsigned short version_type=secret_test;
#define CODENAME ""
constexpr unsigned int build=1;
/*
* Version Format:
* 1.0.0.1 <Version Type>
* | | | L Build Number
* | | L Patch Version
* | L Minor Version
* L Main Version
*/
constexpr char *VERSION="1.0.0";
void ShowVersionInfo(void)
{
    printf("Objective Shell");
    if(version_type!=stable)
        printf(" Codename '%s'\n",CODENAME);
    else
        puts("");
    printf("Version:%s.%d",VERSION,build);
    switch(version_type)
    {
        case test:
            puts(" Test ");
            break;
        case beta:
            puts(" Beta");
            break;
        case secret_test:
            puts(" Secret Test");
            puts("This test version of Objective Shell is not a public version");
            break;
        default:
            puts(" ?");
            #ifdef __linux
            printf("\033[0m[\033[31mError\033[0m]Error version type,please recompile this version.");
            #elif defined(_WIN32)||defined(_WIN64)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("[");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
            printf("Error");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            printf("]Error version type,please recompile this version.");
            #endif
    }
    #ifdef __linux
    puts("Target OS:Linux");
    #elif defined(_WIN32)
    puts("Target OS:Windows 32-bit");
    #elif defined(_WIN64)
    puts("Target OS:Windows 64-bit");
    #endif
    printf("Processor Architecture:");
    #ifdef __x86_64__
    puts("amd64");
    #elif defined(__i386__)
    puts("i386");
    #endif
}
#endif