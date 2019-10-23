data segment
startup_info db 'Objective Shell',0dh,0ah,'Copyright(C)2019 CodesBuilder','$'
interrupt_disabled db 0
user_input db 512 dup (0)
data ends

stack segment
db 8192 dup (0)
stack ends

code segment
assume cs:code,ds:data,ss:stack

;function name:print
;arguments:
;bx:string start address
print:
    push dx
    push ah
    mov ah,09h
    mov dx,bx
    int 21h
    pop ah
    pop dx
    ret

;function name:putchar
;arguments:
;al:character
putchar:
    push dl
    push ah
    mov dl,al
    mov ah,02h
    int 21h
    pop ah
    pop dl
    ret

;function name:disable_int
;arguments:none
disable_int:
    cli
    mov interrupt_disabled,1
    ret

;function name:enable_int
;arguments:none
enable_int:
    sti
    mov interrupt_disabled,0
    ret

;function name:next_line
;arguments:none
next_line:
    mov 
    ret

;function name:exit
;arguments:none
exit:
    mov ah,4ch
    sti
    int 21h

;function name:reboot
;arguments:none
reboot:
    sti
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
    sti
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
    mov bx,offset startup_info
    call print
    
    call exit
code ends
end main
