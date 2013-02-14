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
	
    //This shows how to use maximilian to build a monophonic synth
    
	double      outputs[2];
    
    //These are the synthesiser bits
    ofxMaxiOsc      VCO1,VCO2,LFO1,LFO2;
    ofxMaxiFilter   VCF;
    ofxMaxiEnvelope ADSR;
    
    
    //These are the control values for the envelope
    double adsrEnv[8]={1,5,0.125,250,0.125,125,0,500};
    
    //This is a bunch of control signals so that we can hear something
    ofxMaxiOsc  timer;
    //this is the metronome
    int         currentCount,lastCount;
    //these values are used to check if we have a new beat this sample
    
    
    //and these are some variables we can use to pass stuff around
    double VCO1out,VCO2out,LFO1out,LFO2out,VCFout,ADSRout;
    
    ofxMaxiMix mix;
    
};


