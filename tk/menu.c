//
// Created by uwu on 12/18/2020.
//

#include "menu.h"

enum {
    MAIN_MENU = 0,
    TABLE = 1,
    TAB_DMX = 3,
    TAB_ERR = 5,
    TAB_INF = 7,
    TAB_SET = 9
};

struct {
    unsigned char screen_id : 6, selected : 6, editing: 1, locked: 1;
} state = {0, 0, 0, 0};

void draw_btns(const char a[], int len_a,
               const char b[], int len_b,
               const char c[], int len_c,
               const char d[], int len_d) {

    draw_rect(1, HEIGHT-16, WIDTH/4-1, 16, 1);
    draw_text(a, len_a, (WIDTH/8) - (len_a*4), HEIGHT-14, 0);

    draw_rect(1+WIDTH/4, HEIGHT-16, WIDTH/4-1, 16, 1);
    draw_text(b, len_b, (WIDTH/8) - (len_b*4)+WIDTH/4, HEIGHT-14, 0);

    draw_rect(1+WIDTH/2, HEIGHT-16, WIDTH/4-1, 16, 1);
    draw_text(c, len_c, (WIDTH/8) - (len_c*4)+WIDTH/2, HEIGHT-14, 0);

    draw_rect(1+(WIDTH*3)/4, HEIGHT-16, WIDTH/4-1, 16, 1);
    draw_text(d, len_d, (WIDTH/8) - (len_d*4)+(3*WIDTH)/4, HEIGHT-14, 0);
}

const row rows[] = {
        (row){"ASD", 3, 3, "LOL"},
        (row){"BAD", 3, 3, "MRU"},
        (row){"MJA", 3, 3, "KYA"},
};

const table tables[] = {
        {3, rows},
        {1,(row[]){
                {"ASD", 3, 3, "MEW"}
            }
        }
};

int get_rows(char tabid) {
    switch (tabid) {
        case TAB_DMX:
            return 1;
        default:
            return 0;
    }
}

const row menu_items[] = {
        (row){"RDM/DMX", 7, 128, TEST},
        (row){"ERROR", 5, 128, TEST},
        (row){"INFO", 4, 128, TEST},
        (row){"SETTINGS", 8, 128, TEST}
};

void draw_menu() {
    if (state.screen_id == MAIN_MENU) {
        draw_btns("LOK", 3, "PRE", 3, "NEX", 3, "GO", 2);
        // Because I'm lazy enough to do it by hand, here it is
        // 128/4 = 32 (centers)
        // 0   32   64   96   128
        // |    |    |    |    |
        //
        // WIDTH/4
        // 32/2-8
        // i*WIDTH/4-WIDTH/8-8
        //
        draw_rect((1 + state.selected) * WIDTH / 4 - WIDTH / 8 - 9, 7, 18, 18, 1);
        draw_bmp(ICONS, WIDTH / 4 - WIDTH / 8 - 8, 8, 2, 16, state.selected == 0 ? 0 : 1);
        draw_bmp(ICONS + 16 * 2, 2 * WIDTH / 4 - WIDTH / 8 - 8, 8, 2, 16, state.selected == 1 ? 0 : 1);
        draw_bmp(ICONS + 16 * 2 * 2, 3 * WIDTH / 4 - WIDTH / 8 - 8, 8, 2, 16, state.selected == 2 ? 0 : 1);
        draw_bmp(ICONS + 16 * 2 * 3, 4 * WIDTH / 4 - WIDTH / 8 - 8, 8, 2, 16, state.selected == 3 ? 0 : 1);
        draw_text(menu_items[state.selected].right,
                  menu_items[state.selected].right_len,
                  CENTER(WIDTH, 8 * menu_items[state.selected].right_len),
                  8 + 16 + 8,
                  1);
    } else if ((state.screen_id & TABLE) != 0) {
        if (state.editing == 0)
            draw_btns("BAC", 3, "DOW", 3, "UP", 2, "EDT", 3);
        else
            draw_btns("", 0, "-", 1, "+", 1, "SVE", 3);
        table t = tables[get_rows(state.screen_id)];
        draw_table(t.rows, t.len, 128, 64-16, 0, 0, state.selected, state.editing==1?2:1);
    }
    update_display();
}

void send_msg(char msg) {
     if (state.screen_id == MAIN_MENU) {
         switch (msg) {
             case MSG_BTN_B:
                 state.selected = (state.selected-1+4)%4;
                 break;
             case MSG_BTN_C:
                 state.selected = (state.selected+1)%4;
                 break;
             case MSG_BTN_D:
                 state.screen_id = (state.selected * 2 + 3);
                 state.selected = 0;
             break;
         }
         clear_display();
         draw_menu();
     } else if ((state.screen_id & TABLE) != 0) {
         if (state.editing == 0) {
             table t = tables[get_rows(state.screen_id)];
             switch (msg) {
                 case MSG_BTN_A:
                     state.selected = (state.screen_id - 3) / 2;
                     state.screen_id = MAIN_MENU;
                     break;
                 case MSG_BTN_B:
                     state.selected = (state.selected-1+t.len) % t.len;
                     break;
                 case MSG_BTN_C:
                     state.selected = (state.selected+1) % tables[get_rows(state.screen_id)].len;
                     break;
                 case MSG_BTN_D:
                     if (state.screen_id != TAB_INF)
                        state.editing = 1;
                     break;
                 default:
                     break;
             }
         } else {
             switch (msg) {
                 case MSG_BTN_B:
                     break;
                 case MSG_BTN_C:
                     break;
                 case MSG_BTN_D:
                     state.editing = 0;
                     break;
                 default:
                     break;
             }
         }
         clear_display();
         draw_menu();
     }
}