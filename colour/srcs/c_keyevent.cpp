#include "../includes/colour.h"

class Selector;

void KeyEvent::detectKey(SDL_Event& event, Selector& selec) {
    if (event.key.keysym.sym == SDLK_ESCAPE) {
        cout << "ESC" << endl;
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
    }
    else if(event.key.keysym.sym == SDLK_UP) {
        cout << "saturation up" << endl;
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
