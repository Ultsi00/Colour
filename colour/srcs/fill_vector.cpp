#include "../includes/colour.h"

/*
    Inserts colour segments to a vector container.
*/
void fill_vector(vector<Segment>& colours) {
    Segment Magenta = Segment(0xFF00FF);
    Segment Rose = Segment(0xFF0080);
    Segment Red = Segment(0xFF0000);
    Segment Orange = Segment(0xFF8000);
    Segment Yellow = Segment(0xFFFF00);
    Segment Chartreuse = Segment(0x80FF00);
    Segment Green = Segment(0x00FF00);
    Segment Aquamarine = Segment(0x00FF80);
    Segment Cyan = Segment(0x00FFFF);
    Segment Azure = Segment(0x0080FF);
    Segment Blue = Segment(0x0000FF);
    Segment Violet = Segment(0x8000FF);

    colours = {Magenta, Rose, Red, Orange, Yellow, Chartreuse,
        Green, Aquamarine, Cyan, Azure, Blue, Violet};
}