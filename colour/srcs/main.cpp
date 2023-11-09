#include "../includes/colour.h"

//put Perimeters to vector<Perimeter> circles;
int main() {
    SdlData sdl = SdlData();
    Perimeter perim;
    Selector selec = Selector();
    vector<Segment> colours;
    KeyEvent keyPress;

    fill_vector(colours);    
    program_loop(sdl, perim, selec, colours, keyPress);
    return 0;
}