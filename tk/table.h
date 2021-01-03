//
// Created by uwu on 12/18/2020.
//

#ifndef SMOLUI_TABLE_H
#define SMOLUI_TABLE_H

#include "menu.h"
#include <math.h>
#include "bitmap.h"
#include "font.h"


typedef struct {
    char *right;
    int right_len;
    int left_len;
    const char *left;
} row;

typedef struct {
    int len;
    row* rows;
} table;

void draw_table(const row rows[], int len, int w, int h, int x, int y, int active, int mode);

#endif //SMOLUI_TABLE_H
