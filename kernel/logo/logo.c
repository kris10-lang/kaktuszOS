void logo(void) {
    kclearscreen();
    kprint("   __    __ ",0x0A00,vga);
    kprint("  |  |  |  |",0x0A00,vga+80);
    kprint("  |  |  |  |",0x0A00,vga+160);
    kprint("__|  |  |  |",0x0A00,vga+240);
    kprint("|__  |  |  |",0x0A00,vga+320);
    kprint("  |  |  |  |",0x0A00,vga+400);
    kprint("  |  |  |  |",0x0E00,vga+480);
    kprint("  |__|  |__|",0x0E00,vga+560);
    kpause();
}