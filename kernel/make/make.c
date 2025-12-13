void make(void) {
    char content[512];
    char filename[13];

    kpause();
    kinput2(886, filename, sizeof(filename),1);

    // Ellenőrizzük, hogy a fájlnév nem üres-e
    int valid = 0;
    for (int i = 0; i < sizeof(filename); i++) {
        if (filename[i] == '\0') break;
        if (filename[i] != ' ' && filename[i] != '\t') {
            valid = 1;
            break;
        }
    }
    if (!valid) {
        kprint("Error: Filename cannot be empty!", 0x4F00, vga+921);
        kpause();
        return;
    }

    // Ellenőrizzük, hogy a fájl már létezik-e
    if (file_exists(filename)) {
        kprint("Error: File already exists!", 0x4F00, vga+921);
        kpause();
        return;
    }

    // Ha minden OK, kérjük be a fájl tartalmát
    kclearscreen();
    kprint("+--------------------------------------+", 0x0F00, vga);
    kprint("|File content:                         |", 0x0F00, vga+40);
    kprint("+--------------------------------------+", 0x0F00, vga+80);
    kpause();
    kinput(120, content, sizeof(content),0);

    // Fájl létrehozása
    int result = create_file(filename, content, strlen(content));
    if (result == 0) {
        kprint("File created successfully",0x0200,vga+120);
    } else {
        kprint("File make failed!", 0x4F00, vga+120);
        kpause();
    }
}