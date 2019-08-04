#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP
#include <memory.h>
class cannot_find_data
{
};
template<class T>class d_array
{
    private:
        int unit_count;
        T *array;
        T *tmp;
        T init;
        int last_find;
        bool have_init_data;
    public:
        d_array(void) noexcept
        {
            this->last_find=-1;
            this->have_init_data=false;
            this->unit_count=0;
        }
        d_array(int _unit_count_)
        {
            this->array=new T[_unit_count_];
            this->unit_count=_unit_count_;
            this->last_find=-1;
            this->have_init_data=false;
        }
        d_array(T init_data) noexcept
        {
            this->init=init_data;
            this->last_find=-1;
            this->have_init_data=true;
            this->unit_count=0;
        }
        d_array(int _unit_count_,T init_data)
        {
            this->array=new T[_unit_count_];
            this->unit_count=_unit_count_;
            this->init=init_data;
            for(register int i=0;i<_unit_count_)
                this->array[i]=init_data;
        }
        void push(T _data_)
        {
            this->tmp=new T[this->unit_count];
            memcpy(this->array,this->tmp,sizeof(T)*unit_count);
            delete[] this->array;
            this->unit_count++;
            this->array=new T[this->unit_count];
            memcpy(tmp,array,sizeof(T)*(this->unit_count-1));
            delete[] this->tmp;
            this->array[unit_count]=_data_;
        }
        void pop(T _data_)
        {
            this->tmp=new T[this->unit_count-1];
            memcpy(this->array,this->tmp,(this->unit_count-1)*sizeof(T));
            delete[] this->array;
            this->unit_count--;
            this->array=new T[this->unit_count];
            memcpy(this->tmp,this->array,this->unit_count)
        }
        int find(const T _find_) noexcept
        {
            for(register int i=0;i<unit_count)
                if(_find_==this->array[i])
                    return i;
            throw cannot_find_data();
        }
        void destroy(void) noexcept
        {
            delete this;
        }
        ~d_array(void) noexcept
        {
            delete[] this->array;
        }
};
#endif