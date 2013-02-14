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
    
    kick.load(ofToDataPath("blip.wav"));
    snare.load(ofToDataPath("snare.wav"));
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
		
        currentCount    =   (int)timer.phasor(8);
        //this sets up a metronome that ticks 8 times a second
        
        
        if (lastCount != currentCount) {
            //if we have a new timer int this sample, play the sound
            
            kicktrigger     =   hit[playHead%16];
            //get the value out of the array for the kick
            
            snaretrigger    =   snarehit[playHead%16];
            //same for the snare
            
            playHead++;
            //iterate the playhead
            
            lastCount=0;
            //reset the metrotest
        }
        
        if (kicktrigger==1)
            kick.trigger();
            //reset the playback position of the sample to 0 (the beginning)
        
        if (snaretrigger==1)
            snare.trigger();
            //likewise for the snare
        
        sampleOut   =   kick.playOnce() + snare.playOnce();
        //just play the file. No looping.
        
        output[i*nChannels    ] = sampleOut;
        output[i*nChannels + 1] = sampleOut;
        
        kicktrigger = 0;
        snaretrigger = 0;
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

