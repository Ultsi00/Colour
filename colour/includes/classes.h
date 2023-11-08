#ifndef CLASSES_H
#define CLASSES_H
#include "colour.h"

class SdlData {
    public:
        SDL_Window *mWindow;
        SDL_Renderer *mRenderer;
        SdlData();
        ~SdlData();
        void createWindow();
        void createRenderer();
        SDL_Window *getWindow() { return(mWindow); }
};

class Draw {
    public:
        int mOrigoX;
        int mOrigoY;
        float mRadius;
        uint16_t mR;
        uint16_t mG;
        uint16_t mB;
        Draw();
        ~Draw();
        void setOrigoX(int origo_x) { mOrigoX = origo_x; }
        void setOrigoY(int origo_y) { mOrigoY = origo_y; }
        void setRadius(float radius) { mRadius = radius; }
        void setColour(uint16_t r, uint16_t g, uint16_t b);
};

class Segment : public Draw {
    public:
        Segment(uint16_t r, uint16_t g, uint16_t b);
        ~Segment();
        void drawArc(SdlData &Sdl, float radius, int origo_x, int origo_y, float start_angle, float end_angle,
                uint16_t r, uint16_t g, uint16_t b);
};

class Perimeter : public Draw {
    public:
        Perimeter();
        ~Perimeter();
        void drawPerimeter(SdlData &Sdl, float radius, int origo_x, int origo_y);
};

#endif