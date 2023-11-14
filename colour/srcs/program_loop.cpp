#include "../includes/colour.h"

/*
    Program loop. Ends when ESC is pressed.
*/
void    program_loop(SdlData& sdl, Perimeter& perim, Selector& selec, vector<Segment>& colours, 
                KeyEvent& keyPress, OutputObject& rectangle) {
    SDL_Event event;
    bool quit = false;

    while(quit == false) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
            else if (event.type == SDL_KEYDOWN)
                keyPress.detectKey(sdl, event, selec, rectangle);
            SDL_SetRenderDrawColor(sdl.mRenderer, 0x00, 0x00, 0x00, 0x00);
            SDL_RenderClear(sdl.mRenderer);
            drawing(sdl, perim, selec, colours, rectangle);
            SDL_RenderPresent(sdl.mRenderer);
        }
    }
}
