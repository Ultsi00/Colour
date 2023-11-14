#ifndef CLASSES_H
#define CLASSES_H
#include "colour.h"

//SDL connection
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

//Object drawing classes
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
        inline void setOrigoX(int origo_x) { mOrigoX = origo_x; }
        inline void setOrigoY(int origo_y) { mOrigoY = origo_y; }
        inline void setRadius(int radius) { mRadius = radius; }
        inline void setAngle(float angle) { mAngle = angle; }
        inline int getRadius() { return mRadius; }
        inline float getAngle() { return mAngle; }

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
        uint8_t mSelectedColourPrev, mSelectedColour;
        uint16_t mRedRect, mGreenRect, mBlueRect;
        float mRedStepSize, mGreenStepSize, mBlueStepSize;
        float mRedTemp, mGreenTemp, mBlueTemp;
        float mRedAnchor, mGreenAnchor, mBlueAnchor;
        Selector();
        ~Selector();
        void setPos(float angle, float multiplier);
        void drawSelector(SdlData& sdl);
        void changePos(int dir);
        void setCurrentColour(Segment& colour_current);
        void changeSaturation(int saturation_change);
        void countSteps(uint16_t r_hue, uint16_t g_hue, uint16_t b_hue);
        void setUnitRGB();
};

class OutputObject : Selector {
    public:
        SDL_Rect mRect;
        OutputObject();
        ~OutputObject();
        void setPosAndArea(int x, int y, int w , int h);
        void drawRectangle(SdlData& sdl, uint16_t r, uint16_t g, uint16_t b);
};

//Key input
class KeyEvent {
    public:
        void detectKey(SdlData& sdl, SDL_Event& event, Selector& selec, OutputObject& rectangle);
};

#endif