#ifndef COLOUR_H
#define COLOUR_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "data.h"
#include "classes.h"
#include "math.h"
#include <vector>
#include <iostream>

using namespace std;

//functions
void    program_loop(SdlData &sdl, Perimeter& perim, Selector& selec,
                vector<Segment>& colours, KeyEvent& keyPress);
void    drawing(SdlData& sdl, Perimeter& perim, Selector& selec, vector<Segment>& colours);
void    fill_vector(vector<Segment>& colours);

//probably dont need after all, remove then
enum colour_names
{
    Magenta = 0,
    Rose = 1,
    Red = 2,
    Orange = 3,
    Yellow = 4,
    Chartreuse = 5,
    Green = 6,
    Aquamarine = 7,
    Cyan = 8,
    Azure = 9,
    Blue = 10,
    Violet = 11
};

#endif