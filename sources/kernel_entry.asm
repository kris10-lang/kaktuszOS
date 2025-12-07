section .note.GNU-stack note

BITS 32
global start
extern kmain

start:
    mov esp, stack_top

    call kmain

hang:
    jmp hang

section .bss
    resb 4096
stack_top: