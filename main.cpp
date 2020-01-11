// LAME Attack game

#include "mbed.h"
#include "AlienBob.h"
#include "PinDetect.h"
#include <time.h>
#include "Speaker.h" 
#include "Spaceship.h"
#include "uLCD_4DGL.h"
#include "AlienAlice.h"
#include "AlienCarrot.h"
#include "AlienDean.h"
#include "MMA8452.h"

uLCD_4DGL uLCD(p28, p27, p29);
PinDetect pb1(p16); //you can use different pins
PinDetect pb2(p17); //you can use different pins
PinDetect pb3(p18); // you can use different pins

int toUpdate = 0;
bool toShoot = false;

void pb1_hit_callback (void) {
    toUpdate = 1;
}
void pb2_hit_callback (void) {
    toUpdate = 2;
}
void pb3_hit_callback (void) {
    toShoot = true;
    //uLCD.printf("made it");
}

int killTotal = 0;
Timer t;
float time1;
float time2;
bool breakout = false;
Speaker mySpeaker(p21);
Serial pc(USBTX,USBRX); //not used in this program
double x;
double y;
double z;

int main() {
     MMA8452 acc(p9, p10, 40000);  //instantiate an acc object! 
   
     //set parameters -- use these and don't change
     acc.setBitDepth(MMA8452::BIT_DEPTH_12);
     acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
     acc.setDataRate(MMA8452::RATE_100);

     uLCD.baudrate(3000000);
     pb1.mode(PullUp);
     pb2.mode(PullUp);
     pb3.mode(PullUp);
     // Delay for initial pullup to take effect
     wait(.01);
    
     // Setup Interrupt callback functions for a pb hit
     pb1.attach_deasserted(&pb1_hit_callback);
     pb2.attach_deasserted(&pb2_hit_callback);
     pb3.attach_deasserted(&pb3_hit_callback);
     // Start sampling pb inputs using interrupts
     pb1.setSampleFrequency();
     pb2.setSampleFrequency();
     pb3.setSampleFrequency();
    
    ScreenAlien** arr = new ScreenAlien *[6];
    
    srand(time(NULL));
    int type;
    for(int i = 0; i<6; i++) {
        type = rand() % 4;
        switch(type) {
            case 0: arr[i] = new AlienBob();
                    break;
            case 1: arr[i] = new AlienAlice();
                    break;
            case 2: arr[i] = new AlienCarrot();
                    break;
            case 3: arr[i] = new AlienDean();
                    break;
        }
    }
    Spaceship * ship = new Spaceship();
    bool collided = false;
    t.start();
    time1 = t.read();
    //uLCD.printf("%d", time1);
    while(!breakout){
      if(!acc.isXYZReady()) 
      {
         wait(0.01);
      }
      else
      {
      acc.readXYZGravity(&x,&y,&z); //notice this is passed by reference use pointers
      //uLCD.printf("%f", y);
      }
        for(int i = 0; i<6; i++) {
            arr[i] -> updateAlien();
            collided = ship -> checkCollision(arr[i] -> getxpos(), arr[i] -> getypos());
            if (collided) {
                killTotal += arr[i] -> kill();
                //uLCD.printf("%d",killTotal);
                if(killTotal == 6) {
                    t.stop();
                    time2 = t.read();
                    breakout = true;
                }
            }
        }
        ship -> updateShip(toUpdate, y);
        toUpdate = 0;
        if(toShoot) {
            ship -> shoot();
            mySpeaker.PlayNote(196,0.05,0.1);
            toShoot = false;
        }
    }
    uLCD.cls();
    uLCD.printf("\n\n Congratulations!!\n\n      Earth Saved!\n\n\n(%f Seconds)", time2 - time1);

}
