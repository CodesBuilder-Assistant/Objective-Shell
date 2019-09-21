#ifndef FS_HPP
#define FS_HPP
#ifdef _WIN32
#include <Windows.h>
#endif
#include <string>
using std::string;
using std::wstring;

bool IsDirectory(const wchar_t *_path_)
{
    #ifdef _WIN32
    wstring find_name=_path_;
    if(find_name[find_name.length()-2]==L'\\'||find_name[find_name.length()-2]==L'/')
        find_name+=L'*';
    else
        find_name+=L'\\*';
    _WIN32_FIND_DATAW finddata;
    HANDLE find_handle;
    find_handle=FindFirstFileW(find_name.c_str(),&finddata);
    if(find_handle==INVALID_HANDLE_VALUE)
    {
        CloseHandle(find_handle);
        return false;
    }
    CloseHandle(find_handle);
    #endif
    return true;
}

#endif