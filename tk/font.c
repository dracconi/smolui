//
// Created by uwu on 12/18/2020.
//

#include "font.h"

char translate_char(byte chr) {
    if (chr >= 48 && chr <= 57) {
        return chr-48;
    }
    if (chr >= 65 && chr <= 90) {
        return chr-65+15;
    }
    if (chr == '.')
        return 11;
    if (chr == '+')
        return 13;
    if (chr == '-')
        return 12;
    if (chr == '/')
        return 14;
    return 10; // empty
}

void draw_char(byte chr, int x, int y, char mode) {
    draw_bmp(FONT+translate_char(chr)*12, x, y, 1, 12, mode);
}

void draw_text(byte* str, int len, int x, int y, char mode) {
    int ix = 0;
    while (len > 0) {
        draw_char(*str, x+8*ix, y, mode);
        str++;
        ix++;
        len--;
    }
}