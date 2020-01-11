#include "AlienDean.h"


uLCD_4DGL extern uLCD;

#define _ 0x000000 //BLACK
#define X 0xFFFFFF //WHITE
#define ALIEN_HEIGHT 8
#define ALIEN_WIDTH 11

int alienDean_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
     X,X,_,_,_,_,_,_,_,X,X,
     X,X,X,X,X,X,X,X,X,X,X,
     X,X,_,X,X,X,X,X,_,X,X,
     X,X,X,_,_,X,_,_,X,X,X,
     _,X,X,X,X,X,X,X,X,X,_,
     _,_,X,X,X,X,X,X,X,_,_,
     _,_,X,X,X,X,X,X,X,_,_,
     X,X,X,_,_,_,_,_,X,X,X,
};

AlienDean::AlienDean() {
    speed = 1;
};

void AlienDean::drawAlien() {
    uLCD.BLIT(xpos, ypos, ALIEN_WIDTH, ALIEN_HEIGHT, alienDean_sprite);
};

void AlienDean::updateAlien() {
    if(!isDead) {
        destroy();
        updatePos(speed);
        drawAlien();
    }
};