#include "../includes/colour.h"

//do as last, interest was in colouring
void input(SDL_Event &event, SdlData& sdl, KeyEvent& keyPress, Selector& selec) {
    keyPress.detectKey(event, selec);

}


/*
    Program loop. Ends when ESC is pressed.
*/
void    program_loop(SdlData& sdl, Perimeter& perim, Selector& selec, vector<Segment>& colours, KeyEvent& keyPress) {
    SDL_Event event;
    bool quit = false;

    while(quit == false) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
            else if (event.type == SDL_KEYDOWN)
                input(event, sdl, keyPress, selec);
            SDL_SetRenderDrawColor(sdl.mRenderer, 0x00, 0x00, 0x00, 0x00);
            SDL_RenderClear(sdl.mRenderer);
            drawing(sdl, perim, selec, colours);
            SDL_RenderPresent(sdl.mRenderer);
        }
    }
}