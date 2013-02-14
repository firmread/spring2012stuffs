/* This is an example of how to integrate maximilain into openFrameworks, 
 including using audio received for input and audio requested for output.
 
 
 You can copy and paste this and use it as a starting example.
 
 */


#include "testApp.h"



//-------------------------------------------------------------
testApp::~testApp() {
	
	delete beat.myData; /*you should probably delete myData for any sample object
						 that you've created in testApp.h*/
	
}


//--------------------------------------------------------------
void testApp::setup(){
	/* some standard setup stuff*/
    
    
	ofEnableAlphaBlending();
	ofSetupScreen();
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	
	/* This is stuff you always need.*/
	
	sampleRate 			= 44100; /* Sampling Rate */
	initialBufferSize	= 512;	/* Buffer Size. you have to fill this buffer with sound*/
	
	
	/* Now you can put anything you would normally put in maximilian's 'setup' method in here. */
	
    myEnvelopeData[500,0,1000,500,0,500];
    myEnvelope.amplitude = myEnvelopeData[0]; 
    
    
	beat.load(ofToDataPath("beat2.wav"));
	beat.getLength();
	
	
	ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);/* Call this last ! */
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
}

//--------------------------------------------------------------
void testApp::audioRequested 	(float * output, int bufferSize, int nChannels){
	
	for (int i = 0; i < bufferSize; i++){
		
		/* Stick your maximilian 'play()' code in here ! Declare your objects in testApp.h.
		 
		 For information on how maximilian works, take a look at the example code at
		 
		 http://www.maximilian.strangeloop.co.uk
		 
		 under 'Tutorials'.
		 
		 */
		
		
		CurrentCount=myCounter.phasor(1, 1, 9);
        if (CurrentCount<5)
            myOscOutput=mySwitchableOsc.square(CurrentCount*100);
        
        else if (CurrentCount>=5)
            myOscOutput=mySwitchableOsc.saw(CurrentCount*50);
        
        if (CurrentCount==1) 
            
            myEnvelope.trigger(0,myEnvelopeData[0]); 
        
        myFilteredOutput=myFilter.lores(myOscOutput,(myEnvelope.line(6, myEnvelopeData)),10);
        
        *outputs=myFilteredOutput;
		
		
		output[i*nChannels    ] = outputs[0]; 
		output[i*nChannels + 1] = outputs[1];
	}
	
}

//--------------------------------------------------------------
void testApp::audioReceived 	(float * input, int bufferSize, int nChannels){	
	
	
	/* You can just grab this input and stick it in a double, then use it above to create output*/
	
	for (int i = 0; i < bufferSize; i++){
		
		/* you can also grab the data out of the arrays*/
		
		
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
	
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}



//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}