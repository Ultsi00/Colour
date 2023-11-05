#include "../includes/colour.h"

SdlData::SdlData() {
    createWindow();
    createRenderer();
}

/*
    Initiate SDL2 connection.
*/
void SdlData::createWindow() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "SDL_Init fail" << endl;
        exit(0);
    }       
    else {
        mWindow = SDL_CreateWindow("Colour", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCRN_W_BASE, SRCN_H_BASE, SDL_WINDOW_SHOWN);
        if (!mWindow)
            this->SdlData::~SdlData();
    }
}

/*
    Initiate SDL2 Renderer
*/
void SdlData::createRenderer() {
    mRenderer = SDL_CreateRenderer(getWindow(), -1, SDL_RENDERER_ACCELERATED);
    if (!mRenderer)
        this->SdlData::~SdlData();
    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0x00);
}

SdlData::~SdlData() {
    cout << "Window and Renderer were destroyed" << endl;
    cout << "Exiting program" << endl;
}
