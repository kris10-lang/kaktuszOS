ENTRY(start)

SECTIONS
{
    . = 0x0;  /* A kernel kezdő címe */

    .text : { *(.text*) }
    .rodata : { *(.rodata*) }
    .data : { *(.data*) }
    .bss : {
        *(.bss*)
        *(COMMON)
    }
}
