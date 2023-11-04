#include "../includes/colour.h"

static void init_renderer(t_sdl *sdl) {
   sdl->renderer = SDL_CreateRenderer(sdl->window, -1, SDL_RENDERER_ACCELERATED);
    if (!sdl->renderer)
        exit_prgm(sdl, "sdl_init(): SDL_CreateRenderer() fail.");
    SDL_SetRenderDrawColor(sdl->renderer, 0x11, 0x44, 0x23, 0x00);
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) && imgFlags))
        exit_prgm(sdl, "sdl_init(): IMG_Init() fail.");
}

/*
    Initiate SDL connection.
*/
void    sdl_init(t_sdl *sdl) {
    sdl->window = NULL;
    sdl->renderer = NULL;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        exit_prgm(sdl, "sdl_init(): SDL_INIT fail.");
    else {
        sdl->window = SDL_CreateWindow("embed", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (sdl->window == NULL)
            exit_prgm(sdl, "sdl_init(): SDL_CreateWindow() fail.");
        init_renderer(sdl);
	}
}