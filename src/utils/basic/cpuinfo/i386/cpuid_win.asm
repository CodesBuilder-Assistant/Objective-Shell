; cpuid_win.asm:
; Copyright(C)2019 CodesBuilder
;
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License version 3 as
; published by the Free Software Foundation.

GetCpuid:
    push eax
    push ebx
    push ecx
    push edx
    xor eax,eax
    cpuid
    pop eax
    pop ebx
    pop ecx
    pop edx
    ret