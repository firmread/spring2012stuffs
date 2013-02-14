#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	for (int i = 0; i < NUM_CIRCLES; i++) {
		
		circles[i].setup();
		
		
	}
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i = 0; i < NUM_CIRCLES; i++) {
		
		if (i ==0) {
			
			circles[i].update(circles[NUM_CIRCLES -1]);
			
		}
		
		for (int j = 0; j < i; j++) {
		
			circles[i].update( circles[j] );
		}
		
	}

}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(40, 40, 40);

	for (int i = 0; i < NUM_CIRCLES; i++) {
		
		//modulus operator
//		if( i % 7 == 0) {
//			ofFill();
//		} else {
//			ofNoFill();
//		}
		
		ofFill();
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