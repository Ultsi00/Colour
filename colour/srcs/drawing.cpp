#include "../includes/colour.h"

/*
    Draws colour segments.
*/
static void segments(SdlData& sdl, vector<Segment>& colours) {
    uint8_t k = 0;
    float start_angle = START_ANGLE;
    float end_angle = colours[k].getAngle();

    while(k < COLOURS_COUNT) {
        colours[k].drawSegment(sdl, start_angle, end_angle);
        start_angle = start_angle + colours[k].getAngle();
        end_angle = end_angle + colours[k].getAngle();
        k++;
    }
}

/*
    Draws perimeter.
*/
static void perimeter(SdlData& sdl, Perimeter& perim) {
    float radius = WHEEL_RADIUS;

    while (radius < (WHEEL_RADIUS + PERIMETER_THICKNESS)) {
        perim.drawPerimeter(sdl, radius, SCRN_W_BASE / 2, SCRN_H_BASE / 2);
        radius++;
    }
}

/*
    Controls colour segment, perimeter and selector drawing.
*/
void drawing(SdlData& sdl, Perimeter& perim, Selector& selec, 
            vector<Segment>& colours, OutputObject& rectangle)
{
    selec.setCurrentColour(colours[selec.mSelectedColour]);
    selec.countSteps(colours[selec.mSelectedColour].mR, colours[selec.mSelectedColour].mG,
            colours[selec.mSelectedColour].mB);
    segments(sdl, colours);
    perimeter(sdl, perim);
    selec.drawSelector(sdl);
    rectangle.drawRectangle(sdl, selec.mRedRect, selec.mGreenRect, selec.mBlueRect);
}
