#ifndef ALIENDEAN_H
#define ALIENDEAN_H
#include "ScreenAlien.h"
#include "mbed.h"
#include "uLCD_4DGL.h"
class AlienDean: public ScreenAlien {  

    public:
        AlienDean();
        void drawAlien();
        void updateAlien();
};
#endif