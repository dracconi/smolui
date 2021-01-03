//
// Created by uwu on 12/18/2020.
//

#ifndef SMOLUI_MENU_H
#define SMOLUI_MENU_H

#define WIDTH 128
#define HEIGHT 64

#define CENTER(max, size) (((max)-(size))/2)

#include "font.h"
#include "table.h"
#include "bitmaps.h"

enum {
    MSG_BTN_A,
    MSG_BTN_B,
    MSG_BTN_C,
    MSG_BTN_D,
    MSG_LOCK,
    MSG_UNLOCK
};

void set_pixel(int x, int y);
void clear_pixel(int x, int y);
void update_display();
void clear_display();

void draw_menu();
void send_msg(char msg);

#endif //SMOLUI_MENU_H
