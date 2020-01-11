#ifndef ALIENBOB_H
#define ALIENBOB_H
#include "ScreenAlien.h"
#include "mbed.h"
#include "uLCD_4DGL.h"
class AlienBob: public ScreenAlien {  


//    int alienBobDown_sprite[ALIEN_HEIGHT * ALIEN_WIDTH];
//    int test[ALIEN_HEIGHT * ALIEN_WIDTH];
    public:
        AlienBob();
        void drawAlien();
        void updateAlien();
        //void destroy();
    private:
        bool armsUp;
        int count;
};
#endif