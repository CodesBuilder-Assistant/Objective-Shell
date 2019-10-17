data segment
MARK_OF_GENUINE db '...OBJSHELLCOREDOS...','$'
user_input db 512 dup (0)
data ends

stack segment
db 8192 dup (0)
stack ends

code segment
assume cs:code,ds:data,ss:stack

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

;function name:exit
;arguments:none
exit:
    mov ah,4ch
    int 21h

;function name:reboot
;arguments:none
reboot:
    int 19h

;function name:clear_user_input_buffer
;arguments:none
clear_user_input_buffer:
    push di
    push bx
    lea di,user_input
    lea bx,user_input
    add bx,512
    init_user_input_buffer:
    mov byte ptr [di],'$'
    inc di
    cmp di,bx
    jne init_user_input_buffer
    pop bx
    pop di
    ret

;function name:init
;arguments:none
init:
    call clear_user_input_buffer
    xor ax,ax
    xor bx,bx
    xor cx,cx
    xor dx,dx
    xor si,si
    xor di,di
    ret

;main function
main:
    call init

    call exit
code ends
end main