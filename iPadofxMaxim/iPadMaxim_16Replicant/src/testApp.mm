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
		
        currentCount    =   (int)timer.phasor(9);
        //this sets up a metronome that ticks every so often
        
        if (lastCount!=currentCount) {
            //if we have a new timer int this sample, play the sound
            
            trigger     =   1;
            //play the arpeggiator line
            
            trigger2    =   leadLineTrigger[playHead%256];
            //play the lead line
            
            if (trigger2    ==  1) {
                //if we are going to play a note
                
                leadPitch   =   mtof.mtof(leadLinePitch[newnote]);
                //get the next pitch val
                
                newnote++;
                //and iterate
                
                if (newnote >   14) {
                    newnote =   0;
                    //make sure we don't go over the edge of the array
                }
            }
            
            currentPitch    =   mtof.mtof(pitch[(playHead%4)] + chord[currentChord%8]);
            //write the frequency val into currentPitch
            
            playHead++;
            //iterate the playhead
            
            if (playHead%32==0) {
                //wrap every 4 bars
                currentChord++;
                //change the chord
            }
            //cout << "tick\n";
            //the clock ticks
            
            lastCount=0;
            //set lastCount to 0
        }
        
        bassout =   filter2.lores(envelope.adsr(bass.saw(currentPitch*0.5)
                    +sound.pulse(currentPitch*0.5,mod.phasor(1)),1,0.9995, 0.25, 0.9995, 1, trigger),9250,2);
        //new, simple ADSR. 
        
        leadout =   filter.lores(leadenvelope.ar(lead2.saw(leadPitch*4)
                    +lead.pulse(leadPitch+(leadmod.sinebuf(1.9)*1.5), 0.6), 0.00005, 0.999975, 50000, trigger2),5900,10);
        //leadline
        
        delayout    =   (leadout+(delay.dl(leadout, 14000, 0.8)*0.5))/2;
        //add some delay
        
        if(trigger!=0)
            trigger=0;
        //set the trigger to off if you want it to trigger immediately next time.
        
//        mix.stereo(VCFout*ADSRout, outputs, 0.5);
        
        output[i*nChannels    ]   = (bassout+delayout)/2;
        output[i*nChannels + 1]   = (bassout+delayout)/2;
		
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

