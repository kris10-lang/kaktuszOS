section .note.GNU-stack note

[BITS 32]
global start
extern kmain

; Defináljuk a GDT szegmens választókat (a GDT-d alapján)
; Általában: 0x08 a kód, 0x10 az adat
DATA_SEG equ 0x10 

section .text
start:
    ; 1. Megszakítások tiltása (ÉLETMENTŐ!)
    cli

    ; 2. Szegmens regiszterek inicializálása
    ; Ezt QEMU megcsinálja helyetted, de a valós vas NEM!
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; 3. Verem beállítása
    mov esp, stack_top

    ; 4. Opcionális: A20 vonal ellenőrzése itt is megtörténhet, 
    ; de tegyük fel, hogy a bootloadered megoldotta.

    call kmain

hang:
    hlt          ; Alacsonyabb fogyasztás, mint a jmp hang
    jmp hang

section .bss
align 16         ; A stack legyen 16 bájtos határon (C ABI elvárás)
resb 16384       ; 4KB kevés lehet, legyen inkább 16KB
stack_top: