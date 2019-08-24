#ifndef MODULES_HPP
#define MODULES_HPP
#include <stdarg.h>
class installation_scheme
{
    private:
        //bool core;
        bool bootmedia;
        bool lib;
        bool sc;
        bool tools;
        bool docs;
        installation_scheme(void)
        {
        }
    public:
        installation_scheme(...)
        {
            va_list args;
        }
};
#endif