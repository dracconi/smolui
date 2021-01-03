#include <stdio.h>

#include <SDL.h>
#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_scancode.h>
#include <SDL_keycode.h>
#include "tk/bitmaps.h"
#include "tk/menu.h"

SDL_Renderer *ren;

int main() {
    printf("Hello, World!\n");
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *w = SDL_CreateWindow("Test suite", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 256, 0);
    ren = SDL_CreateRenderer(w, 0, 0);
    SDL_SetRenderDrawColor(ren, 128, 128, 128, 255);
    SDL_RenderSetScale(ren, 4, 4);
    uint8_t cont = 1;
    draw_menu();
    while (cont == 1) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) {
                cont = 0;
            }
            if (ev.type == SDL_KEYUP) {
                if (ev.key.keysym.sym == SDLK_q)
                    send_msg(MSG_BTN_A);
                if (ev.key.keysym.sym == SDLK_w)
                    send_msg(MSG_BTN_B);
                if (ev.key.keysym.sym == SDLK_e)
                    send_msg(MSG_BTN_C);
                if (ev.key.keysym.sym == SDLK_r)
                    send_msg(MSG_BTN_D);
                if (ev.key.keysym.sym == SDLK_k)
                    send_msg(MSG_LOCK);
                if (ev.key.keysym.sym == SDLK_l)
                    send_msg(MSG_UNLOCK);
            }
        }
        SDL_Delay(1000/120);
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(w);
    SDL_Quit();
    return 0;
}

void update_display() {
    SDL_RenderPresent(ren);
}

void set_pixel(int x, int y) {
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    SDL_RenderDrawPoint(ren, x, y);
}

void clear_pixel(int x, int y) {
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderDrawPoint(ren, x, y);
}

void clear_display(){
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
}
