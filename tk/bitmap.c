//
// Created by uwu on 12/18/2020.
//

#include "bitmap.h"

void draw_bmp(const byte bmp[], int x, int y, int w, int h, char mode) {
    unsigned int ix, jx, kx;
    for (ix = 0; ix < h; ix++) {
        for (jx = 0; jx < w; jx++) {
            for (kx = 0; kx < 8; kx++) {
                if ((bmp[ix*w+jx] & (0x80u>>kx)) != 0) {
                    if (mode == 1) {
                        set_pixel(x + jx * 8 + kx, ix+y);
                    } else {
                        clear_pixel(x + jx * 8 + kx, ix+y);
                    }
                }
            }
        }
    }
}
void draw_rect(int x, int y, int w, int h, char mode) {
    int ix, jx;
    for (ix = 0; ix < h; ix++) {
        for (jx = 0; jx < w; jx++) {
            if (mode == 1) {
                set_pixel(x + jx, ix+y);
            } else {
                clear_pixel(x + jx, ix+y);
            }
        }
    }
}
