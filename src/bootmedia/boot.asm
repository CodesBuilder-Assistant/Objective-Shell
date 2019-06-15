  org 07c00h
  
  mov ax,cs
  mov ds,ax
  mov es,ax
  
  ;push ax
  ;mov ah,07h
  ;mov al,0
  ;mov bh,0
  ;int 10h
  
  times 512-($-$$) db 0
  
  db 0x55,0xaa
