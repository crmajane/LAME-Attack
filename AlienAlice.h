#ifndef ALIENALICE_H
#define ALIENALICE_H
#include "ScreenAlien.h"
#include "mbed.h"
#include "uLCD_4DGL.h"
class AlienAlice: public ScreenAlien {  


//    int alienBobDown_sprite[ALIEN_HEIGHT * ALIEN_WIDTH];
//    int test[ALIEN_HEIGHT * ALIEN_WIDTH];
    public:
        AlienAlice();
        void drawAlien();
        void updateAlien();
        //void destroy();
};
#endif