#include "../includes/colour.h"

void segments(SdlData& Sdl, vector<Segment>& colours) {
    float i = 0.02; //check which value is accurate enough to fill segment
    int radius = 50; //data.h
    
    // while ('colour# < colours_tot')
    // i = 0.02;
    while (i < radius) {
        //better to use 0-11, since can loop. If this, then remove enum.
        colours[Magenta].drawArc(Sdl, i, 200, 200, colours[Magenta].mColour);
        i = i + 0.02;
    }
    // colours['colourcode#'++]
}

void perimeter(SdlData& Sdl, Perimeter& Perim) {
    int perimeter_thickness = 20; // data.h
    int i = 0;
    int radius = 150; // data.h

    while (i < perimeter_thickness) {
        Perim.drawPerimeter(Sdl, radius, SCRN_W_BASE / 2, SRCN_H_BASE / 2);
        radius++;
        i++;
    }
}

void drawing(SdlData& Sdl, Perimeter& Perim, vector<Segment>& colours) {

    perimeter(Sdl, Perim);
    segments(Sdl, colours);
    


}
