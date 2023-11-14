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

/**************************************************************************************/

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
        r_iter = r_iter + 0.333f;
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

/**************************************************************************************/

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

/**************************************************************************************/

/*
    Selector : Perimeter (=child of Draw)
*/
Selector::Selector() {
    setPos(SEGMENT_ANGLE, 0.5);
    mSelectedColour = 0, mSelectedColourPrev = 0;
    //Rectangle hue value at selector start position
    mRedRect = 0xFF, mGreenRect = 0x00, mBlueRect = 0xFF;
}

/*
    Multiplier is 0.5 only at initialization, else 1.
    This is for focusing the selector into the middle of a colour segment angle.
*/
void Selector::setPos(float angle, float multiplier) {
    this->mAngle = angle * multiplier;
    this->mOrigoX = (SCRN_W_BASE / 2) + (int)(RADIUS_ORBIT * cos(this->mAngle));
    this->mOrigoY = (SCRN_H_BASE / 2) - (int)(RADIUS_ORBIT * sin(this->mAngle));
}

/*
    Draws the hue selector at orbit.
*/
void Selector::drawSelector(SdlData& sdl) {
    float radius = SELECTOR_RADIUS;

    while (radius < (SELECTOR_RADIUS + SELECTOR_THICKNESS)) {
        this->drawPerimeter(sdl, radius, this->mOrigoX, this->mOrigoY);
        radius = radius + 0.5;
    }
}

/*
    Changes the selector position at orbit.
*/
void Selector::changePos(int dir) {
    if (dir == 1) {
        this->mAngle = this->mAngle + SEGMENT_ANGLE;
        setPos(this->mAngle, 1);
        if (mSelectedColour >= 0 && mSelectedColour < 11)
            mSelectedColour++;
        else if(mSelectedColour == 11)
            mSelectedColour = 0;
    }
    else if(dir == -1) {
        this->mAngle = this->mAngle - SEGMENT_ANGLE;
        setPos(this->mAngle, 1);
        if (mSelectedColour > 0 && mSelectedColour <= 11)
            mSelectedColour--;
        else if(mSelectedColour == 0)
            mSelectedColour = 11;
    }
}

/*
    Updates the current (rectangle) hue to correspond the selected colour
        wheel hue, if the hue selector has moved to a new position.
*/
void Selector::setCurrentColour(Segment& colour_current) {
    if (mSelectedColour != mSelectedColourPrev) {
        mRedRect = colour_current.mR;
        mGreenRect = colour_current.mG;
        mBlueRect = colour_current.mB;
        mSelectedColourPrev = mSelectedColour;
    }
}

/*
    Changes the hue saturation. Saturation change is allowed from the original
        hue value to white (255, 255, 255). Reverting back from the less saturated
        hue towards the original hue will stop when the original hue value has
        been reached.
*/
void Selector::changeSaturation(int saturation_change) {
    //saturation up
    if (saturation_change == 1) {
        if (mRedTemp > 0 && mRedTemp >= mRedAnchor) {
            mRedTemp = mRedTemp - SAT_CHANGE_MULTI * mRedStepSize;
            if (mRedTemp < 0)
                mRedTemp = 0;
            if (mRedTemp < mRedAnchor)
                mRedTemp = mRedAnchor;
        }
        if (mGreenTemp > 0 && mGreenTemp >= mGreenAnchor) {
            mGreenTemp = mGreenTemp - SAT_CHANGE_MULTI * mGreenStepSize;
            if (mGreenTemp < 0)
                mGreenTemp = 0;
            if (mGreenTemp < mGreenAnchor)
                mGreenTemp = mGreenAnchor;
        }
        if (mBlueTemp > 0 && mBlueTemp >= mBlueAnchor) {
            mBlueTemp = mBlueTemp - SAT_CHANGE_MULTI * mBlueStepSize;
            if (mBlueTemp < 0)
                mBlueTemp = 0;
            if (mBlueTemp < mBlueAnchor)
                mBlueTemp = mBlueAnchor;
            }
    }
    //saturation down
    else if(saturation_change == -1) {
        if (mRedTemp < 1) {
            mRedTemp = mRedTemp + SAT_CHANGE_MULTI * mRedStepSize;
            if (mRedTemp > 1)
                mRedTemp = 1;
        }
        if (mGreenTemp < 1) {
            mGreenTemp = mGreenTemp + SAT_CHANGE_MULTI * mGreenStepSize;
            if (mGreenTemp > 1)
                mGreenTemp = 1;
        }
        if (mBlueTemp < 1) {
            mBlueTemp = mBlueTemp + SAT_CHANGE_MULTI * mBlueStepSize;
            if (mBlueTemp > 1)
                mBlueTemp = 1;  
        }
    }
    mRedRect = (uint16_t)(mRedTemp * 255);
    mGreenRect = (uint16_t)(mGreenTemp * 255);
    mBlueRect = (uint16_t)(mBlueTemp * 255);
}

