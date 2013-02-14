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
    
    myEnvelope.amplitude=myEnvelopeData[0]; 
    //initialise the envelope
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
		
        CurrentCount = myCounter.phasor(1, 1, 9);
        
        if (CurrentCount<5)
            oscOut = mySwitchableOsc.square(CurrentCount*100);
        
        else if (CurrentCount>=5)
            oscOut = mySwitchableOsc.saw(CurrentCount*50);
        
        if (CurrentCount==1) 
            myEnvelope.trigger(0,myEnvelopeData[0]); //trigger the envelope
        
        filterOut = myFilter.lores(oscOut, myEnvelope.line(6, myEnvelopeData), 10);
        //lores takes an audio input, a frequency and a resonance factor (1-100)
     
        mix.stereo(filterOut,outputs,0.5);
		
		output[i*nChannels    ] = outputs[0];
		output[i*nChannels + 1] = outputs[1];
		
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

