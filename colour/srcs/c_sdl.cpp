#include "../includes/colour.h"

SdlData::SdlData(SDL_Window *window, SDL_Renderer *renderer) {
    createWindow(window);
    createRenderer(renderer);
}

/*
    Initiate SDL connection.
*/
void SdlData::createWindow(SDL_Window *window) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "fail init" << endl;
        exit(0);
    }
    else {
        mWindow = SDL_CreateWindow("Colour", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCRN_W_BASE, SRCN_H_BASE, SDL_WINDOW_SHOWN);
        if (mWindow = NULL) {
            cout << "window fail" << endl;
            exit(0);
        }
    }
}

/*
    SDL2 Renderer
*/
void SdlData::createRenderer(SDL_Renderer *renderer) {
    mRenderer = SDL_CreateRenderer(getWindow(), -1, SDL_RENDERER_ACCELERATED);
    if (mRenderer == NULL) {
        cout << "renderer fail" << endl;
        exit(0);
    }
    SDL_SetRenderDrawColor(getRenderer(), 0x00, 0x00, 0x00, 0x00);
    /* this shouldnt be needed as dont use images
    int imgFlag = IMG_INT_PNG;
    if (!(IMG_Init(imgFlags) && imgFlags))
        cout << "IMG_Init fail" << endl;
        exit(0);
    */
}

SdlData::~SdlData() {
}