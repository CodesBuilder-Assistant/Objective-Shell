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
void alert(const wchar_t *alert_message,const wchar_t *alert_title)
{
    #if defined(_WIN32)||defined(_WIN64)
    MessageBoxW(NULL,alert_message,alert_title,MB_OKC|MB_ICONINFORMATION);
    #elif defined(__linux)
    #endif
}
#endif