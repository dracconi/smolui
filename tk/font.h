//
// Created by uwu on 12/18/2020.
//

#ifndef SMOLUI_FONT_H
#define SMOLUI_FONT_H

#include "bitmap.h"
#include "bitmaps.h"

#define FONT_SIZEW 8
#define FONT_SIZEH 12

void draw_text(byte* str, int len, int x, int y, char mode);
void draw_char(byte chr, int x, int y, char mode);


// font size: 8x12 +-/0-9A-Z
// translate_char : matches with ranges and returns new index

#endif //SMOLUI_FONT_H
