ENTRY(hello)
SECTIONS {
  . = 0x20000;   /* vagy ahova akarod tölteni */
  .text : { *(.text) }
  .data : { *(.data) }
  .bss  : { *(.bss)  }
}
