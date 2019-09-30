#ifndef DIR_HPP
#define DIR_HPP
#ifdef _WIN32
#include <Windows.h>
#endif
#include <wchar.h>
#include <string>
using std::wstring;
void dir(const wchar_t *ls_dir)
{
    #ifdef _WIN32
    wchar_t *original_dir=new wchar_t[16384];
    GetCurrentDirectoryW(16384,original_dir);
    SetCurrentDirectoryW(ls_dir);
    WIN32_FIND_DATAW finddata;
    HANDLE find_handle;
    //Ignore useless file name.
    find_handle=FindFirstFileW(L"*",&finddata);
    if(find_handle==INVALID_HANDLE_VALUE)
        return;
    FindNextFileW(find_handle,&finddata);
    wstring last_file_name;
    while(true)
    {
        wprintf(L"%ls\n",finddata.cFileName);
        last_file_name=finddata.cFileName;
        FindNextFileW(find_handle,&finddata);
        if(last_file_name==finddata.cFileName)
            break;
    }
    SetCurrentDirectoryW(original_dir);
    delete[] original_dir;
    #endif
}
#endif