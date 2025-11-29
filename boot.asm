BITS 16
ORG 0x7C00

start:
    cli
    xor ax, ax
    mov ds, ax
    mov ss, ax
    mov sp, 0x7C00

    mov [BOOT_DRIVE], dl

; =====================================================================
; Load kernel to 0x00100000 (1 MB)
; =====================================================================
    mov ax, 0x1000         ; ES = 0x1000 → physical = 0x1000 << 4 = 0x10000
    mov es, ax
    xor bx, bx

    mov ah, 02h
    mov al, 1              ; 1 sector kernel
    mov ch, 0
    mov cl, 2              ; sector 2
    mov dh, 0
    mov dl, [BOOT_DRIVE]
    int 13h
    jc disk_error

; =====================================================================
; Enter Protected Mode
; =====================================================================
    lgdt [gdt_desc]

    mov eax, cr0
    or eax, 1
    mov cr0, eax

    jmp 0x08:pm_start

; =====================================================================
; 32-bit mode
; =====================================================================
BITS 32
pm_start:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov ss, ax

    jmp 0x10000            ; jump to kernel

hang:
    hlt
    jmp hang

; =====================================================================
; GDT
; =====================================================================
BITS 16
gdt_start:
    dq 0x0000000000000000
    dq 0x00CF9A000000FFFF
    dq 0x00CF92000000FFFF
gdt_end:

gdt_desc:
    dw gdt_end - gdt_start - 1
    dd gdt_start

BOOT_DRIVE db 0

disk_error:
    mov si, err
    call print
    jmp $

print:
    mov ah, 0x0E
.next:
    lodsb
    test al, al
    jz .done
    int 10h
    jmp .next
.done:
    ret

err db "Disk error!", 0

TIMES 510-($-$$) db 0
DW 0xAA55
