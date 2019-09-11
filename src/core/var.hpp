#ifndef VAR_HPP
#define VAR_HPP
#include <list>
#include <wchar.h>
using std::list;
template<class var_type>class var
{
    private:
        var_type data;
        wchar_t *name;
        friend var<void *> findvar(wchar_t *var_name);
        var(void)
        {
        }
    public:
        var(wchar_t *var_name)
        {
            wcscpy(this->name,var_name);
            this->data=0;
        }
        var(wchar_t *var_name,var_type initial_data)
        {
            wcscpy(this->name.var_name);
            this->data=initial_data;
        }
        var operator =(var_type _data)
        {
            var tmpvar;
            tmpvar.data=_data;
            wcscpy(tmpvar.name,this->name);
            return tmpvar;
        }
        var operator =(var<var_type> var_obj)
        {
            var tmpvar;
            tmpvar.data=var_obj.data;
            wcscpy(tmpvar.name,this->name);
            return tmpvar;
        }
};
list<var<signed char>>sbyte_vars;
list<var<unsigned char>>byte_vars;
list<var<short>>sword_vars;
list<var<unsigned short>>word_vars;
list<var<int>>sdword_vars;
list<var<unsigned int>>dword_vars;
list<var<long long>>sqword_vars;
list<var<unsigned long long>>qword_vars;
var<void *>* findvar(wchar_t *var_name)
{
    list<var<signed char>>::iterator sbyte_itor;
    for(sbyte_itor=sbyte_vars.begin();sbyte_itor!=sbyte_vars.end();sbyte_itor++)
        if(wcscmp(sbyte_itor->name,var_name)==0)
        {

        }
}
#endif