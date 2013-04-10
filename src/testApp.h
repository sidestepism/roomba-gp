#pragma once

#include "ofMain.h"
#include <math.h>

#define FWIDTH 12
#define FHEIGHT 12

#define WALLCOLOR 200
#define POINTCOLOR 100
#define FIELDCOLOR 50

// 1m 進むのに必要な時間
#define SPEED_STRAIGHT 30
#define SPEED_TURN 30

// コマンド
#define VAL 0
#define MOVE 1
#define IFLTE 2
#define PROG2 3
#define SENSOR0 16
#define SENSOR1 17
#define SENSOR2 18
#define SENSOR3 19
#define SENSOR4 20
#define R0 32
#define R1 33
#define R2 34
#define R3 35
#define NOOP -1

class testApp : public ofBaseApp{

public:

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    bool bFirst;
    string typeStr;

    ofTrueTypeFont  franklinBook14;
    ofTrueTypeFont	verdana14;
    ofTrueTypeFont	verdana30;

    ofTrueTypeFont  franklinBook14A;
    ofTrueTypeFont	verdana14A;
    
};

