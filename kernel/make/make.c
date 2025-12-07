void make(void) {
    char content[512];
    char filename[13];
    kpause();
    kinput2(1547, filename, sizeof(filename));
    int valid = 0;
    for (int i = 0; i < sizeof(filename); i++) {
        if (filename[i] == '\0') break;
        if (filename[i] != ' ' && filename[i] != '\t') {
            valid = 1;
            break;
        }
    }
    if (!valid) {
        kprint("Error: Filename cannot be empty!", 0x4F00, vga +1680+21);
        kpause();
        return;
    }

    kclearscreen();
    kprint("+------------------------------------------------------------------------------+", 0x0F00, vga);
    kprint("|File content:                                                                 |", 0x0F00, vga + 80);
    kprint("+------------------------------------------------------------------------------+", 0x0F00, vga + 160);
    kpause();
    kinput(240, content, sizeof(content));
    // Fájl létrehozása
    int result = create_file(filename, content,strlen(content));
    if (result == 0) {
    } else {
        kprint("File make failed!", 0x4F00, vga+240);
    }
}