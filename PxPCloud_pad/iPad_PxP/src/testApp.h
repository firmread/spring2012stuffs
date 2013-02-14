#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"
#include "ofxMaxim.h"
#include "ofxUI.h"


class testApp : public ofxiPhoneApp {
	
public:
	~testApp();
	void setup();
	void update();
	void draw();
	void exit();
	
	void touchDown(ofTouchEventArgs &touch);
	void touchMoved(ofTouchEventArgs &touch);
	void touchUp(ofTouchEventArgs &touch);
	void touchDoubleTap(ofTouchEventArgs &touch);
	void touchCancelled(ofTouchEventArgs &touch);

	void lostFocus();
	void gotFocus();
	void gotMemoryWarning();
	void deviceOrientationChanged(int newOrientation);
	
    ofVideoGrabber video;
    unsigned char* pixels;
    
    //sound
    void audioReceived(float *input, int bufferSize, int nChannels);
    float volume;
    float *inputBufferCopy;
	
	
    //ofxUI
    void drawGrid(float x, float y); 
    
    void setGUI(); 
    ofxUICanvas *gui; 
    
    bool hideGUI; 
    bool bdrawGrid; 
    bool bdrawPadding; 
    
    void guiEvent(ofxUIEventArgs &e);
    
    float red, green, blue; 
    
    float spreadbase;
    float spreadmultiplier;
    
    float boxbase;
    float boxmultiplier;

};


