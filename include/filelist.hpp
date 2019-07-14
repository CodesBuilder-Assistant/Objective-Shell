#ifndef FINDFILE_HPP
#define FINDFILE_HPP
#include <vector>
#include <string>
#ifdef __linux
#include <boost/filesystem.hpp>
#elif defined(_WIN32)||defined(_WIN64)
#include <Windows.h>
#endif
using namespace std;
class file_list
{
    private:
        vector<wchar_t *>files;
        vector<wchar_t *>directories;
    public:
        file_list(void)
        {
        }
        file_list(wchar_t *findname)
        {
            #if defined(_WIN32)||defined(_WIN64)
            WIN32_FIND_DATAW finddata;
            HANDLE find_handle=FindFirstFile(findname,&finddata);
            if(find_handle==INVALID_HANDLE_VALUE)
                return;
            //Skip the useless file name.
            FindNextFileW(find_handle,&finddata);
            wstring last_filename;
            while(finddata.cFileName!=last_filename.c_str())
            {
                int file_attrib=GetFileAttributesW(finddata.cFileName);
                if(file_attrib==FILE_ATTRIBUTE_DIRECTORY)
                    this->directories.push_back(finddata.cFileName);
                else
                    this->files.push_back(finddata.cFileName);
                last_filename=finddata.cFileName;
                FindNextFileW(find_handle,&finddata);
            }
            #elif defined(__linux__)
            #endif
        }
        void refresh(wchar_t *findname,bool clear)
        {
            if(clear)
            {
                this->files.clear();
                this->directories.clear();
            }
            #if defined(_WIN32)||defined(_WIN64)
            WIN32_FIND_DATAW finddata;
            HANDLE find_handle=FindFirstFile(findname,&finddata);
            if(find_handle==INVALID_HANDLE_VALUE)
                return;
            //Skip last directory.
            FindNextFileW(find_handle,&finddata);
            wstring last_filename;
            while(finddata.cFileName!=last_filename.c_str())
            {
                int file_attrib=GetFileAttributesW(finddata.cFileName);
                if(file_attrib==FILE_ATTRIBUTE_DIRECTORY)
                    this->directories.push_back(finddata.cFileName);
                else
                    this->files.push_back(finddata.cFileName);
                last_filename=finddata.cFileName;
                FindNextFileW(find_handle,&finddata);
            }
            CloseHandle(find_handle);
            #elif defined(__linux__)
            #endif
        }
        void refresh(wchar_t *findname)
        {
            this->refresh(findname,true);
        }
        void clear(void)
        {
            this->files.clear();
            this->directories.clear();
        }
        void attach(wchar_t *findname)
        {
            this->refresh(findname,false);
        }
        void find(wchar_t *findname)
        {
            this->refresh(findname);
        }
        bool empty(bool target)
        {
            if(target)
                if(this->directories.empty())
                    return true;
                else
                    return false;
            if(this->files.empty())
                return true;
            else
                return false;
        }
};
#endif