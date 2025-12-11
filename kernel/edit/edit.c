void edit(void) {
    char filename[13];
    char content[512];
    int length = 0;

    kpause();
    kinput2(1547, filename, sizeof(filename));

    // Ellenőrzés: nem lehet üres név
    int valid = 0;
    for (int i = 0; i < sizeof(filename); i++) {
        if (filename[i] == '\0') break;
        if (filename[i] != ' ' && filename[i] != '\t') {
            valid = 1;
            break;
        }
    }
    if (!valid) {
        kprint("Error: Filename cannot be empty!", 0x4F00, vga + 1680 + 21);
        kpause();
        return;
    }

    // Ha létezik, beolvassuk, ha nem, akkor üres tartalommal folytatjuk
    if (file_exists(filename)) {
        length = read_file(filename, content, sizeof(content));
        if (length < 0) {
            kprint("Error reading file!", 0x4F00, vga + 1680 + 21);
            kpause();
            return;
        }
    } else {
        kprint("Error file doesn't exists", 0x4F00, vga + 1680 + 21);
        kpause();
        return;
    }

    kclearscreen();
    kprint("+------------------------------------------------------------------------------+", 0x0F00, vga);
    kprint("|Editing file:                                                                 |", 0x0F00, vga + 80);
    kprint(filename, 0x0F00, vga + 100);
    kprint("+------------------------------------------------------------------------------+", 0x0F00, vga + 160);

    kpause();
    // Most kérjük be a szerkesztett szöveget (vagy akár kódot erre a részre)
    kinput(240, content, sizeof(content));

    // Ha létezett a fájl, töröljük
    if (file_exists(filename)) {
        delete_file(filename);
    }

    // Ha van tartalom, létrehozzuk a fájlt
    int new_length = 0;
    for (int i = 0; i < sizeof(content); i++) {
        if (content[i] == '\0') break;
        new_length++;
    }

    if (new_length > 0) {
        create_file(filename, content, new_length);
        kprint("File saved successfully.", 0x0200, vga+240);
    } else {
        kprint("Empty file, nothing saved.", 0x4F00, vga+240);
    }
}
