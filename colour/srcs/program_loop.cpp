#include "../includes/colour.h"

//do as last, interest was in colouring
void input(SDL_Event &event) {
    if (event.key.keysym.sym == SDLK_ESCAPE)
        exit(0);
    else if(event.key.keysym.sym == SDLK_f)
        cout << "F" << endl;
}


/*
    Program loop. Ends when ESC is pressed.
*/
void    program_loop(SdlData& Sdl, Perimeter& Perim, vector<Segment>& colours) {
    SDL_Event event;
    bool quit = false;

    while(quit == false) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN)
                input(event);
            else if(event.type == SDL_MOUSEBUTTONDOWN) 
                if (event.button.button == SDL_BUTTON_LEFT)
                    cout << "M1 is clicked once" << endl;

            SDL_SetRenderDrawColor(Sdl.mRenderer, 0x00, 0x00, 0x00, 0x00);
            SDL_RenderClear(Sdl.mRenderer);
            drawing(Sdl, Perim, colours);
            SDL_RenderPresent(Sdl.mRenderer);
        }
    }
}