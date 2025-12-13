void prog(void) {
    char filename[13];
    char input[256];
    unsigned char buffer[128];
    int i = 0, j = 0;
    int length = 0;
    
    kpause();
    kinput2(886, filename, sizeof(filename),1);
    if (filename[0] == '\0') {
        kprint("Error: Filename cannot be empty.", 0x4F00, vga +921);
        kpause();
        return;
    }
    if (file_exists(filename)) {
        kprint("Error: File already exists!", 0x4F00, vga + 921);
        kpause();
        return;
    }
    // Most töröljük a képernyőt
    kclearscreen();
    // Első képernyő – nincs törlés
    kprint("+--------------------------------------+", 0x0F00, vga);
    kprint("|Write in hex code without 0x prefix   |", 0x0F00, vga + 40);
    kprint("+--------------------------------------+", 0x0F00, vga + 80);
    kpause();
    // Beolvasunk egy sort szövegesen (pl: "84 97 bb aa")
    kinput(120, input, sizeof(input),0);

    while (input[i] != '\0' && input[i] != '\n' && j < (int)sizeof(buffer)) {
        // Skip spaces
        while (input[i] == ' ' || input[i] == '\t') i++;

        // Ha a következő 2 karakter hex számjegyek, olvassuk be őket
        if (input[i] && input[i+1]) {
            int val = hex_to_byte(&input[i]);
            if (val < 0) {
                kprint("Invalid hex input!", 0x4F00, vga+120);
                kpause();
                return;
            }
            buffer[j++] = (unsigned char)val;
            i += 2;
        } else if (input[i]) {
            // Egyetlen hex karakter is elfogadott (pl: 'a' -> 0x0a)
            int val = hex_char_to_int(input[i]);
            if (val < 0) {
                kprint("Invalid hex input!", 0x4F00, vga+120);
                kpause();
                return;
            }
            buffer[j++] = (unsigned char)val;
            i++;
        }
    }

    length = j;

    if (length > 0) {
        create_file(filename, (const char*)buffer, length);
        kprint("File created!", 0x0200, vga+120);
    } else {
        kprint("No valid input given.", 0x4F00, vga+120);
    }

    kpause();
}