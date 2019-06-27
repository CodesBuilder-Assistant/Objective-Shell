#ifndef PORT_HPP
#define PORT_HPP
#include "asmarg.hpp"
short ReadPort(unsigned int port_n,bool read16_bit)
{
    dword_arg=port_n;
    if(read16_bit)
    {
        #ifdef __linux
        asm(".intel_syntax noprefix");
        asm("push ax");
        asm("in ax,dword_arg");
        asm("mov sword_arg,ax");
        asm("pop ax");
        return sword_arg;
        #elif defined(_WIN32)||defined(_WIN64)
        #endif
    }
    else
    {
        #ifdef __linux
        asm(".intel_syntax noprefix");
        asm("push al");
        asm("in al,dword_arg");
        asm("mov sbyte_arg,al");
        asm("pop al");
        return sbyte_arg;
        #elif defined(_WIN32)||defined(_WIN64)
        #endif
    }
}
#endif