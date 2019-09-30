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
    if(GetFileAttributesW(_path_)!=FILE_ATTRIBUTE_DIRECTORY)
        return false;
    #endif
    return true;
}

#endif