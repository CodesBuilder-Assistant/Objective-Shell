#ifndef SHUTDOWN_HPP
#define SHUTDOWN_HPP
#ifdef _WIN32
#include <Windows.h>
#endif
#include <stdlib.h>
#include <string>
using std::wstring;
void shutdown(void)
{
    #ifdef _WIN32
    wchar_t *windir=new wchar_t[256];
    GetSystemDirectoryW(windir,256);
    wstring exec_command=windir;
    delete[] windir;
    exec_command+=L"\\shutdown.exe -s -t 0";
    _wsystem(exec_command.c_str());
    #endif
}
void reboot(void)
{
    #ifdef _WIN32
    wchar_t *windir=new wchar_t[256];
    GetSystemDirectoryW(windir,256);
    wstring exec_command=windir;
    delete[] windir;
    exec_command+=L"\\shutdown.exe -r -t 0";
    _wsystem(exec_command.c_str());
    #endif
}
#endif