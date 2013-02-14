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
	
    
	double      outputs[2],moreoutputs[2];
    
    double      filtered,patch1,patch2,tune,delayed,
                mixed,ramp,filtered2,noise,pan,more;
    //a bunch of patch cables
    
    int         beat,lastbeat,morebeats,lastmorebeats;
    //some rhythmic elemts
    
    double env[4]={200,0,0,50};
    //the kick drum pitch envelope data
    
    double env2[6]={10000,0,9000,5,0,5};
    //the hi hat pitch envelope data
    
    double melody[14]={600,0,0,650,0,0,400,0,0,425,0,300,0,315};
    //the melody data
    
    int rhythm1[16]={1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0};
    //another way of doing a rhythm
	
    ofxMaxiOsc  a,c,d,e,g,h,ii,j,squarewave;
    //some oscillators
    
    ofxMaxiEnvelope b,f;
    //two envelopers
    
    ofxMaxiDelayline delay;
    //a delay line
    
    ofxMaxiFilter myfilter,antia;
    // a FAT filter
    
    ofxMaxiMix mymix,bobbins;
    //some panning busses
    
    ofxMaxiSample beats;
    
};


