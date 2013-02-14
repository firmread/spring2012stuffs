#include "testApp.h"
// precompiler fn of C
// that memory allocate in the computer before anything compile

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    // sync with refresh rate of the screen
    // always use this when we draw sth
    for (int i = 0; i < NUM_CIRCLES; i++) {
        circles[i].setup();
    }
}

// you can easily create your own custom fn anywhere like processing
// ex.
// void testApp::myFunction(){
// }


//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < NUM_CIRCLES; i++) {
        for (int j = 0; j<i ; j++){
            circles[i].update( circles[j] );
        }
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(40, 40, 40);
    for (int i = 0; i <NUM_CIRCLES; i++) {
        //modulus operator
        if (i % 2 == 0) {
            ofFill();
        }
        else{
            ofNoFill();
        }
        circles[i].draw();
    }
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