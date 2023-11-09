#include "../includes/colour.h"

class SdlData;

/*
    Parent class
*/
void Draw::setColour(uint16_t r, uint16_t g, uint16_t b) {
    mR = r;
    mG = g;
    mB = b;
}

/*
    Segment : Draw
*/
Segment::Segment(uint16_t r, uint16_t g, uint16_t b, float angle, int radius) {
    setColour(r, g, b);
    setAngle(angle);
    setRadius(radius);
}

void Segment::drawSegment(SdlData& sdl, float start_angle, float end_angle) {
    float r_iter = RADIUS_ITER;

    while (r_iter < this->getRadius()) {
        this->drawArc(sdl, r_iter, SCRN_W_BASE / 2, SCRN_H_BASE / 2, start_angle, end_angle);
        r_iter = r_iter + 0.5;
    }
}

void Segment::drawArc(SdlData&sdl, float radius, int origo_x, int origo_y,
                float start_angle, float end_angle)
{
    int x = 0, y = 0;
    float angle_inc = 1.0f / radius;
    float angle = start_angle;
    while (angle <= end_angle) {
        x = origo_x + (int)(radius * cos(angle));
        y = origo_y - (int)(radius * sin(angle));
        SDL_SetRenderDrawColor(sdl.mRenderer, this->mR, this->mG, this->mB, 0x00);
        SDL_RenderDrawPoint(sdl.mRenderer, x, y);
        angle = angle + angle_inc;
    }
}

Segment::~Segment() {
}

/*
    Perimeter : Draw

    MidPoint Circle Algorithm
*/
void Perimeter::drawPerimeter(SdlData& sdl, float radius, int origo_x, int origo_y) {
    int diameter = (int)(radius * 2);
    int x = (radius - 1), y = 0, tx = 1, ty = 1;
    int error = (tx - diameter);

    SDL_SetRenderDrawColor(sdl.mRenderer, 0xFF, 0xFF, 0xFF, 0x00);
    while (x >= y) {
        SDL_RenderDrawPoint(sdl.mRenderer, origo_x + x, origo_y - y);
        SDL_RenderDrawPoint(sdl.mRenderer, origo_x + x, origo_y + y);
        SDL_RenderDrawPoint(sdl.mRenderer, origo_x - x, origo_y - y);
        SDL_RenderDrawPoint(sdl.mRenderer, origo_x - x, origo_y + y);
        SDL_RenderDrawPoint(sdl.mRenderer, origo_x + y, origo_y - x);
        SDL_RenderDrawPoint(sdl.mRenderer, origo_x + y, origo_y + x);
        SDL_RenderDrawPoint(sdl.mRenderer, origo_x - y, origo_y - x);
        SDL_RenderDrawPoint(sdl.mRenderer, origo_x - y, origo_y + x);
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

/*
    Selector : Perimeter (=child of Draw)
*/
Selector::Selector() {
    setPos(SEGMENT_ANGLE, 0.5);
    mSelected_colour = 0;
}

/*
    multiplier is 0.5 only at initialization, else 1.
    This is for focusing the selecter in the middle of a colour segment angle.
    1 acts as a step for moving from one segment to another.
*/
void Selector::setPos(float angle, float multiplier) {
    this->mAngle = angle * multiplier;
    this->mOrigoX = (SCRN_W_BASE / 2) + (int)(RADIUS_ORBIT * cos(this->mAngle));
    this->mOrigoY = (SCRN_H_BASE / 2) - (int)(RADIUS_ORBIT * sin(this->mAngle));
}

void Selector::drawSelector(SdlData& sdl) {
    float radius = SELECTOR_RADIUS;

    while (radius < (SELECTOR_RADIUS + SELECTOR_THICKNESS)) {
        this->drawPerimeter(sdl, radius, this->mOrigoX, this->mOrigoY);
        radius = radius + 0.5;
    }
}

void Selector::changePos(int dir) {
    if (dir == 1) {
        this->mAngle = this->mAngle + SEGMENT_ANGLE;
        setPos(this->mAngle, 1);
        if (mSelected_colour >= 0 && mSelected_colour < 11)
            mSelected_colour++;
        else if(mSelected_colour == 11)
            mSelected_colour = 0;
    }
    else if(dir == -1) {
        this->mAngle = this->mAngle - SEGMENT_ANGLE;
        setPos(this->mAngle, 1);
        if (mSelected_colour > 0 && mSelected_colour <= 11)
            mSelected_colour--;
        else if(mSelected_colour == 0)
            mSelected_colour = 11;
    }
}

Selector::~Selector(){
}
