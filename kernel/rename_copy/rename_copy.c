void copy(void) {
    char filename1[13];
    char filename2[13];
    char file_content[512];
    kpause();
    kinput2(886,filename1,sizeof(filename1));
    kpause();
    kinput2(886+13,filename2,sizeof(filename2));
    int size = read_file(filename1, file_content, sizeof(file_content));
    if (size > 0) {
        if (file_exists(filename2)) {
        kprint("Error: File already exists!", 0x4F00, vga + 921);
        kpause();
        return;
        }
        create_file(filename2,file_content,sizeof(file_content));
        kprint("File successfully created",0x0200,vga+921);
    } else {
        kprint("File not found or read error.", 0x4F00, vga + 921);
        kpause();
    }
}

void rename(void) {
    char filename1[13];
    char filename2[13];
    char file_content[512];
    kpause();
    kinput2(886,filename1,sizeof(filename1));
    kpause();
    kinput2(886+13,filename2,sizeof(filename2));
    int size = read_file(filename1, file_content, sizeof(file_content));
    if (size > 0) {
        if (file_exists(filename2)) {
        kprint("Error: File already exists!", 0x4F00, vga + 921);
        kpause();
        return;
        }
        create_file(filename2,file_content,sizeof(file_content));
        delete_file(filename1);
        kprint("File successfully created",0x0200,vga+921);
    } else {
        kprint("File not found or read error.", 0x4F00, vga + 921);
        kpause();
    }
}