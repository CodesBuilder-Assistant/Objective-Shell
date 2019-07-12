#ifndef REGISTER_HPP
#define REGISTER_HPP
enum reg_id
{
    EAX=51,
    EBX,
    ECX,
    EDX,
    AX,
    BX,
    CX,
    DX,
    AH,
    AL,
    BH,
    BL,
    CH,
    CL,
    DH,
    DL,
    RAX,
    RBX,
    RCX,
    RDX,
    R5,
    R6,
    R7,
    R8,
    R9,
    R10,
    R11,
    R12,
    R13,
    R14,
    R15
};
unsigned int _eax,_ebx,_ecx,_edx;
unsigned short _ax,_bx,_cx,_dx;
unsigned char _ah,_al,_bh,_bl,_ch,_cl,_dh,_dl;
void __fastcall regset_32bit(unsigned int data,unsigned short reg_id)
{
    switch(reg_id)
    {
        case EAX:

    }
}
#endif