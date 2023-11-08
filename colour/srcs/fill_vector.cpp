#include "../includes/colour.h"

/*
    Inserts colour segments to a vector container.
*/
void fill_vector(vector<Segment>& colours) {
    Segment Magenta = Segment(0xFF, 0x00, 0xFF);
    Segment Rose = Segment(0xFF, 0x00, 0x80);
    Segment Red = Segment(0xFF, 0x00, 0x00);
    Segment Orange = Segment(0xFF, 0x80, 0x00);
    Segment Yellow = Segment(0xFF, 0xFF, 0x00);
    Segment Chartreuse = Segment(0x80, 0xFF, 0x00);
    Segment Green = Segment(0x00, 0xFF, 0x00);
    Segment Aquamarine = Segment(0x00, 0xFF, 0x80);
    Segment Cyan = Segment(0x00, 0xFF, 0xFF);
    Segment Azure = Segment(0x00, 0x80, 0xFF);
    Segment Blue = Segment(0x00, 0x00, 0xFF);
    Segment Violet = Segment(0x80, 0x00, 0xFF);

    colours = {Magenta, Rose, Red, Orange, Yellow, Chartreuse,
        Green, Aquamarine, Cyan, Azure, Blue, Violet};
}