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
    
    b.amplitude =   env[0];
	f.amplitude =   env2[0];
	//initialise the envelope
    
    beats.load(ofToDataPath("beat2.wav"));
    //put a path to a soundfile here. Wav format only.
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
		
        
        beat        = ((int) c.phasor(8));
        //this oscillator is now a counter
        
        morebeats   = ((int) e.phasor(0.5,0,16));
        //so is this one
        
        patch1      = b.line(4,env);
        //here's envelope b
        
        patch2      = f.line(6,env2);
        //here's envelop f
        
        tune        = g.saw(melody[morebeats]*0.25);//here's the melody, which occurs at certain times
        
        if (lastbeat!=beat) {
            //this is a nice sample and hold routine for the kick drum 
            f.trigger(0, env2[0]);
            //it runs off the hi hat.
            
            if (rhythm1[morebeats]==1) {
                b.trigger(0, env[0]);
                //and gets played when it's time.
            }
        }
        
        lastbeat    = beat;
        //let's start again. It's a loop
        
        ramp        = ii.phasor(0.5,1,2048);
        //create a basic ramp
       
        pan         = j.phasor(0.25);
        //some panning from a phasor (object is equal power)
        
        delayed     = delay.dl(tune, ramp, 0.9)*0.125;
        
        //the delay line
        
        //then it all gets mixed.
        mixed       = ((a.sinewave(patch1)*0.5)+((d.saw(patch2))*0.125)+(delayed*0.3)*0.5);
        
        noise       = ii.noise()*0.25;
        //add some noise
        
        filtered2   = beats.play(1*(1./16.),0,beats.length);
        //	filtered2=beats.play(-1);
        
        more        = squarewave.pulse(melody[morebeats],pan)*0.05;
        
        filtered    = myfilter.lores(filtered2, 1+(pan*10000), 10)*0.4;
        //filter the noise! this lores takes values between 1 and 100 for res, and freq for cutoff.
        
        //now we send the sounds to some stereo busses.
        mymix.stereo(more+mixed+delayed, outputs, 1-pan);
        bobbins.stereo(filtered, moreoutputs, pan);
        //invert the pan
        
        //mixing
        output[i*nChannels    ]   = outputs[0] + moreoutputs[0];
        output[i*nChannels + 1]   = outputs[1] + moreoutputs[1];
        //stick it in the out!!
		
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

