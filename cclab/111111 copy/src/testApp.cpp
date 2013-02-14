#include "testApp.h"
// precompiler fn of C
// that memory allocate in the computer before anything compile

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    // sync with refresh rate of the screen
    // always use this when we draw sth
    for (int i = 0; i < NUM_CIRCLES; i++) {
        speed[i].x = ofRandom(1,3);
        speed[i].y = ofRandom(1,3);
        radius[i] = ofRandom(5,15);
        
        pos[i].set(ofRandom(radius[i], ofGetWidth() - radius[i]), 
                   ofRandom(radius[i], ofGetHeight()- radius[i]));
        
        //this is the same as above written in different syntax
        //pos[i].x=ofRandom(radius[i], ofGetWidth() - radius[i];
        //pos[i].y=ofRandom(radius[i], ofGetHeight()- radius[i];
        
        color[i].set(ofRandom(255), ofRandom(255), ofRandom(255));
        
        //color[i].r = 
        //color[i].g = 
        //color[i].b = 
        //color[i].a = 
        
        
        ofBackground(40, 40, 40);
        ofSetFrameRate(60);
    }
}

// you can easily create your own custom fn anywhere like processing
// ex.
// void testApp::myFunction(){
// }


//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < NUM_CIRCLES; i++) {
        pos[i].x += speed[i].x;
        pos[i].y += speed[i].y;
        
        if (pos[i].x < radius[i] || pos[i].x > ofGetWidth() - radius[i]){
            speed[i].x *= -1;
        }
        
        if (pos[i].y < radius[i] || pos[i].y > ofGetHeight() - radius[i]){
            speed[i].y *= -1; 
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
        ofSetColor(color[i]);
        ofCircle(pos[i].x, pos[i].y, radius[i]);
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