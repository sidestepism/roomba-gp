//
//  Roomba.cpp
//  fontsExample
//
//  Created by 伏見 遼平 on 2013/04/01.
//
//

#ifndef _INC_STAGE
#define _INC_STAGE

#include "testApp.h"
#include "Roomba.h"

#define FWIDTH 12
#define FHEIGHT 12

using namespace std;

Roomba::Roomba(){
    this->setPosition(FWIDTH / 2, FHEIGHT / 2, 0);
    this->frame = 0;
    this->sframe = 0;
    this->point = 0;
}

void Roomba::sayHello(){
    cout << "Hello!" << endl;
}

void Roomba::setPosition(double _x, double _y, double _deg){
    ox = sx = x = _x;
    oy = sy = y = _y;
    oangle = sangle = angle = _deg;
}

void Roomba::outputStatus(){
    cout << "sx: " << sx << ", sy:" << sy << ", angle: " << angle << endl;
    cout << "ox: " << sx << ", oy:" << sy << ", angle: " << angle << endl;
    cout << "sframe: " << sframe << ", oframe:" << oframe << ", frame:" << frame << endl;
}

void Roomba::cmdStraight(double dist){
    int frame = dist;

    this->x += sin(this->angle) * dist;
    this->y += cos(this->angle) * dist;
}


void Roomba::cmdTurn(double angle){
    this->angle += angle;
}


void Roomba::update(){
    if(this->sframe < this->frame){
        std::cout << "update" << endl;
        double px, py; // prev frame x, y
        px = this->sx;
        py = this->sy;
        double p = ((this->sframe - this->oframe) / (this->frame - this->oframe));
        this->sx = this->ox + (this->x - this->ox) * p;
        this->sy = this->oy + (this->y - this->oy) * p;
        this->sangle = this->oangle + (this->angle - this->oangle) * p;
        this->sframe ++;

        int tile = this->checkTile();
        std::cout << "tilecheck" << tile << endl;

        if(tile < 0){
            std::cout << "wall!" << endl;
            // 壁なら、移動をキャンセル
            // 何もしない
            this->x = this->sx = px;
            this->y = this->sy = py;

        }else if(tile > 0){
            this->collectPoint();
        }
    }else{
        nextCommand();
    }
}

void Roomba::nextCommand(){

    this->oframe = this->sframe;
    this->frame = this->sframe + 10;
    this->ox = this->x;
    this->oy = this->y;
    this->oangle = this->oangle;


    // 木を読んでいろいろ実行したりする
    int rand = floor(ofRandom(4));
    switch(rand){
        case 3:
            cmdStraight(1);
            break;
        case 2:
            cmdStraight(0.5);
            break;
        case 1:
            cmdTurn(0.5);
            break;
        case 0:
            cmdTurn(-0.5);
            break;
    }

}

float Roomba::display_x(){
    return this->sx * stage->size + stage->offset;
}

float Roomba::display_y(){
    return this->sy * stage->size + stage->offset;
}


void Roomba::draw(){
    ofSetColor(255);
    ofCircle(this->display_x(), this->display_y(), stage->size/2);

    ofSetColor(0);
    ofLine(this->display_x(),
           this->display_y(),
           this->display_x() + sin(this->angle) * stage->size/2,
           this->display_y() + cos(this->angle) * stage->size/2
           );
}

int Roomba::checkTile(){
    int x = floor(this->x);
    int y = floor(this->y);
    if(x < 0 || y < 0 || x >= this->stage->width || y >= this->stage->width){

    }
    if(this->stage->wallField[x][y] > 0){
        return -1;
    }
    if(this->stage->pointField[x][y] > 0){
        return 1;
    }
    return 0;
}

void Roomba::collectPoint(){
    int x = floor(this->x);
    int y = floor(this->y);
    this->point += this->stage->pointField[x][y];
    this->stage->pointField[x][y] = 0;
}

void getSensorValue(){

}

#endif 