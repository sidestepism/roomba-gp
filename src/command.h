//
//  command.h
//  fontsExample
//
//  Created by 伏見 遼平 on 2013/04/02.
//
//

#ifndef __fontsExample__command__
#define __fontsExample__command__

#include <iostream>
#include <vector>
#include <roomba.h>
#include <string.h>

#define MOVE 0
#define TURN 1
#define IFLTE 2
#define PROG2 3
#define SENSOR0 4
#define SENSOR1 5
#define SENSOR2 6
#define SENSOR3 7
#define SENSOR4 8
#define R0 9
#define R1 10
#define R2 11
#define R3 12
#define NOOP -1

#define OPC 13

int args[OPC] = {
    1, 1, 4, 2,
    0, 0, 0, 0, 0,
    0, 0, 0, 0
};

int ops[OPC] = {
    MOVE, TURN, IFLTE, PROG2,
    SENSOR0, SENSOR1, SENSOR2, SENSOR3, SENSOR4,
    R0, R1, R2, R3
};


class Command{
public:
    Command();
    ~Command();

    void randomGenerate();
    void setDepth();

    int depth = 0;
    int op = NOOP;
    int argc = 0;
    int val = 0;
    Command *childNodes[4];

    string *toString();
    
    int evaluate();
    Command *parentNode;
    Roomba *roomba;
};

#endif /* defined(__fontsExample__command__) */
