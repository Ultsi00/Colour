#include "../includes/colour.h"

/*
    Draws colour selector.
*/
void selector(SdlData& sdl, Selector& selec) {
    selec.drawSelector(sdl);

}

/*
    Draws colour segments.
*/
void segments(SdlData& sdl, vector<Segment>& colours) {
    int k = 0;
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
void perimeter(SdlData& sdl, Perimeter& perim) {
    int radius = WHEEL_RADIUS;

    while (radius < (WHEEL_RADIUS + PERIMETER_THICKNESS)) {
        perim.drawPerimeter(sdl, radius, SCRN_W_BASE / 2, SCRN_H_BASE / 2);
        radius++;
    }
}

/*
    Controls colour segment, perimeter and selector drawing.
*/
void drawing(SdlData& sdl, Perimeter& perim, Selector& selec, vector<Segment>& colours) {

    segments(sdl, colours);
    perimeter(sdl, perim);
    selector(sdl, selec);


}
