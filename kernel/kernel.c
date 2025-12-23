//előre létrehozott változók
#include "valtozok.c"
#include "apppoziciok.c"
//prototípusok
#include "prototipusok.c"
#include "appprototipusok.c"
//main
void kmain(void) {
    while (1) {
        kinit_gui();
        kprint("                                    ", 0x0F00, vga+881);
        kinput(881,command,sizeof(command),1);
        if (strcmp(command, "logo") == 0) {
            logo();
        }
        if (strcmp(command, "calc") == 0) {
            calc();
        }
        if (strcmp(command, "read") == 0) {
            read();
        }
        if (strcmp(command, "dir") == 0) {
            dir();
        }
        if (strcmp(command, "make") == 0) {
            make();
        }
        if (strcmp(command, "run") == 0) {
            char filename[13];
            kpause();
            kinput2(885, filename, sizeof(filename),1);
            run_app(filename);
        }
        if (strcmp(command, "del") == 0) {
            del();
        }
        if (strcmp(command, "prog") == 0) {
            prog();
        }
        if (strcmp(command, "edit") == 0) {
            edit();
        }
        if (strcmp(command, "copy") == 0) {
            copy();
        }
        if (strcmp(command, "name") == 0) {
            rename();
        }
        if (strcmp(command, "help") == 0) {
            help();
        }
        if (strcmp(command, "commodore64") == 0) {
            shell();
        }
        kpause();
    }
}
//fügvények
void kinit_gui(void) {
    kclearscreen();
    int line = 0;
    kprint("+--+--+--+--+--+--+--+--+--+--+--+--+--+", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("+--+--+--+--+--+--+--+--+--+--+--+--+--+", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("+--+--+--+--+--+--+--+--+--+--+--+--+--+", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("+--+--+--+--+--+--+--+--+--+--+--+--+--+", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("+--+--+--+--+--+--+--+--+--+--+--+--+--+", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("+--+--+--+--+--+--+--+--+--+--+--+--+--+", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("|  |  |  |  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("+--+--+--+--+--+--+--+--+--+--+--+--+--+", 0x0A00, vga+line);
    line = line+40;
    kprint("|Welcome to |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("|kaktuszOS  |  |  |  |  |  |  |  |  |  |", 0x0A00, vga+line);
    line = line+40;
    kprint("+--+--+--+--+--+--+--+--+--+--+--+--+--+", 0x0E00, vga+line);
    line = line+40;
    kprint("|                                      |", 0x0E00, vga+line);
    line = line+40;
    kprint("|                                      |", 0x0E00, vga+line);
    line = line+40;
    kprint("+--------------------------------------+", 0x0E00, vga+line);
    kwriteapp("logo", app1[0], app1[1], app1[2],0x0F00);
    kwriteapp("calc", app2[0], app2[1], app2[2],0x0F00);
    kwriteapp("read", app3[0], app3[1], app3[2],0x0F00);
    kwriteapp("dir ", app4[0], app4[1], app4[2],0x0F00);
    kwriteapp("make", app5[0], app5[1], app5[2],0x0F00);
    kwriteapp("del ", app6[0], app6[1], app6[2],0x0F00);
    kwriteapp("prog", app7[0], app7[1], app7[2],0x0F00);
    kwriteapp("edit", app8[0], app8[1], app8[2],0x0F00);
    kwriteapp("run ", app9[0], app9[1], app9[2],0x0F00);
    kwriteapp("copy",app10[0],app10[1],app10[2],0x0F00);
    kwriteapp("name",app11[0],app11[1],app11[2],0x0F00);
    kwriteapp("help",app12[0],app12[1],app12[2],0x0F00);
}
void kclearscreen(void) {
    for (int i = 0; i < 40*25; i++) {
        vga[i] = (unsigned short)(' ' | 0x0F00);
    }
}
void kprint(const char* str, unsigned color, volatile unsigned short* start_addr) {
    int i = 0;
    while (str[i]) {
        start_addr[i] = (unsigned short)(str[i] | color);
        i++;
    }
}
void kprint_int(int value, unsigned short color, volatile unsigned short* start_addr) {
    char buffer[12];
    int i = 10;
    buffer[11] = '\0';
    if (value == 0) {
        buffer[i--] = '0';
    } else {
        int temp = value;
        while (temp > 0) {
            buffer[i--] = (temp % 10) + '0';
            temp /= 10;
        }
    }
    volatile unsigned short* current_addr = start_addr;
    for (int j = i + 1; buffer[j] != '\0'; j++) {
        *current_addr = (unsigned short)(buffer[j] | color);
        current_addr++;
    }
}
void kprint_spaces(int count, unsigned short color, volatile unsigned short* start_addr) {
    volatile unsigned short* current_addr = start_addr;
    for (int i = 0; i < count; i++) {
        *current_addr = (unsigned short)(' ' | color);
        current_addr++;
    }
}
void kwriteapp(const char* text, int start_c, int sorindex1, int sorindex2, unsigned color) {
    int def_start_c = start_c;
    vga[start_c+sorindex1*40] = (unsigned short)(text[0] | color);
    start_c++;
    vga[start_c+sorindex1*40] = (unsigned short)(text[1] | color);
    start_c = def_start_c;
    vga[start_c+sorindex2*40] = (unsigned short)(text[2] | color);
    start_c++;
    vga[start_c+sorindex2*40] = (unsigned short)(text[3] | color);
}
unsigned char kscancode_to_ascii(unsigned char scancode) {
    switch (scancode) {
        case 0x29: return '0';
        case 0x02: return '1';
        case 0x03: return '2';
        case 0x04: return '3';
        case 0x05: return '4';
        case 0x06: return '5';
        case 0x07: return '6';
        case 0x08: return '7';
        case 0x09: return '8';
        case 0x0A: return '9';
        case 0x1E: return 'a';
        case 0x30: return 'b';
        case 0x2E: return 'c';
        case 0x20: return 'd';
        case 0x12: return 'e';
        case 0x21: return 'f';
        case 0x22: return 'g';
        case 0x23: return 'h';
        case 0x17: return 'i';
        case 0x24: return 'j';
        case 0x25: return 'k';
        case 0x26: return 'l';
        case 0x32: return 'm';
        case 0x31: return 'n';
        case 0x18: return 'o';
        case 0x19: return 'p';
        case 0x10: return 'q';
        case 0x13: return 'r';
        case 0x1F: return 's';
        case 0x14: return 't';
        case 0x16: return 'u';
        case 0x2F: return 'v';
        case 0x11: return 'w';
        case 0x2D: return 'x';
        case 0x15: return 'z';
        case 0x2C: return 'y';
        case 0x39: return ' ';
        case 0x35: return '/';
        case 0x37: return '*';
        case 0x4A: return '-';
        case 0x4E: return '+';
        case 0x34: return '.';
        default: return 0;
    }
}
unsigned char get_scancode() {
    // 1. Várjuk meg, amíg a Status Register (0x64) 0. bitje 1 lesz
    // Ez jelzi, hogy van olvasható adat az Output Bufferben
    while (!(kinb(0x64) & 1)) {
        // Itt egy nagyon rövid várakozás (opcionális, de stabilabb)
        asm volatile("pause"); 
    }
    // 2. Csak most olvassuk ki a kódot
    return kinb(0x60);
}
void kinput(int vga_pos_start, char* buffer, int buffer_size, int shadow_mode) {
    int cmd_len = 0;
    int vga_pos_current = vga_pos_start; 
    buffer[0] = '\0';
    const int VGA_WIDTH = 40;
    while (1) {
        unsigned char scancode = get_scancode();
        if (scancode & 0x80) {
            continue; 
        }
        if (scancode == 0x1C) {
            break;
        }
        if (scancode == 0x0E) { // Backspace
            if (cmd_len > 0) {
                cmd_len--;
                buffer[cmd_len] = '\0';
                vga_pos_current--;
                vga[vga_pos_current] = (unsigned short)(' ' | 0x0F00);
                if (shadow_mode) {
                    vga[vga_pos_current + VGA_WIDTH] = (unsigned short)(' ' | 0x0F00); 
                }
            }
        }
        unsigned char ch = kscancode_to_ascii(scancode);
        if (ch != 0) {
            if (cmd_len < buffer_size - 1) {
                buffer[cmd_len++] = ch;
                buffer[cmd_len] = '\0';
                vga[vga_pos_current] = (unsigned short)(ch | 0x0F00);
                
                if (shadow_mode) {
                    const int VGA_WIDTH = 40;
                    if ((vga_pos_current + VGA_WIDTH) < (40 * 25)) { 
                        vga[vga_pos_current + VGA_WIDTH] = (unsigned short)(ch | 0x0F00);
                    }
                }
                
                vga_pos_current++;
            }
        }
        do {
            scancode = kinb(0x60);
        } while (!(scancode & 0x80));
    }
}
void kinput2(int vga_pos_start, char* buffer, int buffer_size, int shadow_mode) {
    int cmd_len = 0;
    int vga_pos_current = vga_pos_start; 
    buffer[0] = '\0';
    
    const int VGA_WIDTH = 40; 

    while (1) {
        unsigned char scancode = get_scancode();
        if (scancode & 0x80) {
            continue; 
        }
        if (scancode == 0x1C) { // Enter (0x1C)
            break;
        }
        if (scancode == 0x0E) { // Backspace (0x0E)
            if (cmd_len > 0) {
                cmd_len--;
                buffer[cmd_len] = '\0';
                vga_pos_current--;
                
                vga[vga_pos_current] = (unsigned short)(' ' | 0x0F00); 
                
                if (shadow_mode) {
                    vga[vga_pos_current + VGA_WIDTH] = (unsigned short)(' ' | 0x0F00); 
                }
            }
        }

        unsigned char ch = kscancode_to_ascii(scancode);
        
        if (ch >= 'a' && ch <= 'z') {
            ch -= 32;
        }
        
        if (ch != 0) {
            if (cmd_len < buffer_size - 1) {
                buffer[cmd_len++] = ch;
                buffer[cmd_len] = '\0';
                
                vga[vga_pos_current] = (unsigned short)(ch | 0x0F00);
                if (shadow_mode) {
                    if ((vga_pos_current + VGA_WIDTH) < (40 * 25)) { 
                        vga[vga_pos_current + VGA_WIDTH] = (unsigned short)(ch | 0x0F00);
                    }
                }
                
                vga_pos_current++;
            }
        }

        do {
            scancode = kinb(0x60);
            if (scancode == 0xAA || scancode == 0xB6) {
                shift_active = 0;
            }
            
        } while (!(scancode & 0x80)); 
        
    skip_char_processing:; 
    }
}
static inline unsigned char kinb(unsigned short port) {
    unsigned char ret;
    __asm__ volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}
int strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}
void kpause(void) {
    unsigned char scancode;
    do {
        scancode = kinb(0x60);
    } while (scancode & 0x80);
    do {
        scancode = kinb(0x60);
    } while (!(scancode & 0x80));
}
void int_to_string(int num, char* buffer) {
    char temp[12];
    int i = 0;
    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }
    int is_negative = 0;
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }
    while (num > 0) {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }
    if (is_negative) {
        temp[i++] = '-';
    }
    int j;
    for (j = 0; j < i; j++) {
        buffer[j] = temp[i - j - 1];
    }
    buffer[j] = '\0';
}
void string_to_int(const char* str, int* out_num) {
    int num = 0;
    int sign = 1;
    int i = 0;
    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') break;
        num = num * 10 + (str[i] - '0');
    }
    *out_num = num * sign;
}
//filesystem
static inline void koutb(unsigned short port, unsigned char data) {
    __asm__ volatile ("outb %0, %w1" : : "a"(data), "Nd"(port));
}
static inline unsigned short kinw(unsigned short port) {
    unsigned short ret;
    __asm__ volatile ("inw %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}
void ata_wait_for_ready(void) {
    kinb(ATA_PRIMARY_DCR); kinb(ATA_PRIMARY_DCR); kinb(ATA_PRIMARY_DCR); kinb(ATA_PRIMARY_DCR);
    while (kinb(ATA_PRIMARY_STATUS) & 0x80); 
}
int read_sectors(unsigned int lba, unsigned char count, unsigned char* buffer) {
    ata_wait_for_ready();
    koutb(ATA_PRIMARY_DCR, 0x00);
    koutb(ATA_PRIMARY_SECTOR_COUNT, count);
    koutb(ATA_PRIMARY_LBA_LOW, (unsigned char)(lba & 0xFF));
    koutb(ATA_PRIMARY_LBA_MID, (unsigned char)((lba >> 8) & 0xFF));
    koutb(ATA_PRIMARY_LBA_HIGH, (unsigned char)((lba >> 16) & 0xFF));
    koutb(ATA_PRIMARY_DRIVE_HEAD, 0xE0 | ((lba >> 24) & 0x0F)); 
    koutb(ATA_PRIMARY_COMMAND, 0x20);
    for (int i = 0; i < count; i++) {
        ata_wait_for_ready();
        if (!(kinb(ATA_PRIMARY_STATUS) & 0x08)) return -1;
        unsigned short* current_buffer_16bit = (unsigned short*)(buffer + i * SECTOR_SIZE);
        for (int j = 0; j < 256; j++) {
            current_buffer_16bit[j] = kinw(ATA_PRIMARY_DATA);
        }
    }
    return 0;
}
int fat_read_bpb(void) {
    if (read_sectors(FAT12_LBA_OFFSET, 1, (unsigned char*)&g_bpb) != 0) {
        kprint("BPB reading problem!", 0x4F00, vga + 881+40);
        return -1;
    }
    if (g_bpb.BPB_BytesPerSec != 512) {
        kprint("BPB unallowed size!", 0x4F00, vga + 881+40);
        return -1;
    }
    return 0;
}
unsigned int fat_calc_lba(unsigned short cluster) {
    if (cluster < 2) return 0;
    unsigned int LBA_FAT = FAT12_LBA_OFFSET + g_bpb.BPB_RsvdSecCnt;
    unsigned int LBA_RDIR = LBA_FAT + (g_bpb.BPB_NumFATs * g_bpb.BPB_FATSz16);
    unsigned int LBA_Data = LBA_RDIR + (g_bpb.BPB_RootEntCnt * 32 / g_bpb.BPB_BytesPerSec);
    return LBA_Data + (cluster - 2) * g_bpb.BPB_SecPerClus;
}
unsigned short fat_read_fat_entry(unsigned short cluster) {
    if (cluster < 2) return 0xFFFF;
    unsigned int LBA_FAT = FAT12_LBA_OFFSET + g_bpb.BPB_RsvdSecCnt;
    unsigned int FAT_offset = cluster + (cluster / 2);
    unsigned int sector = LBA_FAT + (FAT_offset / SECTOR_SIZE);
    unsigned int entry_offset = FAT_offset % SECTOR_SIZE;
    unsigned char sector_buffer[SECTOR_SIZE];
    if (read_sectors(sector, 1, sector_buffer) != 0) return 0xFFFF;
    unsigned short entry_value = *(unsigned short*)&sector_buffer[entry_offset];
    if (cluster & 0x01) {
        return entry_value >> 4;
    } 
    else {
        return entry_value & 0x0FFF;
    }
}
int read_file(const char* filename, char* output_buffer, int buffer_size) {
    if (fat_read_bpb() != 0) return -1;
    unsigned int LBA_FAT = FAT12_LBA_OFFSET + g_bpb.BPB_RsvdSecCnt;
    unsigned int LBA_RDIR = LBA_FAT + (g_bpb.BPB_NumFATs * g_bpb.BPB_FATSz16);
    int root_dir_sectors = (g_bpb.BPB_RootEntCnt * 32) / SECTOR_SIZE;
    DIR_Entry* entry;
    unsigned char root_dir_buffer[SECTOR_SIZE];
    int file_size = 0;
    unsigned short start_cluster = 0;
    for (int i = 0; i < root_dir_sectors; i++) {
        if (read_sectors(LBA_RDIR + i, 1, root_dir_buffer) != 0) return -1;
        for (int j = 0; j < SECTOR_SIZE / sizeof(DIR_Entry); j++) {
            entry = (DIR_Entry*)&root_dir_buffer[j * sizeof(DIR_Entry)];
            if (entry->DIR_Name[0] == 0x00 || entry->DIR_Name[0] == 0xE5) continue;
            char fat_name[12];
            int k;
            for (k = 0; k < 8; k++) {
                if (entry->DIR_Name[k] == ' ') break;
                fat_name[k] = entry->DIR_Name[k];
            }
            if (entry->DIR_Name[8] != ' ') {
                fat_name[k++] = '.';
                for (int l = 8; l < 11; l++) {
                    if (entry->DIR_Name[l] == ' ') break;
                    fat_name[k++] = entry->DIR_Name[l];
                }
            }
            fat_name[k] = '\0';
            if (strcmp(fat_name, filename) == 0) {
                file_size = entry->DIR_FileSize;
                start_cluster = entry->DIR_FstClus;
                goto found_file;
            }
        }
    }
    return -1;
found_file:
    unsigned short current_cluster = start_cluster;
    int bytes_read = 0;
    while (current_cluster < 0xFF8) {
        unsigned int lba_addr = fat_calc_lba(current_cluster);
        if (read_sectors(lba_addr, 1, (unsigned char*)(output_buffer + bytes_read)) != 0) return -1;
        bytes_read += SECTOR_SIZE;
        current_cluster = fat_read_fat_entry(current_cluster);
        if (bytes_read >= buffer_size) break; 
    }
    if (file_size < buffer_size) {
        output_buffer[file_size] = '\0';
    } else {
        output_buffer[buffer_size - 1] = '\0';
    }
    return file_size;
}
int strlen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    
    return length;
}
int write_sectors(unsigned int lba, unsigned char count, unsigned char* buffer) {
    ata_wait_for_ready();
    koutb(ATA_PRIMARY_DCR, 0x00);
    koutb(ATA_PRIMARY_SECTOR_COUNT, count);
    koutb(ATA_PRIMARY_LBA_LOW, (unsigned char)(lba & 0xFF));
    koutb(ATA_PRIMARY_LBA_MID, (unsigned char)((lba >> 8) & 0xFF));
    koutb(ATA_PRIMARY_LBA_HIGH, (unsigned char)((lba >> 16) & 0xFF));
    koutb(ATA_PRIMARY_DRIVE_HEAD, 0xE0 | ((lba >> 24) & 0x0F)); 
    
    koutb(ATA_PRIMARY_COMMAND, 0x30);
    
    for (int i = 0; i < count; i++) {
        ata_wait_for_ready();
        if (!(kinb(ATA_PRIMARY_STATUS) & 0x08)) return -1;
        unsigned short* current_buffer_16bit = (unsigned short*)(buffer + i * SECTOR_SIZE);
        for (int j = 0; j < 256; j++) {
            koutw(ATA_PRIMARY_DATA, current_buffer_16bit[j]);
        }
    }
    
    koutb(ATA_PRIMARY_COMMAND, 0xE7);
    ata_wait_for_ready(); 
    
    return 0;
}

static inline void koutw(unsigned short port, unsigned short data) {
    __asm__ volatile ("outw %w0, %w1" : : "a"(data), "Nd"(port));
}
#define FAT_ENTRY_FREE 0x0000 
#define FAT_ENTRY_EOF 0x0FFF 

unsigned short fat_find_free_cluster(void) {
    if (fat_read_bpb() != 0) return 0;
    
    unsigned int LBA_FAT = FAT12_LBA_OFFSET + g_bpb.BPB_RsvdSecCnt;
    
    if (read_sectors(LBA_FAT, g_bpb.BPB_FATSz16 * g_bpb.BPB_NumFATs, g_fat_table) != 0) {
        return 0; 
    }
    
    for (unsigned short cluster = 2; cluster < 4085; cluster++) { 
        unsigned int FAT_offset = cluster + (cluster / 2);
        unsigned int sector_offset = FAT_offset / SECTOR_SIZE;
        unsigned int entry_offset = FAT_offset % SECTOR_SIZE;
        
        unsigned char* sector_buffer = g_fat_table + sector_offset * SECTOR_SIZE;
        unsigned short entry_value = *(unsigned short*)&sector_buffer[entry_offset];
        
        unsigned short current_entry;
        if (cluster & 0x01) {
            current_entry = entry_value >> 4;
        } else {
            current_entry = entry_value & 0x0FFF;
        }
        
        if (current_entry == FAT_ENTRY_FREE) {
            if (cluster & 0x01) { 
                *(unsigned short*)&sector_buffer[entry_offset] = (entry_value & 0x000F) | (FAT_ENTRY_EOF << 4);
            } else { 
                *(unsigned short*)&sector_buffer[entry_offset] = (entry_value & 0xF000) | FAT_ENTRY_EOF;
            }

            write_sectors(LBA_FAT, g_bpb.BPB_FATSz16, g_fat_table);
            write_sectors(LBA_FAT + g_bpb.BPB_FATSz16, g_bpb.BPB_FATSz16, g_fat_table);
            
            return cluster;
        }
    }
    return 0;
}
char toupper(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    return c;
}

int fat_create_file_entry(const char* filename, unsigned short start_cluster, unsigned int file_size) {
    unsigned int LBA_FAT = FAT12_LBA_OFFSET + g_bpb.BPB_RsvdSecCnt;
    unsigned int LBA_RDIR = LBA_FAT + (g_bpb.BPB_NumFATs * g_bpb.BPB_FATSz16);
    int root_dir_sectors = (g_bpb.BPB_RootEntCnt * 32) / SECTOR_SIZE;
    
    unsigned char root_dir_buffer[SECTOR_SIZE];
    DIR_Entry* entry;
    
    unsigned char fat_name[11] = "           ";
    int k = 0;
    for (int i = 0; i < strlen(filename); i++) {
        char current_char = filename[i];
        if (current_char == '.') {
            k = 8;
            continue;
        }
        if (k < 11) {
            fat_name[k++] = toupper(current_char);
        }
    }
    
    for (int i = 0; i < root_dir_sectors; i++) {
        if (read_sectors(LBA_RDIR + i, 1, root_dir_buffer) != 0) return -1;
        
        for (int j = 0; j < SECTOR_SIZE / sizeof(DIR_Entry); j++) {
            entry = (DIR_Entry*)&root_dir_buffer[j * sizeof(DIR_Entry)];
            
            if (entry->DIR_Name[0] == 0x00 || entry->DIR_Name[0] == 0xE5) {
                
                for (int l = 0; l < 11; l++) { entry->DIR_Name[l] = fat_name[l]; }
                entry->DIR_Attr = 0x20;
                entry->DIR_FstClus = start_cluster;
                entry->DIR_FileSize = file_size;
                if (write_sectors(LBA_RDIR + i, 1, root_dir_buffer) != 0) return -1;
                
                return 0;
            }
        }
    }
    
    return -1;
}
int create_file(const char* filename, const char* content, int len) {
    if (fat_read_bpb() != 0) return -1;
    
    int content_len = len;
    if (content_len > SECTOR_SIZE) content_len = SECTOR_SIZE;
    unsigned short start_cluster = fat_find_free_cluster();
    if (start_cluster == 0) return -1; 
    
    unsigned int lba_addr = fat_calc_lba(start_cluster);
    unsigned char sector_buffer[SECTOR_SIZE];
    for(int i = 0; i < SECTOR_SIZE; i++) sector_buffer[i] = 0; 
    
    for(int i = 0; i < content_len; i++) {
        sector_buffer[i] = content[i];
    }
    
    if (write_sectors(lba_addr, 1, sector_buffer) != 0) return -1;
    
    if (fat_create_file_entry(filename, start_cluster, content_len) != 0) return -1;
    
    return 0;
}
void run_app(const char* filename) {
    #define TEMP_BUFFER_SIZE 4096 
    char temp_buffer[TEMP_BUFFER_SIZE]; 
    int file_size = read_file(filename, temp_buffer, TEMP_BUFFER_SIZE);
    if (file_size < 0) {
        kprint("File not found or read error!", 0x4F00, vga+921);
        kpause();
        return;
    } 
    unsigned char* src = (unsigned char*)temp_buffer;
    unsigned char* dest = (unsigned char*)TARGET_LOAD_ADDR;
    for (int i = 0; i < file_size; i++) {
        dest[i] = src[i];
    }
    kclearscreen();
    run_assembly_code(TARGET_LOAD_ADDR);
    kprint("PRESS ANY KEY TO RETURN",0x4F00,vga);
    kpause(); 
}
void run_assembly_code(void* app_address) {
    __asm__ __volatile__ (
        "movl %%eax, %%esi\n"
        "call *%%esi\n"
        
        : 
        : "a" (app_address)
        : "esi"
    );
}
int delete_file(const char* filename) {
    if (fat_read_bpb() != 0) return -1;

    unsigned int LBA_FAT1 = FAT12_LBA_OFFSET + g_bpb.BPB_RsvdSecCnt;
    unsigned int LBA_RDIR = LBA_FAT1 + (g_bpb.BPB_NumFATs * g_bpb.BPB_FATSz16);
    int root_dir_sectors = (g_bpb.BPB_RootEntCnt * 32) / SECTOR_SIZE;

    unsigned char root_buffer[SECTOR_SIZE];
    DIR_Entry* entry;

    unsigned char fat_name[11];
    for (int i = 0; i < 11; i++) fat_name[i] = ' ';
    int idx = 0;
    int part = 0;
    for (int i = 0; filename[i] != '\0' && idx < 11; i++) {
        char c = filename[i];
        if (c == '.') { part = 1; idx = 8; continue; }
        if (part == 0 && idx < 8) fat_name[idx++] = toupper(c);
        else if (part == 1 && idx < 11) fat_name[idx++] = toupper(c);
    }

    unsigned short start_cluster = 0;
    int entry_sector = -1;
    int entry_index = -1;
    for (int s = 0; s < root_dir_sectors; s++) {
        if (read_sectors(LBA_RDIR + s, 1, root_buffer) != 0) return -1;
        for (int e = 0; e < SECTOR_SIZE / sizeof(DIR_Entry); e++) {
            entry = (DIR_Entry*)&root_buffer[e * sizeof(DIR_Entry)];
            unsigned char first = entry->DIR_Name[0];
            if (first == 0x00 || first == 0xE5) continue;
            int match = 1;
            for (int k = 0; k < 11; k++) {
                if (entry->DIR_Name[k] != fat_name[k]) { match = 0; break; }
            }
            if (match) {
                start_cluster = entry->DIR_FstClus;
                entry_sector = s;
                entry_index = e;
                goto found;
            }
        }
    }
    return -1;

found:
    if (read_sectors(LBA_RDIR + entry_sector, 1, root_buffer) != 0) return -1;
    entry = (DIR_Entry*)&root_buffer[entry_index * sizeof(DIR_Entry)];
    entry->DIR_Name[0] = 0xE5;
    if (write_sectors(LBA_RDIR + entry_sector, 1, root_buffer) != 0) return -1;

    unsigned int fat_size_bytes = g_bpb.BPB_FATSz16 * SECTOR_SIZE;
    if (fat_size_bytes > sizeof(g_fat_table)) {
        return -1;
    }
    for (unsigned int sec = 0; sec < g_bpb.BPB_FATSz16; sec++) {
        if (read_sectors(LBA_FAT1 + sec, 1, g_fat_table + sec * SECTOR_SIZE) != 0)
            return -1;
    }

    unsigned short cur = start_cluster;
    while (cur >= 2 && cur < 0xFF8) {
        unsigned int offset = cur + (cur / 2);
        unsigned int byte_index = offset;
        if (byte_index + 1 >= fat_size_bytes) break;

        unsigned short entry_val = g_fat_table[byte_index] | (g_fat_table[byte_index + 1] << 8);
        unsigned short next;
        if (cur & 1) {
            next = entry_val >> 4;
        } else {
            next = entry_val & 0x0FFF;
        }

        if (cur & 1) {
            entry_val = entry_val & 0x000F;
        } else {
            entry_val = entry_val & 0xF000;
        }

        g_fat_table[byte_index] = entry_val & 0xFF;
        g_fat_table[byte_index + 1] = (entry_val >> 8) & 0xFF;

        cur = next;
    }

    for (unsigned int sec = 0; sec < g_bpb.BPB_FATSz16; sec++) {
        if (write_sectors(LBA_FAT1 + sec, 1, g_fat_table + sec * SECTOR_SIZE) != 0)
            return -1;
    }
    unsigned int LBA_FAT2 = LBA_FAT1 + g_bpb.BPB_FATSz16;
    for (unsigned int sec = 0; sec < g_bpb.BPB_FATSz16; sec++) {
        if (write_sectors(LBA_FAT2 + sec, 1, g_fat_table + sec * SECTOR_SIZE) != 0)
            return -1;
    }

    return 0;
}
int file_exists(const char* filename) {
    if (fat_read_bpb() != 0) return 0;

    unsigned int LBA_FAT = FAT12_LBA_OFFSET + g_bpb.BPB_RsvdSecCnt;
    unsigned int LBA_RDIR = LBA_FAT + (g_bpb.BPB_NumFATs * g_bpb.BPB_FATSz16);
    int root_dir_sectors = (g_bpb.BPB_RootEntCnt * 32) / SECTOR_SIZE;

    unsigned char root_dir_buffer[SECTOR_SIZE];
    DIR_Entry* entry;

    unsigned char fat_name[11];
    for (int i = 0; i < 11; i++) fat_name[i] = ' ';
    int idx = 0, part = 0;
    for (int i = 0; filename[i] != '\0' && idx < 11; i++) {
        char c = filename[i];
        if (c == '.') { part = 1; idx = 8; continue; }
        if (part == 0 && idx < 8) fat_name[idx++] = toupper(c);
        else if (part == 1 && idx < 11) fat_name[idx++] = toupper(c);
    }

    for (int s = 0; s < root_dir_sectors; s++) {
        if (read_sectors(LBA_RDIR + s, 1, root_dir_buffer) != 0) return 0;
        for (int e = 0; e < SECTOR_SIZE / sizeof(DIR_Entry); e++) {
            entry = (DIR_Entry*)&root_dir_buffer[e * sizeof(DIR_Entry)];
            if (entry->DIR_Name[0] == 0x00 || entry->DIR_Name[0] == 0xE5) continue; // üres vagy törölt
            int match = 1;
            for (int k = 0; k < 11; k++) {
                if (entry->DIR_Name[k] != fat_name[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) return 1;
        }
    }

    return 0;
}
int hex_char_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}
int hex_to_byte(const char* str) {
    int hi = hex_char_to_int(str[0]);
    int lo = hex_char_to_int(str[1]);
    if (hi < 0 || lo < 0) return -1;
    return (hi << 4) | lo;
}
void kputchar(char character, unsigned color, volatile unsigned short* addr) {
    *addr = (unsigned short)(character | color);
}
#include "apps.c"