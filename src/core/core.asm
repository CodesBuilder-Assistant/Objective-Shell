data segment
MARK_OF_GENUINE db '...OBJSHELLCOREDOS...','$'
user_input db 8193 dup (0)
data ends
code segment
assume cs:code,ds:data

;function name:print
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

;function name:reboot
;arguments:none
reboot:
    int 19h

;function name:clear_user_input_buffer
;arguments:none
clear_user_input_buffer:
    push ax
    push bx
    mov ax,offset user_input
    mov bx,offset user_input
    add bx,8191
    init_user_input_buffer:
    mov [ax],'0'
    cmp ax,bx
    inc ax
    jne init_user_input_buffer
    mov [ax],'$'
    pop bx
    pop ax
    ret

;function name:init
;arguments:none
init:
    call clear_user_input_buffer
    xor ax,ax
    xor bx,bx
    xor cx,cx
    xor dx,dx
    ret

;main function
main:
    call init
code ends
end main