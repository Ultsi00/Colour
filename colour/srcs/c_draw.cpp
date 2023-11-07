#include "../includes/colour.h"

class SdlData;

Draw::Draw() {
}

Draw::~Draw() {
}

Segment::Segment(uint32_t colour) {
    setColour(colour);
}

void Segment::drawArc(SdlData& Sdl, float radius, int origo_x, int origo_y, uint32_t colour) {
    int centrex=200,centrey=200;// centre of circle in pixel coords
    // int radius=50;
    int xpos = 0;
    int ypos = 0;

    float two_pi=6.283f * 0.1666f;

    float angle_inc=1.0f/radius;
    for(float angle=0.0f; angle<= two_pi;angle+=angle_inc){
        xpos= centrex + (int)(radius * cos(angle));
        ypos= centrey + (int)(radius * sin(angle));
        //this->mColour. Then can remove colour from f(arg)
        SDL_SetRenderDrawColor(Sdl.mRenderer, 0x00, 0xFF, 0x00, 0x00); //need to break colour into components
        SDL_RenderDrawPoint(Sdl.mRenderer, xpos, ypos);
    }
}

Segment::~Segment() {
}

Perimeter::Perimeter() {
}

/*
    MidPoint Circle Algorithm
*/
void Perimeter::drawPerimeter(SdlData& Sdl, float radius, int origo_x, int origo_y) {
    int diameter = (int)(radius * 2);
    int x = (radius - 1), y = 0, tx = 1, ty = 1;
    int error = (tx - diameter);

    SDL_SetRenderDrawColor(Sdl.mRenderer, 0xFF, 0xFF, 0xFF, 0x00);
    while (x >= y) {
        SDL_RenderDrawPoint(Sdl.mRenderer, origo_x + x, origo_y - y);
        SDL_RenderDrawPoint(Sdl.mRenderer, origo_x + x, origo_y + y);
        SDL_RenderDrawPoint(Sdl.mRenderer, origo_x - x, origo_y - y);
        SDL_RenderDrawPoint(Sdl.mRenderer, origo_x - x, origo_y + y);
        SDL_RenderDrawPoint(Sdl.mRenderer, origo_x + y, origo_y - x);
        SDL_RenderDrawPoint(Sdl.mRenderer, origo_x + y, origo_y + x);
        SDL_RenderDrawPoint(Sdl.mRenderer, origo_x - y, origo_y - x);
        SDL_RenderDrawPoint(Sdl.mRenderer, origo_x - y, origo_y + x);
        if (error <= 0) {
            y = y + 1;
            error = error + ty;
            ty = ty + 2;
        }
        if (error > 0) {
            x = x - 1;
            tx = tx + 2;
            error = error + (tx - diameter);
        }
    }
}

Perimeter::~Perimeter() {
}
