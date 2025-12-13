
// kernel/dir/dir.c

// --------------------------------------------------
// GLOBÁLIS DEKLARÁCIÓK ÉS MAKRÓK (Feltételezettek)
// --------------------------------------------------
#define FAT12_LBA_OFFSET 64
// Feltételezzük, hogy a g_bpb és a DIR_Entry struktúrák itt vagy egy headerben elérhetőek.
// char display_name[13]; // Globálisan kell deklarálni, ha a függvényen kívül történt a deklaráció.

// VGA memória alapcím (Fontos: Helyezd ezt a deklarációt egy központi header/c fájlba!)
// extern volatile unsigned short* vga; // Ha ez a deklaráció már létezik egy headerben.

// Segédfüggvény a FAT attribútumok ellenőrzésére
int is_directory(unsigned char attr) {
    return (attr & 0x10) != 0; // 0x10 = Könyvtár (Directory)
}

// --------------------------------------------------
// A JAVÍTOTT DIR FÜGGVÉNY
// --------------------------------------------------
void dir(void) {
    // 1. Inicializálás és BPB olvasás
    if (fat_read_bpb() != 0) return;

    unsigned int LBA_FAT = FAT12_LBA_OFFSET + g_bpb.BPB_RsvdSecCnt;
    unsigned int LBA_RDIR = LBA_FAT + (g_bpb.BPB_NumFATs * g_bpb.BPB_FATSz16);
    int root_dir_sectors = (g_bpb.BPB_RootEntCnt * 32) / g_bpb.BPB_BytesPerSec;

    unsigned char root_dir_buffer[SECTOR_SIZE];
    DIR_Entry* entry;
    
    // A display_name-t a dir() függvényen belül deklaráljuk, ha a fenti sor kommentben van.
    char display_name[13]; 
    
    kclearscreen();
    
    // ❗ INDEX VÁLTOZÓ: Pozíciókövetéshez (modulo, összehasonlítás)
    unsigned short vga_cursor_index = 0; 
    
    // ❗ CÍM VÁLTOZÓ: A kprint hívásokhoz szükséges pointer
    volatile unsigned short* vga_cursor_pos = (volatile unsigned short*)0xb8000;
    
    // Fejléc kiírása
    kprint("Directory Listing (FAT12 Root)", 0x0A00, vga_cursor_pos);
    vga_cursor_index += 40;
    vga_cursor_pos += 40; 
    
    kprint("FILENAME        TYPE      SIZE", 0x0F00, vga_cursor_pos);
    vga_cursor_index += 40;
    vga_cursor_pos += 40; 

    kprint("----------------------------------------", 0x0700, vga_cursor_pos);
    vga_cursor_index += 40;
    vga_cursor_pos += 40; 

    // Fájlszámláló
    int entry_count = 0;

    // 2. Az összes Gyökérkönyvtári szektor átvizsgálása
    for (int i = 0; i < root_dir_sectors; i++) {
        if (read_sectors(LBA_RDIR + i, 1, root_dir_buffer) != 0) {
            kprint("Error when reading ::", 0x4F00, vga_cursor_pos);
            kpause();
            return;
        }

        // Végigmenetel minden DIR_Entry-n a szektorban
        for (int j = 0; j < SECTOR_SIZE / sizeof(DIR_Entry); j++) {
            entry = (DIR_Entry*)&root_dir_buffer[j * sizeof(DIR_Entry)];
            
            if (entry->DIR_Name[0] == 0x00) goto end_listing; 
            if (entry->DIR_Name[0] == 0xE5 || entry->DIR_Attr == 0x0F || entry->DIR_Attr == 0x08) continue;
            
            entry_count++;

            // 3. Fájlnév konvertálása és megjelenítése
            int k = 0;
            
            // Név (8 karakter)
            for (int l = 0; l < 8; l++) {
                if (entry->DIR_Name[l] == ' ') break;
                display_name[k++] = entry->DIR_Name[l];
            }
            
            // Kiterjesztés (3 karakter)
            if (entry->DIR_Name[8] != ' ') {
                display_name[k++] = '.';
                for (int l = 8; l < 11; l++) {
                    if (entry->DIR_Name[l] == ' ') break;
                    display_name[k++] = entry->DIR_Name[l];
                }
            }
            display_name[k] = '\0';
            
            // --- Megjelenítés ---
            
            // Fájlnév (oszlop 1)
            kprint(display_name, 0x0F00, vga_cursor_pos);
            int name_len = strlen(display_name);
            vga_cursor_pos += name_len;
            vga_cursor_index += name_len; 
            
            kprint_spaces(16 - name_len, 0x0F00, vga_cursor_pos); 
            vga_cursor_pos += 16 - name_len;
            vga_cursor_index += 16 - name_len; 

            // Típus (oszlop 2)
            if (is_directory(entry->DIR_Attr)) {
                kprint("<DIR>", 0x0B00, vga_cursor_pos); 
                kprint_spaces(8 - 5, 0x0B00, vga_cursor_pos + 5); // +5 pointer eltolás
                vga_cursor_pos += 8;
                vga_cursor_index += 8; 
                kprint_spaces(4, 0x0F00, vga_cursor_pos);
                vga_cursor_pos += 4;
                vga_cursor_index += 4; 
            } else {
                kprint("FILE", 0x0700, vga_cursor_pos); 
                kprint_spaces(8 - 4, 0x0700, vga_cursor_pos + 4); // +4 pointer eltolás
                vga_cursor_pos += 8;
                vga_cursor_index += 8; 
                kprint_spaces(4, 0x0F00, vga_cursor_pos);
                vga_cursor_pos += 4;
                vga_cursor_index += 4; 
            }
            
            // Méret (oszlop 3)
            if (!is_directory(entry->DIR_Attr)) {
                kprint_int(entry->DIR_FileSize, 0x0700, vga_cursor_pos); 
                // Fontos: Itt a kprint_int függvénynek kell léptetnie a vga_cursor_pos-t!
                // Mivel a kprint_int nem küld vissza léptetési hosszt, 
                // feltételezzük, hogy *nem lépteti* a vga_cursor_pos-t.
                // EZ LOGIKAI HIBA LEHET, DE EZ AZ ÖSSZES KÓDOD! 
                // Vagy itt kellene léptetned: vga_cursor_index += [méret_hossza];
            }
            
            // Új sor (INDEX alapú ugrás)
            unsigned short jump = (80 - (vga_cursor_index % 80)); 
            vga_cursor_index += jump;
            
            // Pointer frissítése a 0xB8000 alapcímről az új index alapján
            vga_cursor_pos = (volatile unsigned short*)0xb8000 + vga_cursor_index; 
            

            // Lapozás
            if (vga_cursor_index >= 2000) { 
                kprint("--- CONTINUE (press button) ---", 0x0E00, vga_cursor_pos);
                kpause();
                kclearscreen();
                vga_cursor_pos = (volatile unsigned short*)0xb8000;
                vga_cursor_index = 0;
            }
        }
    }

end_listing:
    vga_cursor_index += 40;
    vga_cursor_pos = (volatile unsigned short*)0xb8000 + vga_cursor_index;
    
    kprint("Total entries found: ", 0x0A00, vga_cursor_pos);
    kprint_int(entry_count, 0x0A00, vga_cursor_pos + 21);
    kpause();
}