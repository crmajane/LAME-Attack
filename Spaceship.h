#ifndef SPACESHIP_H
#define SPACESHIP_F
#include "uLCD_4DGL.h"
#include "ScreenAlien.h"
extern uLCD_4DGL uLCD;

class Spaceship {
    public:
        Spaceship();
        void updateShip(int x, double xAcc);
        void drawShip();
        void ship();
        void shoot();
        void drawBullet();
        bool checkCollision(int ax, int ay);
    private:
        int ypos;
        int xpos;
        bool bulletExists;
        int xbullet;
        int ybullet;
        int bulletColor;
};
#endif