#include "../includes/embed.h"

/*
    Program loop. Ends when ESC is pressed.
*/
void    prgm_loop(t_sdl *sdl, vector<DevicePart> &txt_container,
            vector<DevicePart> &txt_nbs_container, Param &param) {
    sdl->quit = false;
    while(sdl->quit == false) {
        while(SDL_PollEvent(&sdl->event)) {
            if (sdl->event.type == SDL_QUIT)
                sdl->quit = true;
            else if (sdl->event.type == SDL_KEYDOWN)
                input(sdl, param);
            SDL_RenderClear(sdl->renderer);
            SDL_SetRenderDrawColor(sdl->renderer, 0x00, 0x00, 0x00, 0x00);
            render(sdl, txt_container, txt_nbs_container, param);
            SDL_RenderPresent(sdl->renderer);
        }
    }
}