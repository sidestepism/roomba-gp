//
//  Stage.cpp
//  fontsExample
//
//  Created by 伏見 遼平 on 2013/04/01.
//
//

#ifndef _INC_STAGE
#define _INC_STAGE

#include "testApp.h"
#include "Stage.h"
#include "math.h"

using namespace std;

Stage::Stage(){
    cout << "constructor of Stage class was called" << endl;
    int i, j;
    for(i = 0; i < FWIDTH; i++){
        for(j = 0; j < FHEIGHT; j++){
            
        }
    }
}

void Stage::draw(){
    int i, j;
    for(i = 0; i < FWIDTH; i++){
        for(j = 0; j < FHEIGHT; j++){
            if(this->wallField[i][j] == 1){
                ofSetColor(WALLCOLOR);
            }else if(this->pointField[i][j] > 0){
                ofSetColor(FIELDCOLOR);
            }else{
                ofSetColor(FIELDCOLOR);
            }

            // 正方形を書く
            ofRect(i * this->size + this->offset, j * this->size + this->offset, this->size, this->size);

            if(this->pointField[i][j] > 0){
                ofSetColor(POINTCOLOR);
                ofCircle(
                         (i + 0.5) * this->size + this->offset,
                         (j + 0.5) * this->size + this->offset,
                         this->size / 4, this->size / 4);
            }
        }
    };
}


#endif