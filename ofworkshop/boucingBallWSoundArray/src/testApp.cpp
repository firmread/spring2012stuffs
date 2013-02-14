#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	//ofBackground(40, 40, 40);
	ofEnableAlphaBlending();
	ofSetFrameRate(60);
	ofSetVerticalSync(true);	
	ofSetCircleResolution(40);
	
	
    for (int i = 0 ; i < CIRCLENUM; i++) {
    
    r[i] = ofRandom(255);
    g[i] = ofRandom(255);
    b[i] = ofRandom(255);
	xPos[i] = ofRandom(ofGetWidth());
	yPos[i] = ofRandom(ofGetHeight());
	xSpeed[i] = ofRandom(-10,10);
	ySpeed[i] = ofRandom(-10,10);
	radius[i] = ofRandom(10,30);
	
    }
    
    friction = -1;
    gravity = .1;
    
    // run file from bin/data folder
    //function that represent the sound
	chirpSound.loadSound("beat.wav");
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
for (int i = 0 ; i < CIRCLENUM; i++) {
    
	xPos[i] = xPos[i] + xSpeed[i];
	yPos[i] = yPos[i] + ySpeed[i];
	
	//so it's always update to false state
	bDidWeHitWall[i] = false;		
	
	if(xPos[i] > ofGetWidth() || xPos[i] < 0){
		xSpeed[i] = xSpeed[i] * -1;
		bDidWeHitWall[i] = true;
	}
	
	if(yPos[i] > ofGetHeight() || yPos[i] < 0){
		ySpeed[i] = ySpeed[i] *-1;
		bDidWeHitWall[i] = true;
	}
	
	if (bDidWeHitWall[i]){
		float pan = xPos[i] / (float)ofGetWidth();
		float height = yPos[i] / (float)ofGetHeight();
		
        //so each sounds is different
		chirpSound.setSpeed(0.5 + 2 * (1-height));
        //smoothen stereo effect
		chirpSound.setPan(pan);
		chirpSound.play();	
	}
	
	//printf("position is %f \n", position);
}
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(40, 40, 40,40);
	
    for (int i = 0 ; i < CIRCLENUM; i++) {
        ofSetColor(r[i], g[i], b[i]);
        ofCircle(xPos[i], yPos[i], radius[i]);
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

