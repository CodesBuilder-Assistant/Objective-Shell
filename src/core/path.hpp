#ifndef PATH_HPP
#define PATH_HPP
#include <list>
#include <stdarg.h>
using std::list;
class path
{
    private:
        list<wchar_t *>paths;
    public:
        path(void)
        {
        }
        path(unsigned int path_count,...)
        {
            va_list args;
            for(unsigned int i=0;i<path_count;i++)
            {
                va_start(args,path_count);
                this->paths.push_back(va_arg(args,wchar_t *));
            }
            va_end(args);
        }
        void add(wchar_t *push_path)
        {
            this->paths.push_back(push_path);
        }
        void push_back(wchar_t *push_path)
        {
            this->paths.push_back(push_path);
        }
};
#endif