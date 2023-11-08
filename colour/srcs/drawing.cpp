#include "../includes/colour.h"

void segments(SdlData& Sdl, vector<Segment>& colours) {
    float radius;
    int radius_tot = WHEEL_RADIUS;
    int k = 0;
    float start_angle = 0;
    float segment_angle = 6.283185307f * 0.08333333f; //shorten, segment: 6.283f / 12
    float end_angle = segment_angle;

    while (k < COLOURS_COUNT) {
        radius = 0.5;
        while (radius < radius_tot) {
            colours[k].drawArc(Sdl, radius, SCRN_W_BASE / 2, SCRN_H_BASE / 2, start_angle, end_angle,
                        colours[k].mR, colours[k].mG, colours[k].mB);
            radius = radius + 0.5;
        }
        start_angle = start_angle + segment_angle;
        end_angle = end_angle + segment_angle;
        k++;
    }
}

void perimeter(SdlData& Sdl, Perimeter& Perim) {
    int i = 0;
    int radius = WHEEL_RADIUS;

    while (i < PERIMETER_THICKNESS) {
        Perim.drawPerimeter(Sdl, radius, SCRN_W_BASE / 2, SCRN_H_BASE / 2);
        radius++;
        i++;
    }
}

void drawing(SdlData& Sdl, Perimeter& Perim, vector<Segment>& colours) {

    perimeter(Sdl, Perim);
    segments(Sdl, colours);
    


}
