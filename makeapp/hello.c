void kprint(const char* str, unsigned color, volatile unsigned short* start_addr) {
    int i = 0;
    while (str[i]) {
        start_addr[i] = (unsigned short)(str[i] | color);
        i++;
    }
}
void hello(void) {
    kprint("Hello, kernel world!\n", 0x0F00, (unsigned short *)0xB8000);
    return;
}
