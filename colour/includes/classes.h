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
        uint32_t mColour;
        Draw();
        ~Draw();
        void setOrigoX(int origo_x) { mOrigoX = origo_x; }
        void setOrigoY(int origo_y) { mOrigoY = origo_y; }
        void setRadius(float radius) { mRadius = radius; }
        void setColour(uint32_t colour) { mColour = colour; }
};

class Segment : public Draw {
    public:
        Segment(uint32_t colour);
        ~Segment();
        void drawArc(SdlData &Sdl, float radius, int origo_x, int origo_y, uint32_t colour);
};

class Perimeter : public Draw {
    public:
        Perimeter();
        ~Perimeter();
        void drawPerimeter(SdlData &Sdl, float radius, int origo_x, int origo_y);
};

#endif