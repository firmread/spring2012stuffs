#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableAlphaBlending();
    
    //setting up different scenes
    
    scenes.push_back(new channel1Scene());
    scenes.push_back(new channel2Scene());
    scenes.push_back(new channel3Scene());
    
    for (int i = 0; i < scenes.size(); i++){
        scenes[i]->setup();
    }
    
    whichScene = 0;
    translate = 0;
    translateTarget = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){

    scenes[whichScene]->update();
    
    translate = 0.99f * translate + 0.01 * translateTarget;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    scenes[whichScene]->draw();
    
    //float ty = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, -768);

    
    
//    ofTranslate(0,translate,0);
//    ofSetColor(0,0,0);
//    ofRect(50,50,300, 768*2-100);
//    ofRect(400, 768*2 - 150, 50,50);
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if (key == ' '){
    whichScene++;
    whichScene %= scenes.size();
    } else if (key == OF_KEY_DOWN){
        translateTarget = -768;
    } else if (key == OF_KEY_UP){
        translateTarget = 0;
    }
    

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    if (x < ofGetWidth()/3){
        whichScene = 0;
    } else if (x >= ofGetWidth()/3 && x < 2*(ofGetWidth()/3)){
        whichScene = 1;
    } else {
        whichScene = 2;
    }
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