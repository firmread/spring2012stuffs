#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();
    ofSetVerticalSync(true);            //so cpu not load too high than what needed
	ofSetCircleResolution(60);          //triangle in circle
	
	xPos	= 20;
	yPos	= 20;
	xSpeed	= 4;
	ySpeed	= 5;
	radius	= 30;
}

//--------------------------------------------------------------
void testApp::update(){
	
	
	xPos = xPos + xSpeed;
	yPos = yPos + ySpeed;
	
	if(xPos > ofGetWidth() ){
		xPos = ofGetWidth();            // this line helps make the ball to not stuck
		xSpeed = xSpeed * -1;
	}
		
	if(xPos < 0 ){
		xPos	= 0;
		xSpeed = xSpeed * -1;
	}
	
	if(yPos > ofGetHeight() || yPos < 0){
		ySpeed = ySpeed *-1;
	}
	//printf("position is %f \n", position);
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255, 0, 128);
	ofCircle(xPos, yPos, radius);
	
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

