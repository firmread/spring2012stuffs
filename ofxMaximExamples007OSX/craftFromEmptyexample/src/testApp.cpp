#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSoundStreamSetup(2,0,this, 44100, 512, 4);/* Call this last ! */
    //ofSoundStreamSetup(<#int nOutputChannels#>, <#int nInputChannels#>, <#ofBaseApp *appPtr#>, <#int sampleRate#>, <#int bufferSize#>, <#int nBuffers#>)
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
		
		/* Stick your maximilian 'play()' code in here ! Declare your objects in testApp.h */
		
        //AM Example
        //*outputs=osciCarrier.saw(abs(mouseX))*osciModulator.phasor(abs(mouseY));

        //FM Example
        *outputs=osciCarrier.sinewave(osciModulator.sinewave(osciThird.sinewave(0.5)*30)*440 );
		
        /* You may end up with lots of outputs. add them here */		
		output[i*nChannels    ] = outputs[0]; 
		output[i*nChannels + 1] = outputs[1];
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