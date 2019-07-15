#ifndef FINDFILE_HPP
#define FINDFILE_HPP
#include <vector>
#include <string>
#include <wchar.h>
#ifdef __linux
#include <boost/filesystem.hpp>
#elif defined(_WIN32)||defined(_WIN64)
#include <Windows.h>
#endif

#define FILE_LIST 0
#define DIRECTORY_LIST 1

class file_list
{
    private:
        std::vector<wchar_t *>files;
        std::vector<wchar_t *>directories;
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
            std::wstring last_filename;
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
            boost::filesystem::directory_iterator end;
            for(boost::filesystem::directory_iterator _i_;_i_!=end;_i_++)
            {
                boost::filesystem::path file_name=_i_->path().extension();
                wstring tmp_wfilename="a";
                for(int i=findname.size();i>=0;i--)
                    for(int j=i;j<i;)
                    {
                        
                    }
                boost::filesystem::path find_name=;
                boost::filesystem::extension()
            }
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
        std::vector<wchar_t *> filelist(void)
        {
            return this->files;
        }
        std::vector<wchar_t *> dirlist(void)
        {
            return this->directories;
        }
        wchar_t *get_filename(unsigned int unit_number)
        {
            if(unit_number>=this->files.size())
                return L'\0';
            return this->files[unit_number];
        }
        wchar_t *get_dirname(unsigned int unit_number)
        {
            if(unit_number>=this->directories.size())
                return L'\0';
            return this->directories[unit_number];
        }
        unsigned int file_count(void)
        {
            return this->files.size();
        }
        unsigned int dir_count(void)
        {
            return this->directories.size();
        }
};
#endif