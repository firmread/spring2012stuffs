#include "testApp.h"
// precompiler fn of C
// that memory allocate in the computer before anything compile

//--------------------------------------------------------------
void testApp::setup(){
    getWidth()
}

// you can easily create your own custom fn anywhere like processing
// ex.
// void testApp::myFunction(){
// }


//--------------------------------------------------------------
void testApp::update(){
    
    int r = ofMap(mouseX, 0, width, 0, 255);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(int r, int g, int b)
    ofFill();
    ofSetColor(255, 0, 0);
    ofRect(10, 20, mouseX, mouseY);
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