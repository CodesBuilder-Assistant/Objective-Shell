#ifndef VAR_HPP
#define VAR_HPP
#include <list>
#include <string>
using namespace std;
class TypeAutoCastNotEnabled
{
};
template<class var_type>class var
{
    private:
        bool auto_cast;
        string var_name;
    public:
        var_type data;
        var(void)
        {
            this->data=(var_type)0;
            this->auto_cast=true;
        }
        var(var_type initial_data)
        {
            this->data=initial_data;
            this->auto_cast=false;
        }
        template<class data_type>var(data_type initial_data)
        {
            this->data=reinterpret_cast<data_type>(initial_data);
            this->auto_cast=true;
        }
        /*
        * Range of values:
        * int:–2147483648-4294967295
        * short:–32768-65535
        * long:–9223372036854775808-18446744073709551615
        * byte:-128-256
        * boolean:0-1
        * var:auto
        */
        template<class data_type>var operator =(data_type value)
        {
            var<int> tmp_class;
            tmp_class.auto_cast=this->auto_cast;
            tmp_class.data=this->data;
            tmp_class.var_name=this->name;
            if(!tmp_class.auto_cast)
            {
                tmp_class.data_type=(typeid(this->data_type)value);
                return tmp_class;
            }
            if(value>INT_MAX)
            {
                if(value>INT64_MAX)
                    tmp_class->data=reinterpret_cast<unsigned long long>((unsigned long long)value)
                else
                    tmp_class->data=reinterpret_cast<long long>((long long)value);
            }
            else if(value>INT16_MAX)
            {
                if(value>INT16_MAX*2+1)
                    tmp_class=reinterpret_cast<int>((int)value);
                else
                    tmp_class=reinterpret_cast<unsigned short>((unsigned short)value);
            }
            else if(value>INT8_MAX)
            {
                if(value>INT8_MAX*2+1)
                    tmp_class=reinterpret_cast<short>((short)value);
                else
                    tmp_class=reinterpret_cast<unsigned char>((unsigned char)value);
            }
            else if(value>1)
                tmp_class=reinterpret_cast<char>((char)value);
            else
                tmp_class=reinterpret_cast<bool>(value);
            return tmp_class;
        }
};
list<var<void *>>var_list;
#endif