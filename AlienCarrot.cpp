#include "AlienCarrot.h"


uLCD_4DGL extern uLCD;

#define _ 0x000000 //BLACK
#define X 0xFFFFFF //WHITE
#define ALIEN_HEIGHT 8
#define ALIEN_WIDTH 11

int alienCarrot_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
     _,X,_,X,_,_,_,X,_,X,_,
     X,X,X,X,X,X,X,X,X,X,X,
     _,X,X,_,_,X,_,_,X,X,_,
     _,X,X,_,_,X,_,_,X,X,_,
     _,_,X,X,X,X,X,X,X,_,_,
     _,_,_,X,X,X,X,X,_,_,_,
     _,_,X,X,_,X,_,X,X,_,_,
     X,X,_,_,_,X,_,_,_,X,X,
};

AlienCarrot::AlienCarrot() {
    speed = 3;
};

void AlienCarrot::drawAlien() {
    uLCD.BLIT(xpos, ypos, ALIEN_WIDTH, ALIEN_HEIGHT, alienCarrot_sprite);
};

void AlienCarrot::updateAlien() {
    if(!isDead) {
        destroy();
        updatePos(speed);
        drawAlien();
    }
};