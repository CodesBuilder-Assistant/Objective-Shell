#ifndef ALERT_HPP
#define ALERT_HPP
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#elif defined(__linux)
#include <wchar.h>
#endif
enum alert_type
{
    ALERT_INFO=11,
    ALERT_ERROR,
    ALERT_WARNING,
    ALERT_NORMAL
};
void alert(wchar_t *alert_message,wchar_t *alert_title,char alert_type)
{
    #if defined(_WIN32)||defined(_WIN64)
    switch(alert_type)
    {
        case ALERT_INFO:
            MessageBoxW(NULL,alert_title,alert_message,MB_OK|MB_ICONINFORMATION);
            break;
        case ALERT_ERROR:
            MessageBoxW(NULL,alert_title,alert_message,MB_OK|MB_ICONERROR);
            break;
        case ALERT_WARNING:
            MessageBoxW(NULL,alert_title,alert_message,MB_OK|MB_ICONWARNING);
            break;
        default:
            MessageBoxW(NULL,alert_title,alert_message,MB_OK);
            break;
    }
    #elif defined(__linux)
    printf("\033[107;2;37m");

    for(int i=0;i<wcslen(alert_message)+2;i++)
    #endif
}
#endif