int hatvany(int alap, int kitevo) {
    if (kitevo < 0) {
        return 0; 
    }
    if (kitevo == 0) {
        return 1;
    }
    int eredmeny = 1;
    for (int i = 0; i < kitevo; i++) {
        eredmeny *= alap; 
    }
    return eredmeny;
}
void calc(void) {
    int on = 1;
    kpause();
    while(on){
        kclearscreen();
        kprint("+-------------------+",0x0F00,vga);
        kprint("|new calc(1/0):     |",0x0F00,vga+80);
        kprint("|                   |",0x0F00,vga+160);
        kprint("|first number:      |",0x0F00,vga+240);
        kprint("|                   |",0x0F00,vga+320);
        kprint("|second number:     |",0x0F00,vga+400);
        kprint("|                   |",0x0F00,vga+480);
        kprint("|operator:          |",0x0F00,vga+560);
        kprint("|                   |",0x0F00,vga+640);
        kprint("|result:            |",0x0F00,vga+720);
        kprint("|                   |",0x0F00,vga+800);
        kprint("+-------------------+",0x0F00,vga+880);
        int eredmeny;
        char szeredmeny[32] = {0};
        int knum1 = 0;
        int knum2 = 0;
        char bnum1[32] = {0};
        char bnum2[32] = {0};
        char muvelet[3] = {0};
        char newcalc[2] = {0};
        kinput(161, newcalc, sizeof(newcalc));
        if (strcmp(newcalc, "0") == 0){
            on = 0;
        } 
        else if (strcmp(newcalc, "1") == 0) {
            kpause();
            kinput(321, bnum1, sizeof(bnum1));
            kpause();
            kinput(481, bnum2, sizeof(bnum2));
            kpause();
            kinput(641, muvelet, sizeof(muvelet));
            string_to_int(bnum1, &knum1);
            string_to_int(bnum2, &knum2);
            if (strcmp(muvelet, "+") == 0) {
                eredmeny = knum1 + knum2;
            }
            else if (strcmp(muvelet, "-") == 0) {
                eredmeny = knum1 - knum2;
            }
            else if (strcmp(muvelet, "*") == 0) {
                eredmeny = knum1 * knum2;
            }
            else if (strcmp(muvelet, "/") == 0) {
                if (knum2 != 0) {
                    eredmeny = knum1 / knum2;
                } else {
                    kprint("DIV BY ZERO", 0x4F00, vga+801);
                    kpause();
                    kpause();
                    continue;
                }
            }
            else if (strcmp(muvelet, "**") == 0) {
                eredmeny = hatvany(knum1, knum2);
            }
            else {
                kprint("OP ERROR", 0x4F00, vga+801);
                kpause();
                kpause();
                continue; 
            }
            int_to_string(eredmeny, szeredmeny);
            kprint(szeredmeny, 0x0F00, vga + 801);
            kpause();
            kpause();
        } else {
            kprint("Invalid input (0/1)", 0x4F00, vga+801);
            kpause();
            kpause();
        }
    }
}