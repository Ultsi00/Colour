#ifndef COLOUR_H
#define COLOUR_H
#include "SDL2/SDL.h"
#include "data.h"
#include "classes.h"
#include "math.h"
#include <vector>
#include <iostream>

using namespace std;

void    program_loop(SdlData &sdl, Perimeter& perim, Selector& selec,
                vector<Segment>& colours, KeyEvent& keyPress, OutputObject& rectangle);
void    drawing(SdlData& sdl, Perimeter& perim, Selector& selec, 
                vector<Segment>& colours, OutputObject& rectangle);
void    fill_vector(vector<Segment>& colours);

#endif