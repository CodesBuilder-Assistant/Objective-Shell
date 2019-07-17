#ifndef CPUID_H
#define CPUID_H
int cpuid_eax,cpuid_ebx,cpuid_ecx,cpuid_edx;
extern int cpuid(void);
#endif