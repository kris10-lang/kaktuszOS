bits 32
org 0x20000
start:
mov ah, 0x0e
mov al, 'L'
mov [0xb8000+(80*2)], ax
ret
