//
//  Roomba.h
//  fontsExample
//
//  Created by 伏見 遼平 on 2013/04/01.
//
//

#ifndef __fontsExample__Roomba__
#define __fontsExample__Roomba__

#include "Stage.h"
#include <iostream>
#include "ofMain.h"

class Roomba{
public:
    Roomba();
    Stage *stage;
    double x;
    double y;
    double angle;
    double frame;

    int point;

    // 描画用の値
    double sx;
    double sy;
    double sangle;
    double ox;
    double oy;
    double oangle;

    double sframe;
    double oframe;

    void setPosition(double x, double y, double deg);
    void sayHello();
    void outputStatus();
    void cmdStraight(double dist);
    void cmdTurn(double deg);

    float display_x();
    float display_y();

    int nextOp;
    int nextOpFrame;

    void nextCommand();

    void update();
    void draw();

    int checkTile();
    void collectPoint();

    float getSensorValue();
};

#endif /* defined(__fontsExample__Roomba__) */
