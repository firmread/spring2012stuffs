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
		
        
        mix =   0;
        //we're adding up the samples each update and it makes sense to clear them each time first.
        //so this first bit is just a basic metronome so we can hear what we're doing.
        
        currentCount    =   (int)timer.phasor(8);
        //this sets up a metronome that ticks 8 times a second
        
        if (lastCount!=currentCount) {
            //if we have a new timer int this sample, play the sound
            
            if (voice == 6) {
                voice   =   0;
            }
            
            ADSR[voice].trigger(0, adsrEnv[0]);
            //trigger the envelope from the start
            pitch[voice] = voice+1;
            voice++;
            
            lastCount=0;
            
        }
        
        //and this is where we build the synth
        
        for (int i=0; i<6; i++) {
            
            
            ADSRout[i]  =   ADSR[i].line(8,adsrEnv);
            //our ADSR env has 8 value/time pairs.
            
            LFO1out[i]  =   LFO1[i].sinebuf(0.2);
            //this lfo is a sinewave at 0.2 hz
            
            VCO1out[i]  =   VCO1[i].pulse(55*pitch[i],0.6);
            //here's VCO1. it's a pulse wave at 55 hz, with a pulse width of 0.6
            
            VCO2out[i]  =   VCO2[i].pulse((110*pitch[i])+LFO1out[i],0.2);
            //here's VCO2. it's a pulse wave at 110hz with LFO modulation on the frequency, and width of 0.2
            
            VCFout[i]   =   VCF[i].lores((VCO1out[i]+VCO2out[i])*0.5, 250+((pitch[i]+LFO1out[i])*1000), 10);
            //now we stick the VCO's into the VCF, using the ADSR as the filter cutoff 
            
            mix         +=   VCFout[i]*ADSRout[i]/6;
            //finally we add the ADSR as an amplitude modulator 
            
            
        }
//        mix.stereo(VCFout*ADSRout, outputs, 0.5);
        
        output[i*nChannels    ]   = mix*0.5;
        output[i*nChannels + 1]   = mix*0.5;
		
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

