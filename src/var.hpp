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
        frined var::operator =;
        var_type data;
        bool auto_cast;
        string var_name;
    public:
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
        template<class data_type>void operator =(data_type target_data)
        {
            if(!this->auto_cast)
            {
                throw TypeAutoCastNotEnabled();
                return;
            }
            this->data=reinterpret_cast<data_type>(target_data);
        }
        template<class data_type>void operator =(var<data_type> target_data)
        {
            if(this->auto_cast)
            {
                throw TypeAutoCastNotEnabled();
                return;
            }
            this->data=reinterpret_cast<data_type>(target_data.data);
        }
        template<class data_type>void operator >(data_type target_data)
        {

        }
};
template<class data_type>class env_var
{
    private:
        data_type *datas;
        unsigned short data_length;
    public:
        env_var(void)
        {
            this->datas=new data_type[1];
            this->datas[0]=NULL;
            this->data_length++;
        }
};
list<var<void *>>var_list;
#endif