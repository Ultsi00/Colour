#include "../includes/colour.h"

/*
    Program loop. Ends when ESC is pressed.
*/
void    program_loop(SdlData& Sdl) {
    SDL_Event event;
    bool quit = false;

    while(quit == false) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            // else if (sdl->event.type == SDL_KEYDOWN)
            //     input(sdl, param);

            SDL_RenderClear(Sdl.mRenderer);
            SDL_SetRenderDrawColor(Sdl.mRenderer, 0x00, 0x00, 0x00, 0x00);
            //render()
            SDL_RenderPresent(Sdl.mRenderer);
        }
    }
}