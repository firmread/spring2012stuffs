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
	
    //Bizarrely, this sounds a little bit like Kraftwerk's 'Metropolis', although it isn't. Funny that. 
    
	double      outputs[2];
    
    //here are the synth bits
    ofxMaxiOsc      sound,bass,timer,mod,lead,lead2,leadmod;
    ofxMaxiFilter   filter, filter2;
    ofxMaxiEnv      envelope, leadenvelope;
    ofxMaxiDelayline delay;
    
    convert mtof;
    //a method for converting midi notes to frequency
    
    double bassout,leadout, delayout;
    //some variables to hold the data and pass it around
    
    int trigger, trigger2, newnote;
    //some control variables
    
    int currentCount,lastCount,playHead = 0, currentChord = 0;
    //some other control variables
    
    int pitch[8] = {57,57,59,60};
    //the bassline for the arpeggio
    
    int chord[8] = {0,0,7,2,5,5,0,0};
    //the root chords for the arpeggio
    
    float currentPitch,leadPitch;
    //the final pitch variables
    
    //here's the lead line trigger array, followed by the pitches
    int leadLineTrigger[256] = 
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    int leadLinePitch[15] = {69,67,65,64,67,66,64,62,65,64,62,57,55,60,57};

    
    //    ofxMaxiMix mix;
    
};


