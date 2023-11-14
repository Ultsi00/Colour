#include "../includes/colour.h"

class Selector;

void KeyEvent::detectKey(SdlData& sdl, SDL_Event& event, Selector& selec, OutputObject& rectangle)
{
    if (event.key.keysym.sym == SDLK_ESCAPE) {       
        SDL_DestroyRenderer(sdl.mRenderer);
        sdl.mRenderer = NULL;
        SDL_DestroyWindow(sdl.mWindow);
        sdl.mWindow = NULL;
        exit(0);
    }
    else if(event.key.keysym.sym == SDLK_LEFT) {
        cout << "value down" << endl;
    }
    else if(event.key.keysym.sym == SDLK_RIGHT) {
        cout << "value up" << endl;
    }
    else if(event.key.keysym.sym == SDLK_DOWN) {
        cout << "saturation down" << endl;
        selec.changeSaturation(-1);
    }
    else if(event.key.keysym.sym == SDLK_UP) {
        cout << "saturation up" << endl;
        selec.changeSaturation(1);
    }
    else if(event.key.keysym.sym == SDLK_a) {
        cout << "selector counter-clockwise" << endl;
        selec.changePos(1);
    }
    else if(event.key.keysym.sym == SDLK_s) {
        cout << "selector clockwise" << endl;
        selec.changePos(-1);
    }
}
