#ifndef ALIENCARROT_H
#define ALIENCARROT_H
#include "ScreenAlien.h"
#include "mbed.h"
#include "uLCD_4DGL.h"
class AlienCarrot: public ScreenAlien {  

    public:
        AlienCarrot();
        void drawAlien();
        void updateAlien();
};
#endif