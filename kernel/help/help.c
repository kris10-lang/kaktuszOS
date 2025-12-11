void help(void) {
    kclearscreen();
    kprint("+----------------------------------+",0x0F00,vga);
    kprint("|logo-to see the logo              |",0x0F00,vga+80);
    kprint("|calc-to use calculator            |",0x0F00,vga+160);
    kprint("|read-to read the content of files |",0x0F00,vga+240);
    kprint("|dir -to see what files do you have|",0x0F00,vga+320);
    kprint("|make-to create a new file         |",0x0F00,vga+400);
    kprint("|del -to delete a file             |",0x0F00,vga+480);
    kprint("|prog-to write a program(use hex)  |",0x0F00,vga+560);
    kprint("|edit-to edit existing files       |",0x0F00,vga+640);
    kprint("|run -to run programs              |",0x0F00,vga+720);
    kprint("|copy-to copy a file               |",0x0F00,vga+800);
    kprint("|name-to rename a file             |",0x0F00,vga+880);
    kprint("|help-to see this                  |",0x0F00,vga+960);
    kprint("+----------------------------------+",0x0F00,vga+1040);
    kpause();
}