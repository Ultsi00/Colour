#ifndef DATA_H
#define DATA_H
#include "colour.h"

#define SCRN_W_BASE 1280
#define SCRN_H_BASE 720
#define COLOURS_COUNT 12
#define WHEEL_RADIUS 200
#define PERIMETER_THICKNESS 10
#define START_ANGLE 0
#define SEGMENT_ANGLE (6.2831f * 0.0833f)
#define RADIUS_ITER 0.5
#define SELECTOR_RADIUS (WHEEL_RADIUS * 0.1)
#define SELECTOR_THICKNESS 2
#define RADIUS_ORBIT (WHEEL_RADIUS + PERIMETER_THICKNESS + 50)
#define RECTANGLE_X (SCRN_W_BASE / 2 + RADIUS_ORBIT + 100)
#define RECTANGLE_Y (SCRN_H_BASE / 2 - 100)
#define RECTANGLE_W (WHEEL_RADIUS * 0.5)
#define RECTANGLE_H (WHEEL_RADIUS * 0.5)
#define SAT_CHANGE_MULTI 2  //Only for speeding visualization. Set to 1 for iterating through all colour values 

#endif