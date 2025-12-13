void read(void) {
    static char file_content[512];
    char filename[13];

    kpause();

    // Név beolvasása kinput2-vel a 1520+22+5 = 1547 offseten
    kinput2(886, filename, sizeof(filename));

    // Ha üres a név
    if (filename[0] == '\0') {
        kprint("Error: Filename cannot be empty.", 0x4F00, vga + 921);
        kpause();
        return;
    }

    // Most töröljük a képernyőt
    kclearscreen();
    // Első képernyő – nincs törlés
    kprint("+--------------------------------------+", 0x0F00, vga);
    kprint("|File content:                         |", 0x0F00, vga + 40);
    kprint("+--------------------------------------+", 0x0F00, vga + 80);

    int size = read_file(filename, file_content, sizeof(file_content));

    if (size > 0) {
        kprint(file_content, 0x0700, vga + 120);
    } else {
        kprint("Something went wrong", 0x4F00, vga+120);
        kprint("File not found or read error.", 0x4F00, vga+160);
    }

    kpause();
}