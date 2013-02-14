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
	
    //This shows how to use maximilian to build a polyphonic synth
    
	double      outputs[2];
    
    //These are the synthesiser bits
    ofxMaxiOsc      VCO1[6],VCO2[6],LFO1[6],LFO2[6];
    ofxMaxiFilter   VCF[6];
    ofxMaxiEnvelope ADSR[6];
    
    
    //These are the control values for the envelope
    double adsrEnv[8]={1,5,0.125,100,0.125,200,0,1000};
    
    //This is a bunch of control signals so that we can hear something
    ofxMaxiOsc  timer;
    //this is the metronome
    int         currentCount,lastCount,voice = 0;
    //these values are used to check if we have a new beat this sample
    
    
    //and these are some variables we can use to pass stuff around
    double VCO1out[6],VCO2out[6],LFO1out[6],LFO2out[6],VCFout[6],ADSRout[6],mix,pitch[6];
    
//    ofxMaxiMix mix;
    
};


