//
// Created by uwu on 12/18/2020.
//

#include "table.h"

int divide(const row *rows, int len) {
    int max = 0;
    while (len > 0) {
        if (rows->right_len > max)
            max = rows->right_len;
        rows++;
        len--;
    }
    return max;
}

void draw_row(row r, int w, int h, int x, int y, int divide, int active) {
    draw_rect(x, y, divide, h, active==1?1:0);
    draw_text(r.left, r.left_len, 0, y, active==1?0:1);
    draw_rect(divide, y, w-divide, h, active==2?1:0);
    draw_text(r.right, r.right_len, divide, y, active==2?0:1);
}

void draw_table(const row rows[], int len, int w, int h, int x, int y, int active, int mode) {
    int div = w-8*divide(rows, len);
    int elem_num = h/16;
    int offset = active - elem_num/2;
    int ix;
    for (ix = 0; ix < elem_num; ix++) {
        draw_row(rows[(offset + ix + len) % len], w, 16, x, y + 16*ix, div, ((offset+ix+len) % len)==active?mode:0);
    }
}

