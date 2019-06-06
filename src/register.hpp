#ifndef REGISTER_HPP
#define REGISTER_HPP
#include <thread>
using namespace std;
//32-bit virtual registers.
unsigned int _eax,_ebx,_ecx,_edx,_esi,_edi,_eflags;
//16-bit virtual registers.
unsigned short _ax,_bx,_cx,_dx,_si,_di,_flags;
//8-bit virtual registers.
unsigned char _ah,_al,_bh,_bl,_ch,_cl,_dh,_dl;
void RegisterUpdateThread(void)
{
    asm volatile("push eax");
    asm volatile("mov eax,_eax");
    asm volatile("bswap eax");
    asm volatile("mov _ax,ax");
    
}
#endif