void shell(void) {
    kclearscreen();
    volatile unsigned short* current_vga_addr = vga;
    unsigned color = 0x9F00;
    int total_spaces = 40 * 25;
    for (int i = 0; i < total_spaces; i++) {
        kputchar(' ', color, current_vga_addr);
        current_vga_addr++; 
    }
    kprint("**** COMMODORE 64 BASIC V2 ****",color,vga+4);
    kprint("KAKTUSZ OS SHELL THAT LOOKS LIKE C 64",color,vga+81);
    kprint("READY.",color,vga+160);
    kpause();
}