/*
    Counts how many steps each colour value, in the current hue, has between:
        current colour value <--> min saturation (all colour values 255).
    Colour wheel hues starts at max saturation.
*/
void Selector::countSteps(uint16_t r_hue, uint16_t g_hue, uint16_t b_hue) {
    uint8_t r_steps_ded, g_steps_ded, b_steps_ded;
    uint8_t highest_deduction;

    //These conditions are met when the selected hue has not undergone saturation change,
    // i.e. calculations are done only when the selector has changed position or is at
    // the starting position, until saturation undergoes changes.
    if (r_hue == mRedRect && g_hue == mGreenRect && b_hue == mBlueRect) {
        //distance between colour value and min saturation (255)
        r_steps_ded = abs(mRedRect - 255);
        g_steps_ded = abs(mGreenRect - 255);
        b_steps_ded = abs(mBlueRect - 255);

        //find highest deduction
        if (r_steps_ded >= g_steps_ded && r_steps_ded >= b_steps_ded && r_steps_ded != 0)
            highest_deduction = r_steps_ded;
        else if(g_steps_ded >= r_steps_ded && g_steps_ded >= b_steps_ded && g_steps_ded != 0)
            highest_deduction = g_steps_ded;
        else if(b_steps_ded >= r_steps_ded && b_steps_ded >= g_steps_ded && b_steps_ded != 0)
            highest_deduction = b_steps_ded;

        //calculate step_size = deduction_colour / highest_deduction_colour
        mRedStepSize = ((float)r_steps_ded / highest_deduction) / 255;
        mGreenStepSize = ((float)g_steps_ded / highest_deduction) / 255;
        mBlueStepSize = ((float)b_steps_ded / highest_deduction) / 255;
        setUnitRGB();
    }
}

/*
    Sets the selected hue from hex value to unit RGB value (0 <-> 1).
        _Temp is the value actively modified in saturation change,
        whereas _Anchor is the selected hue original value, above which
        overall saturation does not go.
*/
void Selector::setUnitRGB() {
    mRedTemp = 0, mGreenTemp = 0, mBlueTemp = 0;
    mRedAnchor = 0, mGreenAnchor = 0, mBlueAnchor = 0;
    mRedTemp = (float)mRedRect / 255;
    mGreenTemp = (float)mGreenRect / 255;
    mBlueTemp = (float)mBlueRect / 255;
    mRedAnchor = (float)mRedRect / 255;
    mGreenAnchor = (float)mGreenRect / 255;
    mBlueAnchor = (float)mBlueRect / 255;
}

Selector::~Selector(){
}

/**************************************************************************************/

/*
    OutputObject : Selector (=child of Perimeter(=child of Draw))
*/
OutputObject::OutputObject() {
    setPosAndArea(RECTANGLE_X, RECTANGLE_Y, (int)RECTANGLE_W, (int)RECTANGLE_H);
}

/*
    Sets rectangle x, y, w, h
*/
void OutputObject::setPosAndArea(int x, int y, int w , int h) {
    this->mRect = {x, y, w, h};
}

/*
    Draws the selected hue into a rectangle.
*/
void OutputObject::drawRectangle(SdlData& sdl, uint16_t r, uint16_t g, uint16_t b) {
    SDL_SetRenderDrawColor(sdl.mRenderer, r, g, b, 0xFF);
    SDL_RenderFillRect(sdl.mRenderer, &this->mRect);
}

OutputObject::~OutputObject() {
}
