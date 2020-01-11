#include "ScreenAlien.h"
#define _ 0x000000 //BLACK

int ScreenAlien::blackBox[88] = {
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
};
int ScreenAlien::alienNum = 0;

ScreenAlien::ScreenAlien() {
    xpos = rand() % 125;
    ypos = alienNum * 20;
    alienNum++;
    movingRight = true;
    isDead = false;
};

void ScreenAlien::updatePos(int speed) {
    if(movingRight) {
        xpos += speed;
        if(xpos > 117)
            movingRight = false;
    } else {
        xpos -= speed;
        if(xpos < 3)
            movingRight = true ;
    }
};

void ScreenAlien::destroy() {
    uLCD.BLIT(xpos, ypos, 11, 8, blackBox);
}

int ScreenAlien::kill() {
    destroy();
    if(!isDead) {
        isDead = true;
        return 1;
    } else
        return 0;
}

const int ScreenAlien::getxpos() {
    return xpos;
}

const int ScreenAlien::getypos() {
    return ypos;
}