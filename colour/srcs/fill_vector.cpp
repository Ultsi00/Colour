#include "../includes/colour.h"

/*
    Inserts colour segments to a vector container.
    By default, each colour segment has the same radius.
*/
void fill_vector(vector<Segment>& colours) {
    Segment magenta = Segment(0xFF, 0x00, 0xFF, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment rose = Segment(0xFF, 0x00, 0x80, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment red = Segment(0xFF, 0x00, 0x00, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment orange = Segment(0xFF, 0x80, 0x00, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment yellow = Segment(0xFF, 0xFF, 0x00, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment chartreuse = Segment(0x80, 0xFF, 0x00, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment green = Segment(0x00, 0xFF, 0x00, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment aquamarine = Segment(0x00, 0xFF, 0x80, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment cyan = Segment(0x00, 0xFF, 0xFF, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment azure = Segment(0x00, 0x80, 0xFF, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment blue = Segment(0x00, 0x00, 0xFF, SEGMENT_ANGLE, WHEEL_RADIUS);
    Segment violet = Segment(0x80, 0x00, 0xFF, SEGMENT_ANGLE, WHEEL_RADIUS);

    colours = {magenta, rose, red, orange, yellow, chartreuse,
        green, aquamarine, cyan, azure, blue, violet};
}