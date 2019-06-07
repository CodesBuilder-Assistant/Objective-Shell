#ifndef VAR_HPP
#define VAR_HPP
#include <list>
using namespace std;
template<class var_type>class var
{
    private:
        var_type data;
        bool _auto;
    public:
        var(void)
        {
            this->data=(var_type)0;
            this->_auto=true;
        }
};
list<var<void *>>var_list;
#endif