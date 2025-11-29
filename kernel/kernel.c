kk@kk-ESPRIMO-P710:~/kaktuszOS$ cat kernel/kernel.c 
//előre létrehozott változók
volatile unsigned short* vga = (volatile unsigned short*)0xB8000;
//prototípusok
void clearscreen(void);
void kprint(const char* str, unsigned color, volatile unsigned short* start_addr);
void init_gui(void);
//main
void kmain(void) {
    init_gui();
    while (1) {}
};
//fügvények
void init_gui(void) {
    clearscreen();
    kprint("+--+--+--++--+--+--+", 0x0E00, vga+30);
    kprint("+--+--+--++--+--+--+", 0x0E00, vga+160+30);
    kprint("+--+--+--++--+--+--+", 0x0E00, vga+240+30);
}
void clearscreen(void) {
    for (int i = 0; i < 80*25; i++) {
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
