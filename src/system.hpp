#ifndef SYSTEM_HPP
#define SYSTEM_HPP
#ifdef __linux
#include <sys/reboot.h>
#include <signal.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
#include <stdlib.h>
void shutdown(void)
{
    #ifdef __linux
    sync();
    reboot(RB_POWER_OFF);
    #elif defined(_WIN32)||defined(_WIN64)
    system("shutdown -s -t 0");
    #endif
}
void reboot(void)
{
    #ifdef __linux
    sync();
    reboot(RB_AUTOBOOT);
    #elif defined(_WIN32)||defined(_WIN64)
    system("shutdown -r -t 0");
    #endif
}
void execute(wchar_t *file_path,wchar_t *arguments)
{
    #if defined(_WIN32)||defined(_WIN64)
    ShellExecuteW(NULL,L"open",file_path,arguments,NULL,SW_NORMAL);
    #elif defined(__linux)
    #endif
}
#ifdef __linux
bool kill(unsigned int proc_id)
#elif defined(_WIN32)||defined(_WIN64)
bool kill(HANDLE proc_handle)
#endif
{
    #ifdef __linux
    #elif defined(_WIN32)||defined(_WIN64)
    if(TerminateProcess(proc_handle,0)==NULL)
        return false;
    #endif
    return true;
}
#endif