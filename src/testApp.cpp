#include "Roomba.h"
#include "Stage.h"
#include "testApp.h"

#define FWIDTH 12
#define FHEIGHT 12

Stage stage;
Roomba roomba;

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0);
    roomba.stage = &stage;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(33);

    int OFFSET = 20;
    int SIZE = 20;
    int i, j;

    string str = "framerate is ";

    str += ofToString(ofGetFrameRate(), 2) + "fps";
    ofSetWindowTitle(str);


    stage.draw();

    roomba.update();
    roomba.draw();
    roomba.outputStatus();


}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
