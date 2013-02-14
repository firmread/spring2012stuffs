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
		
        
        //so this first bit is just a basic metronome so we can hear what we're doing.
        
        
        currentCount = (int)timer.phasor(0.5);
        //this sets up a metronome that ticks every 2 seconds
        
        if (lastCount!=currentCount) {
            //if we have a new timer int this sample, play the sound
            
            ADSR.trigger(0, adsrEnv[0]);
            //trigger the envelope from the start
            
            cout << "tick\n";
            //the clock ticks
            
            lastCount   = 0;
        }
        
        
        //and this is where we build the synth
        
        
        ADSRout     =   ADSR.line(8,adsrEnv);
        //our ADSR env has 8 value/time pairs.
        
        LFO1out     =   LFO1.sinebuf(0.2);
        //this lfo is a sinewave at 0.2 hz
        
        VCO1out     =   VCO1.pulse(55,0.6);
        //here's VCO1. it's a pulse wave at 55 hz, with a pulse width of 0.6
        
        VCO2out     =   VCO2.pulse(110+LFO1out,0.2);
        //here's VCO2. it's a pulse wave at 110hz with LFO modulation on the frequency, and width of 0.2
        
        VCFout      =   VCF.lores((VCO1out+VCO2out)*0.5, 250+(ADSRout*15000), 10);
        //now we stick the VCO's into the VCF, using the ADSR as the filter cutoff 
        
        //finally we add the ADSR as an amplitude modulator 
        mix.stereo(VCFout*ADSRout, outputs, 0.5);
        
        output[i*nChannels    ]   = outputs[0];
        output[i*nChannels + 1]   = outputs[1];
		
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

