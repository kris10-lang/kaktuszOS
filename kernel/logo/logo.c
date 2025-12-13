void logo(void) {
    kclearscreen();
    kprint("   __    __ ",0x0A00,vga);
    kprint("  |  |  |  |",0x0A00,vga+40);
    kprint("  |  |  |  |",0x0A00,vga+80);
    kprint("__|  |  |  |",0x0A00,vga+120);
    kprint("|__  |  |  |",0x0A00,vga+160);
    kprint("  |  |  |  |",0x0A00,vga+200);
    kprint("  |  |  |  |",0x0E00,vga+240);
    kprint("  |__|  |__|",0x0E00,vga+280);
    kpause();
}