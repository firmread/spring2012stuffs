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
	
    void drawGrid(float x, float y); 
    
	void setGUI1(); 
	void setGUI2(); 
	void setGUI3(); 	
	
	ofxUICanvas *gui1;   	
	ofxUICanvas *gui2;   	
	ofxUICanvas *gui3;   	    
    
	bool hideGUI; 
	
	float red, green, blue; 
	bool bdrawGrid; 
	bool bdrawPadding; 
	
	void guiEvent(ofxUIEventArgs &e);
    
    float *buffer; 
    ofImage *img; 
};


