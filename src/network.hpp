#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <stdio.h>
#include <wchar.h>
#include <string>
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#elif defined(__linux)
#endif
using namespace std;
enum url_licenses
{
    UL_HTTP=0X0b,
    UL_FTP
};
unsigned short GetLinkLicenseType(wchar_t *target_url)
{
    wstring license_name;
    for(register int i=0;i<wcslen(target_url)&&target_url[i]!=':';i++)
        license_name+=target_url[i];
    if(license_name==L"http"||license_name==L"https")
        return UL_HTTP;
    else if(license_name==L"ftp")
        return UL_FTP;
}
enum network_error_code
{
    ERROR_LICENSE=0x15,
    CANNOT_CONNECT
};
unsigned short DownloadFile(wchar_t *filename,wchar_t *file_url)
{
    #ifdef __linux
    #elif defined(_WIN32)||defined(_WIN64)
    WSADATA wsadat_struct;
    WSAStartup(MAKEWORD(2,2),&wsadat_struct);
    switch(GetLinkLicenseType(file_url))
    {
        case UL_HTTP:
            SOCKET DownloadSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
            break;
        case UL_FTP:
            SOCKET DownloadSocket=socket(AF_INET,SOCK_STREAM,IPPORT_FTP);
            break;
        default:
            return ERROR_LICENSE;
    }
    WSACleanup();
    #endif
}
#endif