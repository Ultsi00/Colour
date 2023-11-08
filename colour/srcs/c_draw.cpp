#include "../includes/colour.h"

class SdlData;

Draw::Draw() {
}

void Draw::setColour(uint16_t r, uint16_t g, uint16_t b) {
    mR = r;
    mG = g;
    mB = b;
}

Draw::~Draw() {
}

Segment::Segment(uint16_t r, uint16_t g, uint16_t b) {
    setColour(r, g, b);
}

void Segment::drawArc(SdlData& Sdl, float radius, int origo_x, int origo_y, float start_angle, float end_angle,
                uint16_t r, uint16_t g, uint16_t b)
    {
    int x = 0, y = 0;
    float angle_inc = 1.0f / radius;
    float angle = start_angle;
    while (angle <= end_angle) {
        x = origo_x + (int)(radius * cos(angle));
        y = origo_y - (int)(radius * sin(angle));
        //this->mColour. Then can remove colour from f(arg)
        SDL_SetRenderDrawColor(Sdl.mRenderer, r, g, b, 0x00);
        SDL_RenderDrawPoint(Sdl.mRenderer, x, y);
        angle = angle + angle_inc;
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
