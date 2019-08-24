#ifndef DIR_HPP
#define DIR_HPP
#ifdef __linux__
#include <sys/io.h>
#elif defined(_WIN32)
#include <Windows.h>
#endif
#include <wchar.h>
#include <stdio.h>
#include <memory.h>
#include <string>
using namespace std;
void dir(const wchar_t *search_file_name)
{
    #if defined(_WIN32)
    WIN32_FIND_DATAW finddata;
    HANDLE finddata_handle;
    if((finddata_handle=FindFirstFileW(search_file_name,&finddata))==INVALID_HANDLE_VALUE)
    {
        puts("File not found");
        return;
    }
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
    #elif defined(__linux__)

    #endif
}
#endif