#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"
#include "ofxMaxim.h"


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
	
	void audioReceived( float * input, int bufferSize, int nChannels );
	void audioRequested( float * output, int bufferSize, int nChannels );
	
	int		initialBufferSize;
	int		sampleRate;
	
    //this tutorial explains how to use the maxiEnv
    
    ofxMaxiSample sound1;
    ofxMaxiOsc timer,snarePhase; 
    ofxMaxiEnv envelope;
    
    int currentCount,lastCount,playHead,
    
    sequence[16] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0}; 
    //This is the sequence for the kick
    
    int sampleTrigger;
    double sampleOut;

 
};


