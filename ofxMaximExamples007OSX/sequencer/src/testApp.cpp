#include "testApp.h"


//--------------------------------------------------------------
testApp::~testApp() {
	
	delete beats.myData; /*you should probably delete myData for any sample object
						 that you've created in testApp.h*/
	
}


//--------------------------------------------------------------
void testApp::setup(){
    
    env[200,0,0,50];
    env2[10000,0,9000,5,0,5];
    melody[600,0,0,650,0,0,400,0,0,425,0,300,0,315];
    rhythm1[1,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0];
    
    b.amplitude=env[0];//starting value for envelope b
	f.amplitude=env2[0];//same for f
	beats.load(ofToDataPath("beat2.wav"));//put a path to a soundfile here. Wav format only.
	printf("Summary:\n%s", beats.getSummary());//get info on samples if you like
    
    
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
        //*outputs=osciCarrier.sinewave(osciModulator.sinewave(osciThird.sinewave(0.5)*30)*440 );
        
        
        beat=((int) c.phasor(8));//this oscillator is now a counter
        morebeats=((int) e.phasor(0.5,0,16));//so is this one
        patch1=b.line(4,env);//here's envelope b
        patch2=f.line(6,env2);//here's envelop f
        tune=g.saw(melody[morebeats]*0.25);//here's the melody, which occurs at certain times
        
        if (lastbeat!=beat) {//this is a nice sample and hold routine for the kick drum 
            f.trigger(0, env2[0]);//it runs off the hi hat.
            
            
            if (rhythm1[morebeats]==1) {
                b.trigger(0, env[0]);//and gets played when it's time.
            }
        }
        
        lastbeat    = beat;                     //let's start again. It's a loop
        ramp        = iwave.phasor(0.5,1,2048);     //create a basic ramp
        pan         = j.phasor(0.25);           //some panning from a phasor (object is equal power)
        delayed     = delay.dl(tune, ramp, 0.9)*0.125;//the delay line
        
        //then it all gets mixed.
        mixed       = ((a.sinewave(patch1)*0.5)+((d.saw(patch2))*0.125)+(delayed*0.3)*0.5);
        //add some noise
        noise       = iwave.noise()*0.25;
 
        filtered2   = beats.play(1*(1./16.),0,beats.length);
//        filtered2 = beats.play(-1);
        
        more        = squarewave.pulse(melody[morebeats],pan)*0.05;
        
        //filter the noise! this lores takes values between 1 and 100 for res, and freq for cutoff.
        filtered    = myfilter.lores(filtered2, 1+(pan*10000), 10)*0.4;
        
        //now we send the sounds to some stereo busses.
        mymix.stereo(more+mixed+delayed, outputs, 1-pan);
        bobbins.stereo(filtered, moreoutputs, pan);//invert the pan
        
        //mixing
        
        output[0]=outputs[0]+moreoutputs[0];//stick it in the out!!
        output[1]=outputs[1]+moreoutputs[1];
		
        /* You may end up with lots of outputs. add them here */		
//		output[i*nChannels    ] = outputs[0]; 
//		output[i*nChannels + 1] = outputs[1];
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