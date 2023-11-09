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
        uint16_t mR;
        uint16_t mG;
        uint16_t mB;
        int mOrigoX;
        int mOrigoY;
        int mRadius;
        float mAngle;
        void setColour(uint16_t r, uint16_t g, uint16_t b);
        void setOrigoX(int origo_x) { mOrigoX = origo_x; }
        void setOrigoY(int origo_y) { mOrigoY = origo_y; }
        void setRadius(int radius) { mRadius = radius; }
        void setAngle(float angle) { mAngle = angle; }
        int getRadius() { return mRadius; }
        float getAngle() { return mAngle; }

};

class Segment : public Draw {
    public:
        Segment(uint16_t r, uint16_t g, uint16_t b, float angle, int radius);
        ~Segment();
        void drawSegment(SdlData& sdl, float start_angle, float end_angle);
        void drawArc(SdlData &sdl, float radius, int origo_x, int origo_y, float start_angle, float end_angle);
};

class Perimeter : public Draw {
    public:
        void drawPerimeter(SdlData &sdl, float radius, int origo_x, int origo_y);
};

class Selector : public Perimeter {
    public:
        int mSelected_colour;
        Selector();
        ~Selector();
        void drawSelector(SdlData& sdl);
        void setPos(float angle, float multiplier);
        void changePos(int dir);
};

class KeyEvent {
    public:
        void detectKey(SDL_Event& event, Selector& selec);

};

#endif