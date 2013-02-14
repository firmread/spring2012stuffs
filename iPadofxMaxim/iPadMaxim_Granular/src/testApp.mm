#include "testApp.h"

testApp::~testApp() {
	
	delete ts;
	
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
	
	//If you want a landscape orientation 
	//iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);
    
    
    ofEnableAlphaBlending();
	ofBackground(0, 0, 0);
    
    
	sampleRate 			= 44100;
	initialBufferSize	= 512;

    lAudioOut			= new float[initialBufferSize];/* outputs */
	rAudioOut			= new float[initialBufferSize];
	lAudioIn			= new float[initialBufferSize];/* inputs */
	rAudioIn			= new float[initialBufferSize];
    
    /* This is a nice safe piece of code */
	memset(lAudioOut, 0, initialBufferSize * sizeof(float));
	memset(rAudioOut, 0, initialBufferSize * sizeof(float));
	
	memset(lAudioIn, 0, initialBufferSize * sizeof(float));
	memset(rAudioIn, 0, initialBufferSize * sizeof(float));
    
	
    samp.load (ofToDataPath("2630__Jovica__133_bpm_ATTACK_LOOP_04_electrified_analog_kit_variation_16_mono.wav"));
	samp2.load(ofToDataPath("24620__anamorphosis__GMB_Kantilan_1.wav"));
	samp3.load(ofToDataPath("26393__brfindla__Calango1berimbau.wav"));
	samp4.load(ofToDataPath("68373__juskiddink__Cello_open_string_bowed.wav"));
	samp5.load(ofToDataPath("71515__Microscopia__Wilhelm_Bruder_Sohne_Organ.wav"));    
    
	ts  = new maxiPitchStretch<grainPlayerWin>(&samp);
	ts2 = new maxiPitchStretch<grainPlayerWin>(&samp2);
	ts3 = new maxiPitchStretch<grainPlayerWin>(&samp3);
	ts4 = new maxiPitchStretch<grainPlayerWin>(&samp4);
	ts5 = new maxiPitchStretch<grainPlayerWin>(&samp5);
	stretches.push_back(ts);
	stretches.push_back(ts2);
	stretches.push_back(ts3);
	stretches.push_back(ts4);
	stretches.push_back(ts5);
	speed       = 1;
    rate        = 2;
	grainLength = 0.05;
	current     = 0;
	
	fft.setup(1024, 512, 256);
	oct.setup(44100, 1024, 10);
	
	ofxMaxiSettings::setup(sampleRate, 2, initialBufferSize);
	ofSoundStreamSetup(2,0, this, maxiSettings::sampleRate, initialBufferSize, 4);
    /* Call this last ! */
	

    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(160,32,240, 150);
	ofDrawBitmapString(":: ofxMaxim Granular Timestretching Example ::", 10,20);
	ofDrawBitmapString("Move the mouse left to right to change playback speed and direction.", 10,40);
	ofDrawBitmapString("Move the mouse up and down to change the grain length.", 10,60);
	ofDrawBitmapString("Click to cycle through samples.", 10,80);
	
	stringstream s;
	s << "Speed: " << speed;
	ofDrawBitmapString(s.str(), 10,ofGetHeight()-40);
	s.str("");
	s << "Grain length: " << round(grainLength*1000.0) << " ms";
	ofDrawBitmapString(s.str(), 10,ofGetHeight()-20);
    
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
		
//		wave = stretches[current]->play(speed, grainLength, 5, 0);
		wave = stretches[current]->play(speed*2, rate, 0.1, 4, 0);
//		wave = stretches[current]->play2(pos, 0.1, 4);
        
		if (fft.process(wave)) {
			oct.calculate(fft.magnitudes);
		}
		
		//play result
		mymix.stereo(wave, outputs, 0.5);
		
        /* You may end up with lots of outputs. add them here */
        lAudioOut[i] = output[i*nChannels    ] = outputs[0]; 
        rAudioOut[i] = output[i*nChannels + 1] = outputs[1];
	}
	
}

//--------------------------------------------------------------
void testApp::audioReceived(float * input, int bufferSize, int nChannels){
    
    /* You can just grab this input and stick it in a double, then use it above to create output*/
    
	for (int i = 0; i < bufferSize; i++){
		/* you can also grab the data out of the arrays*/
		lAudioIn[i] = input[i*2];
		rAudioIn[i] = input[i*2+1];
	}
    
}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch){
    
	speed       = ( (double)  touch.x / ofGetWidth()    * 4.0) - 2.0;
	grainLength = ( (double)  touch.y / ofGetHeight()   * 0.1) + 0.001;
	pos         = ( (double)  touch.x / ofGetWidth()    * 2.0);
    
    rate        = ( (double)  touch.y / ofGetHeight()   * 4.0) - 2.0;

}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs &touch){
	if (++current > stretches.size()-1) current = 0;
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

