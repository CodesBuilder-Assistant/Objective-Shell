#ifndef DIR_HPP
#define DIR_HPP
#ifdef __linux
#include <sys/io.h>
#elif defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#endif
#include <wchar.h>
#include <stdio.h>
#include <memory.h>
#include <string>
using namespace std;
void dir(wchar_t *search_file_name)
{
    #ifdef __linux
    #elif defined(_WIN32)||defined(_WIN64)
    WIN32_FIND_DATAW finddata;
    HANDLE finddata_handle;
    if((finddata_handle=FindFirstFileW(search_file_name,&finddata))==INVALID_HANDLE_VALUE)
        return;
    wstring last_filename;
    bool thisdir=false;
    while(last_filename!=finddata.cFileName)
    {
        int file_attrib=GetFileAttributesW(finddata.cFileName);
        if(!thisdir)
        {
            thisdir=true;
            continue;
        }
        else if(file_attrib==FILE_ATTRIBUTE_DIRECTORY)
            printf("[DIR]");
        else
            printf("[FILE]");
        wprintf(finddata.cFileName);
        puts("");
        last_filename=finddata.cFileName;
        FindNextFileW(finddata_handle,&finddata);
    }
    #endif
}
#endif