void shell(void) {
    kclearscreen();
    volatile unsigned short* current_vga_addr = vga; // A kiindulási VGA cím
    unsigned color = 0x9F00; // Fehér-magenta
    int total_spaces = 40 * 25; // 1000 szóköz
    for (int i = 0; i < total_spaces; i++) {
        kputchar(' ', color, current_vga_addr);
        // Lépjünk a következő karakter helyére
        current_vga_addr++; 
    }
    //
    kprint("**** COMMODORE 64 BASIC V1 ****",color,vga+4);
    kprint("64K RAM SYSTEM 38911 BASIC BYTES FREE",color,vga+81);
    kprint("READY.",color,vga+160);
    kpause();
}