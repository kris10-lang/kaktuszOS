bits 32
org 0x20000

vga_memory      equ 0xb8000
character       equ 'A'
MIN_VGA         equ 0
MAX_VGA         equ 1999
KB_STATUS_PORT  equ 0x64
KB_DATA_PORT    equ 0x60
D_SCANCODE      equ 0x20
A_SCANCODE      equ 0x1E
ENTER_SCANCODE  equ 0x1C

start:
    mov edi, 1
    mov esi, MIN_VGA
    mov ah, 0x0e
    mov al, character
    mov [vga_memory+(esi*2)], ax

loop:
    call handle_input
    cmp edi, 0
    je done
    jmp loop

; ------------------ BILLENTYŰ KEZELÉS ------------------------
handle_input:
    in al, KB_STATUS_PORT
    test al, 0x01
    jz .exit_handle 
    in al, KB_DATA_PORT
    test al, 0x80
    jnz .exit_handle
        
    cmp al, ENTER_SCANCODE
    je set_pointer

    cmp al, D_SCANCODE
    je call_mov_right
    cmp al, A_SCANCODE
    je call_mov_left
    
.exit_handle:
    ret 

set_pointer:
    mov edi, 0
    ret

; ------------------ JÁTÉKOS MOZGÁSA ---------------------------
call_mov_right:
    call mov_right
    ret

call_mov_left:
    call mov_left
    ret

mov_right:
    mov ah, 0x0e
    mov al, character
    cmp esi, MAX_VGA
    je done
    mov [vga_memory+(esi*2)], word 0x0F20
    inc esi
    mov [vga_memory+(esi*2)], ax
    jmp done
mov_left:
    mov ah, 0x0e
    mov al, character
    cmp esi, MIN_VGA
    je done
    mov [vga_memory+(esi*2)], word 0x0F20
    dec esi
    mov [vga_memory+(esi*2)], ax
    jmp done
done:
    ret