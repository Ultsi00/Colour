#ifndef CLASSES_H
#define CLASSES_H
#include "colour.h"

//classes
class SdlData {
    private:
        SDL_Window *mWindow;
        SDL_Renderer *mRenderer;
        //SDL_Event mEvent;
    public:
        SdlData(SDL_Window *window, SDL_Renderer *renderer);
        ~SdlData();
        void createWindow(SDL_Window *window);
        void createRenderer(SDL_Renderer *renderer);
        SDL_Window *getWindow() { return(mWindow); }
        SDL_Renderer *getRenderer() { return(mRenderer); }
        /*SDL_Event getEvent() { return(mEvent); }*/

};

#endif