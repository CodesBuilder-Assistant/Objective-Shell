#ifndef LOCALE_HPP
#define LOCALE_HPP
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
#include <stdio.h>
char *GetLocale(void)
{
    FILE *locale_conf_fp;
    #ifdef __linux
    if((locale_conf_fp=fopen("/etc/objshell/locale.bin","r"))==NULL)
    {
        fclose(locale_conf_fp);
        puts("\033[0m[\033[31mError\033[0m]Locale config file not detected,loaded default setting");
        return "en-us";
    }
    #elif defined(_WIN32)||defined(_WIN64)
    if((locale_conf_fp=fopen("locale.bin","r"))==NULL)
    {
        fclose(locale_conf_fp);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf("[");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        printf("Error");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        puts("]Locale config file not detected,loaded default setting");
        return "en-us";
    }
    #endif
    fseek(locale_conf_fp,0L,SEEK_END);
    if(ftell(locale_conf_fp)!=4)
    {
        #ifdef __linux
        puts("\033[0m[\033[31mError\033[0m]Locale config file damaged,please reinstall Objective Shell or fix it");
        puts("[\033[94mNote\033[0m]Loaded default setting");
        #elif defined(_WIN32)||defined(_WIN64)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf("[");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        printf("Error");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        puts("]Locale config file damaged,please reinstall Objective Shell or fix it");
        printf("[");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE|FOREGROUND_INTENSITY);
        printf("Note");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        puts("]Loaded default setting");
        #endif
        fclose(locale_conf_fp);
        return "en-us";
    }
    char ret_buffer[6];
    fread(&ret_buffer,5,1,locale_conf_fp);
    fclose(locale_conf_fp);
    if(ret_buffer=="en-us"||\
        ret_buffer=="zh-cn"||\
        ret_buffer=="zh-hk"||\
        ret_buffer=="zh-tw"||\
        ret_buffer=="zh-mo"||\
        ret_buffer=="en-hk")
    return ret_buffer;
    else
    {
        #ifdef __linux
        puts("\033[30m[\033[31mError\033[0m]Invalid locale config,loaded default setting");
        #elif defined(_WIN32)||defined(_WIN64)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        printf("[");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);
        printf("Error");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        puts("]Invalid locale config,loaded default setting");
        #endif
        return "en-us";
    }
}
#endif