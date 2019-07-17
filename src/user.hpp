#ifndef USER_HPP
#define USER_HPP
#ifdef __linux
#elif defined(_WIN32)||defined(_Win64)
#include <Windows.h>
#endif
#ifdef __linux
char *GetUserName(void)
#elif defined(_WIN32)||defined(_WIN64)
wchar_t *GetUserName(void)
#endif
{
    #ifdef __linux
    char ret_username[256];
    #elif defined(_WIN32)||defined(_WIN64)
    wchar_t ret_username[256];
    DWORD unbuffer_max=255;
    GetUserNameW(ret_username,&unbuffer_max);
    #endif
    return ret_username;
}
#endif