#ifndef PORT_HPP
#define PORT_HPP
#if defined(_WIN32)||defined(_WIN64)
#include <windows.h>
#elif defined(__linux__)
#include
#endif
class port
{
    private:
        int port_number;
        int original_data;
        bool mapped;
    public:
        port(void)
        {
            this->port_number=-1;
            this->original_data=0;
            this->mapped=false;
        }
        port(unsigned int port_number_)
        {
            this->port_number=reinterpret_cast<unsigned int>(port_number_);
            this->original_data=0;
            this->mapped=false;
        }
        port(unsigned int port_number_,int initial_data)
        {
            this->port_number=reinterpret_cast<unsigned int>(port_number_);
            this->out(initial_data);
            this->original_data=0;
            this->mapped=false;
        }
        int in(void)
        {
            if(this->port_number==-1)
                return -1;
        }
        void out(int out_data)
        {
            if(this->port_number==-1)
                return;
        }
        bool mapping(int mapping_data)
        {
            if(this->port_number==-1)
                return false;
            this->original_data=this->in();
            this->out(mapping_data);
        }
        bool unmapping(void)
        {
            if(this->port_number==-1||!this->mapped)
                return false;
            this->out(this->original_data);
            this->mapped=false;
        }
};
#endif