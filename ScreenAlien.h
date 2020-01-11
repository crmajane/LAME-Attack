#ifndef SCREENALIEN_H
#define SCREENALIEN_H
#include "uLCD_4DGL.h"
extern uLCD_4DGL uLCD;
class ScreenAlien {
    static int alienNum;
    static int blackBox[88];

    public:
        ScreenAlien();
        void updatePos(int);
        void destroy();
        int kill();
        const int getxpos();
        const int getypos();
        
        virtual void drawAlien() = 0;
        virtual void updateAlien() = 0;
        int speed;
        //virtual void destroy() = 0;
    protected:
        bool movingRight;
        bool isDead;
        int xpos;
        int ypos;
};
#endif