#include "testApp.h"
#include "ofxMaxim.h"

testApp::~testApp() {
    
}

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableAlphaBlending();
	// register touch events
	ofRegisterTouchEvents(this);
	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	//iPhoneAlerts will be sent to this.
	ofxiPhoneAlerts.addListener(this);
	
	sampleRate 			= 44100;
	initialBufferSize	= 512;

	ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);
	
	//If you want a landscape oreintation 
	//iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);
	
	ofBackground(255,255,255);
    
    sound1.load(ofToDataPath("68373__juskiddink__cello-open-string-bowed.wav"));
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::exit(){

}


//--------------------------------------------------------------
void testApp::audioRequested(float * output, int bufferSize, int nChannels){
	
	if( initialBufferSize != bufferSize ){
		ofLog(OF_LOG_ERROR, "your buffer size was set to %i - but the stream needs a buffer size of %i", initialBufferSize, bufferSize);
		return;
	}	
	
	for (int i = 0; i < bufferSize; i++){
		
        currentCount = (int)timer.phasor(8);
        //this sets up a metronome that ticks 8 times a second
        
        if (lastCount!=currentCount) {
            //if we have a new timer int this sample, play the sound
            
            sampleTrigger = sequence[playHead%16];
            playHead++;
            //iterate the playhead
            lastCount = 0;
            //reset the metrotest
            
        }
        
        //the envelope we're using here is an AR envelope.
        //It has an input (which in this case is a sound)
        //It has an attack coefficient, a hold val (in samples)
        //and a release coefficient. Finally, it has a trigger input.
        //If you stick a 1 in the trigger input, it retriggers the envelope
        
        sampleOut = envelope.ar(sound1.play(1.), 0.1, 0.9999, 1, sampleTrigger);
        //ar(input, A, R, holdtime, trigger)
		
        output[0] = sampleOut;
        //left channel
        output[1] = sampleOut;
        //right channel
        
        sampleTrigger = 0;
        //set trigger to 0 at the end of each sample to guarantee retriggering.

		
	}
	
}

//--------------------------------------------------------------
void testApp::audioReceived(float * input, int bufferSize, int nChannels){
	
}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){

}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs& args){
	
}

