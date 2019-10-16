data segment
MARK_OF_GENUINE db '...OBJSHELLCOREDOS...','$'
data ends
code segment
assume cs:code,ds:data
;function:print
;arguments:
;bx - string address
print:
    push ds
    push ax
    mov ax,data
    mov ds,ax
    mov ah,09h
    push dx
    mov dx,bx
    int 21h
    pop dx
    pop ax
    pop ds
    ret
reboot:
    int 19h
main:
code ends
end main