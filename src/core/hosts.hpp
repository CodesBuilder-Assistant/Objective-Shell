#ifndef HOSTS_HPP
#define HOSTS_HPP
#ifdef __linux
#elif defined(_WIN32)
#include <Windows.h>
#endif
#ifdef __linux
char *GetLocalHostName(void)
#elif defined(_WIN32)
wchar_t *GetLocalHostName(void)
#endif
{
    #ifdef __linux
    #elif defined(_WIN32)
    wchar_t local_hostname[256];
    DWORD lhbuffer_max=255;
    GetComputerNameW(local_hostname,&lhbuffer_max);
    #endif
    return local_hostname;
}
#endif