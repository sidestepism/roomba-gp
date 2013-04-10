//
//  command.cpp
//  fontsExample
//
//  Created by 伏見 遼平 on 2013/04/02.
//
//


#include "command.h"
#include "math.h"




Command::Command(){
    int i;
    for (i = 0; i < 4; i++) {
        this->childNodes[i] = NULL;
    }
}

Command::~Command(){
    // 子供のメモリも責任を持って解放
    for (int i = 0; i < 4; i++) {
        if(this->childNodes[i] != NULL){
            delete this->childNodes[i];
        }
    }


}

void Command::randomGenerate(){
    int s = floor(ofRandom(OPC));
    this->op = ops[s];
    this->argc = args[s];

    for (int i = 0; i < this->argc; i++) {
        this->childNodes[i] = new Command();
        this->childNodes[i]->randomGenerate();
    }
}

int Command::evaluate(){
    int r;
    int l;
    switch(this->op){
        case MOVE:
            if(this->childNodes[0]->val == -1){
                // どのくらい進むかまだ決めていないぜ
                this->childNodes[0]->evaluate();
            }else{
                // どのくらい進むか決まっている
                // 命令をスタックに積む
                this->roomba->nextOp = MOVE;
                this->roomba->nextOpFrame = this->childNodes[0]->val;
                this->val = 0;
            }
            break;
        case TURN:
            if(this->childNodes[0]->val == -1){
                // どのくらい進むかまだ決めていないぜ
                this->childNodes[0]->evaluate();
            }else{
                // どのくらい進むか決まっている
                // 命令をスタックに積む
                this->roomba->nextOp = TURN;
                this->roomba->nextOpFrame = this->childNodes[0]->val;
                this->val = 0;
            }
            break;
        case IFLTE:
            if (this->childNodes[0]->val < 0){
                // 引数0 が未評価
                this->childNodes[0]->evaluate();
            }else if(this->childNodes[1]->val < 0){
                // 引数1 が未評価
                this->childNodes[1]->evaluate();
            }else{
                // 引数0, 1 が評価済み
                if(this->childNodes[0]->val > this->childNodes[1]->val){
                    this->childNodes[2]->evaluate();
                }else{
                    this->childNodes[3]->evaluate();
                }
            }
            break;
        case PROG2:
            if (this->childNodes[0]->val < 0){
                // 引数0 が未評価
                return this->childNodes[0]->evaluate();
            }else if(this->childNodes[1]->val < 0){
                // 引数1 が未評価
                return this->childNodes[1]->evaluate();
            }
        case SENSOR0:
            return 100;
            break;
        case SENSOR1:
            return 300;
            break;
        case SENSOR2:
            return 500;
            break;
        case SENSOR3:
            return 700;
            break;
        case SENSOR4:
            return 900;
            break;
        case R0:
            return 0;
            break;
        case R1:
            return 100;
            break;
        case R2:
            return 200;
            break;
        case R3:
            return 300;
            break;
        case NOOP:
            break;
        default:
            cout << "Unknown opcode" << endl;
            break;
    }

}