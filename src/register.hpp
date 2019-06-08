#ifndef REGISTER_HPP
#define REGISTER_HPP
using namespace std;
//32-bit virtual registers.
unsigned int _eax,_ebx,_ecx,_edx,_esi,_edi,_eflags;
//16-bit virtual registers.
unsigned short _ax,_bx,_cx,_dx,_si,_di,_flags;
//8-bit virtual registers.
unsigned char _ah,_al,_bh,_bl,_ch,_cl,_dh,_dl;

unsigned int lastreg_original;
enum registers_32bit
{
    EAX=1001,
    EBX,
    ECX,
    EDX,
    ESI,
    EDI,
    EFLAGS
};
enum registers_16bit
{
    AX=651,
    BX,
    CX,
    DX,
    SI,
    DI,
    FLAGS
};
enum registers_8bit
{
    AH=701,
    AL,
    BH,
    BL,
    CH,
    CL,
    DH,
    DL
};
template<class register_type>void RegisterMov(unsigned short reg_id)
{

}
void MappingRegister(unsigned short reg_id,bool cancel_mapping)
{
    switch(reg_id)
    {
        case EAX:
            asm("mov lastreg_original,eax");
            asm("mov eax,_eax");
    }
}
#endif