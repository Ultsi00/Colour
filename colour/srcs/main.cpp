#include "../includes/colour.h"

int main() {
    SdlData sdl = SdlData();
    KeyEvent keyPress;
    vector<Segment> colours;
    Perimeter perim;
    Selector selec = Selector();
    OutputObject rectangle;

    fill_vector(colours);    
    program_loop(sdl, perim, selec, colours, keyPress, rectangle);
    return 0;
}