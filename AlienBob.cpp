#include "AlienBob.h"


uLCD_4DGL extern uLCD;

#define _ 0x000000 //BLACK
#define X 0xFFFFFF //WHITE
#define ALIEN_HEIGHT 8
#define ALIEN_WIDTH 11

int alienBobDown_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
     _,_,X,_,_,_,_,_,X,_,_,
     _,_,_,X,_,_,_,X,_,_,_,
     _,_,X,X,X,X,X,X,X,_,_,
     _,X,X,_,X,X,X,_,X,X,_,
     X,X,X,X,X,X,X,X,X,X,X,
     X,_,X,X,X,X,X,X,X,_,X,
     X,_,X,_,_,_,_,_,X,_,X,
     _,_,_,X,X,_,X,X,_,_,_,
};

int alienBobUp_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 _,_,X,_,_,_,_,_,X,_,_,
 X,_,_,X,_,_,_,X,_,_,X,
 X,_,X,X,X,X,X,X,X,_,X,
 X,X,X,_,X,X,X,_,X,X,X,
 X,X,X,X,X,X,X,X,X,X,X,
 _,_,X,X,X,X,X,X,X,_,_,
 _,_,X,_,_,_,_,_,X,_,_,
 _,X,_,_,_,_,_,_,_,X,_,
};

AlienBob::AlienBob() {
    armsUp = false;
    count = 0;
    speed = 1;
};

void AlienBob::drawAlien() {
    if(armsUp)
        uLCD.BLIT(xpos, ypos, ALIEN_WIDTH, ALIEN_HEIGHT, alienBobDown_sprite);
    else
        uLCD.BLIT(xpos, ypos, ALIEN_WIDTH, ALIEN_HEIGHT, alienBobUp_sprite);
    //uLCD.printf("made it");
};

void AlienBob::updateAlien() {
    if(!isDead) {
        destroy();
        updatePos(speed);
        drawAlien();
        count++;
        if(count == 10) {
            armsUp = !armsUp;
            count = 0;
        }
    }
};