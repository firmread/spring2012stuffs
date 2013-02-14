#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"
#include "ofxMaxim.h"
#include <sys/time.h>


typedef hannWinFunctor grainPlayerWin;

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
	
    /* outputs */
    float 	* lAudioOut; 
	float   * rAudioOut;
    
    /* inputs */
	float * lAudioIn;
	float * rAudioIn;
    
    /* buffer size */ 
	int		initialBufferSize;
	int		sampleRate;
	
    
	/* stick your maximilian stuff below */
	
	double          wave,sample,outputs[2];
	ofxMaxiSample   samp, samp2, samp3, samp4, samp5;
	vector < maxiPitchStretch < grainPlayerWin> * > stretches;
	ofxMaxiMix      mymix;
	maxiPitchStretch <grainPlayerWin> *ts, *ts2, *ts3, *ts4, *ts5;
	double          speed, grainLength, rate;
	
	ofxMaxiFFT      fft;
	ofxMaxiFFTOctaveAnalyzer    oct;
	int             current;
	double          pos;

};


