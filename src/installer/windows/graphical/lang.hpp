#ifndef LANG_HPP
#define LANG_HPP
#include <Windows.h>
class language_config final
{
    private:

    public:
        LPWSTR installer_title;
        LPWSTR for_testing_purposes_only;
        LPWSTR select_install_path;
        LPWSTR install_path;
        LPWSTR install_button;
        language_config(void)
        {
            this->installer_title=NULL;
            this->for_testing_purposes_only=NULL;
            this->select_install_path=NULL;
            this->install_path=NULL;
            this->install_button;
        }
        language_config(unsigned int count,...)
        {
            va_list arglist;
        }
};
#endif