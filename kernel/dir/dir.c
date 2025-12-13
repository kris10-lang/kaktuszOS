int is_directory(unsigned char attr) {
    return (attr & 0x10) != 0;
}
void dir(void) {
    if (fat_read_bpb() != 0) return;
    unsigned int LBA_FAT = FAT12_LBA_OFFSET + g_bpb.BPB_RsvdSecCnt;
    unsigned int LBA_RDIR = LBA_FAT + (g_bpb.BPB_NumFATs * g_bpb.BPB_FATSz16);
    int root_dir_sectors = (g_bpb.BPB_RootEntCnt * 32) / g_bpb.BPB_BytesPerSec;
    unsigned char root_dir_buffer[SECTOR_SIZE];
    DIR_Entry* entry;
    char display_name[13]; 
    
    kclearscreen();
    unsigned short vga_cursor_index = 0; 
    volatile unsigned short* vga_cursor_pos = (volatile unsigned short*)0xb8000;
    kprint("Directory Listing (FAT12 Root)", 0x0A00, vga_cursor_pos);
    vga_cursor_index += 40;
    vga_cursor_pos += 40; 
    
    kprint("FILENAME        TYPE      SIZE", 0x0F00, vga_cursor_pos);
    vga_cursor_index += 40;
    vga_cursor_pos += 40; 

    kprint("----------------------------------------", 0x0700, vga_cursor_pos);
    vga_cursor_index += 40;
    vga_cursor_pos += 40; 
    int entry_count = 0;

    for (int i = 0; i < root_dir_sectors; i++) {
        if (read_sectors(LBA_RDIR + i, 1, root_dir_buffer) != 0) {
            kprint("Error when reading ::", 0x4F00, vga_cursor_pos);
            kpause();
            return;
        }
        for (int j = 0; j < SECTOR_SIZE / sizeof(DIR_Entry); j++) {
            entry = (DIR_Entry*)&root_dir_buffer[j * sizeof(DIR_Entry)];
            
            if (entry->DIR_Name[0] == 0x00) goto end_listing; 
            if (entry->DIR_Name[0] == 0xE5 || entry->DIR_Attr == 0x0F || entry->DIR_Attr == 0x08) continue;
            
            entry_count++;

            int k = 0;
            
            for (int l = 0; l < 8; l++) {
                if (entry->DIR_Name[l] == ' ') break;
                display_name[k++] = entry->DIR_Name[l];
            }
            
            if (entry->DIR_Name[8] != ' ') {
                display_name[k++] = '.';
                for (int l = 8; l < 11; l++) {
                    if (entry->DIR_Name[l] == ' ') break;
                    display_name[k++] = entry->DIR_Name[l];
                }
            }
            display_name[k] = '\0';
            
            kprint(display_name, 0x0F00, vga_cursor_pos);
            int name_len = strlen(display_name);
            vga_cursor_pos += name_len;
            vga_cursor_index += name_len; 
            
            kprint_spaces(16 - name_len, 0x0F00, vga_cursor_pos); 
            vga_cursor_pos += 16 - name_len;
            vga_cursor_index += 16 - name_len; 

            if (is_directory(entry->DIR_Attr)) {
                kprint("<DIR>", 0x0B00, vga_cursor_pos); 
                kprint_spaces(8 - 5, 0x0B00, vga_cursor_pos + 5);
                vga_cursor_pos += 8;
                vga_cursor_index += 8; 
                kprint_spaces(4, 0x0F00, vga_cursor_pos);
                vga_cursor_pos += 4;
                vga_cursor_index += 4; 
            } else {
                kprint("FILE", 0x0700, vga_cursor_pos); 
                kprint_spaces(8 - 4, 0x0700, vga_cursor_pos + 4);
                vga_cursor_pos += 8;
                vga_cursor_index += 8; 
                kprint_spaces(4, 0x0F00, vga_cursor_pos);
                vga_cursor_pos += 4;
                vga_cursor_index += 4; 
            }
            
            if (!is_directory(entry->DIR_Attr)) {
                kprint_int(entry->DIR_FileSize, 0x0700, vga_cursor_pos); 
            }
            
            unsigned short jump = (80 - (vga_cursor_index % 80)); 
            vga_cursor_index += jump;
            
            vga_cursor_pos = (volatile unsigned short*)0xb8000 + vga_cursor_index; 
            
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