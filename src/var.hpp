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
            this->_unsigned=false;
            this->_auto=true;
        }
        bool var(long long initial_value)
        {
            switch(var_type)
            {
                case int:
                    if(initial_value>2147483648)
                        this->data=reinterpret_cast<long long>(initial_value);
                    else
                        this->data=initial_value;
                case short:
                    if(initial_value>32767)
                        this->data=reinterpret_cast<int>(initial_value);
                    else
                        this->data=initial_value;
                case long long:
                    if(initial_value>=0)
                        if(initial_value<=4294967295)
                            if(initial_value<=65535)
                                if(initial_value<=256)
                                    this->data=reinterpret_cast<unsigned char>((unsigned char)initial_value);
                                else
                                    this->data=reinterpret_cast<unsigned short>((unsigned short)initial_value);
                            else
                                this->data=reinterpret_cast<unsigned int>((unsigned int)initial_value);
                        else
                            this->data=reinterpret_cast<long long>(initial_value);
            }
        }
};
list<var<void *>>var_list;
#endif