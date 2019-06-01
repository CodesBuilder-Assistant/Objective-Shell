#ifndef VAR_HPP
#define VAR_HPP
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
                    if(initial_value<-2147483648)
                        this->data=reinterpret_cast<long long>(initial_value);
                    else
                        this->data=initial_value;
                case short:
                    if(initial_value<-32767)
                        if()
            }
        }
};
#endif