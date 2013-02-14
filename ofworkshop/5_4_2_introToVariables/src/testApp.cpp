#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();
	ofSetVerticalSync(true);
	
	position	= 50;
	speed		= 5;
}

//--------------------------------------------------------------
void testApp::update(){
	
	
	position = position + speed;
	
	if (position > ofGetWidth()){
		position = -50;
	}
	//printf("position is %f \n", position);
	//cout << "position is: "<< position << endl;
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255, 0, 128);
	ofRect(position, 100,50,50);
	
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

