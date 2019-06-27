#ifndef CPU_HPP
#define CPU_HPP
#include "asmarg.hpp"
#include <memory.h>
int cpuid_ebx,cpuid_ecx,cpuid_edx;
char *cpuid(void)
{
    char return_buffer[13];
    unsigned short return_buffer_next_ptr=4;
    asm volatile(".intel_syntax noprefix");
    asm volatile("push eax");
    asm volatile("push ebx");
    asm volatile("push ecx");
    asm volatile("push edx");
    asm volatile("xor eax,eax");
    asm volatile("cpuid");
    asm volatile("mov cpuid_ebx,ebx");
    asm volatile("mov cpuid_ecx,ecx");
    asm volatile("mov cpuid_edx,edx");
    memcpy(return_buffer,&cpuid_ebx,4);
    memcpy(return_buffer+return_buffer_next_ptr,&cpuid_edx,4);
    return_buffer_next_ptr+=4;
    memcpy(return_buffer+return_buffer_next_ptr,&cpuid_ecx,4);
    return return_buffer;
}
#endif