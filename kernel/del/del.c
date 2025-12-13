void del(void) {
    char filename[13];

    kpause();

    // Fájlnév bekérése
    kinput2(885, filename, sizeof(filename));

    // Üres fájlnév hiba
    if (filename[0] == '\0') {
        kprint("Error: Filename cannot be empty.", 0x4F00, vga+921);
        kpause();
        return;
    }

    // Fájl törlése
    int result = delete_file(filename);

    // Kiírás az eredményről
    if (result == 0) {
        kprint("File deleted.", 0x4f00,vga+921);
    } else {
        kprint("Error deleting file.", 0x4F00, vga+921);
    }

    kpause();
}