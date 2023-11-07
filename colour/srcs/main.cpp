#include "../includes/colour.h"

int main() {
    SdlData Sdl = SdlData();
    Perimeter Perim = Perimeter();
    vector<Segment> colours;
    
    fill_vector(colours);    
    program_loop(Sdl, Perim, colours);
    return 0;
}