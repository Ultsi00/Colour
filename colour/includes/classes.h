#ifndef CLASSES_H
#define CLASSES_H
#include "colour.h"

//classes
class SdlData {
    public:
        SDL_Window *mWindow;
        SDL_Renderer *mRenderer;
        SdlData();
        ~SdlData();
        void createWindow();
        void createRenderer();
        SDL_Window *getWindow() { return(mWindow); }
};

#endif