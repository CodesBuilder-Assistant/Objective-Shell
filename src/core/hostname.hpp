#ifndef HOSTNAME_HPP
#define HOSTNAME_HPP
#ifdef _WIN32
#include <Windows.h>
#endif
const wchar_t *GetLocalHostName(void)
{
    #ifdef _WIN32
    wchar_t localhost_name[256];
    DWORD buffer_size=255;
    GetComputerNameW(localhost_name,&buffer_size);
    return localhost_name;
    #endif
}
#endif