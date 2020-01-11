#include "Spaceship.h"

Spaceship::Spaceship() {
    xpos = 65;
    ypos = 117;
    bulletExists = false;
    drawShip();
    xbullet = -1;
    ybullet = -1;
    bulletColor = 0xFFFFFF;
}

void Spaceship::drawShip() {
    uLCD.filled_rectangle(xpos, ypos , xpos+25, ypos + 7, 0xFFFFFF);
}

void Spaceship::updateShip(int num, double xAcc) {
    uLCD.filled_rectangle(xpos, ypos, xpos+25, ypos + 7, 0x000000);
    //uLCD.printf("%f", xAcc);
    if(num == 1) {
        xpos += 12;
    } else if(num == 2) {
        xpos -= 12;
    }
    drawShip();
    if(bulletExists) {
        //uLCD.printf("update");
        uLCD.filled_circle(xbullet, ybullet, 3, 0x000000);
        xbullet += xAcc*6;
        ybullet -= 4;
        drawBullet();
        if(ybullet < -5)
            bulletExists = false;
        if(xbullet < 2)
            bulletExists = false;
        if(xbullet > 125)
            bulletExists = false;
    }
}

void Spaceship::shoot() {
    //uLCD.printf("shooting");
    if (!bulletExists) {
        //uLCD.printf("no bullet");
        xbullet = xpos + 14;
        ybullet = 110;
        //uLCD.printf("%d", ybullet);
        bulletExists = true;
        drawBullet();
    } else {
        //uLCD.printf("%d", xbullet);
        return;
    }
}

void Spaceship::drawBullet() {
    uLCD.filled_circle(xbullet, ybullet, 3, bulletColor);
    //uLCD.printf("draw");
}

bool Spaceship::checkCollision(int ax, int ay) {
    if (bulletExists) {
        if((xbullet > (ax - 3) & xbullet < (ax + 13)) & (ybullet < (ay + 10) && ybullet > (ay - 1))) {
            return true;
        } else
            return false;
    } else
        return false;
}