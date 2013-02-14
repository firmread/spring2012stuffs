#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class testApp : public ofBaseApp{

    public:
        ~testApp();/* destructor is very useful */		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        
        void audioRequested 	(float * input, int bufferSize, int nChannels);     
    
        //always run the empty example to see if it's working at first!!

        double outputs[2],moreoutputs[2]; //some track outputs
        double filtered,patch1,patch2,tune,delayed,mixed,ramp,filtered2,noise,pan,more;//a bunch of patch cables
        int beat,lastbeat,morebeats,lastmorebeats;//some rhythmic elemts
        double env[4]; //the kick drum pitch envelope data
        double env2[6]; //the hi hat pitch envelope dat
        double melody[14];//the melody data
        int rhythm1[16];//another way of doing a rhythm
        maxiOsc a,c,d,e,g,h,iwave,j,squarewave;//some oscillators
        maxiEnvelope b,f;//two envelopers
        maxiDelayline delay;//a delay line
        maxiFilter myfilter,antia;// a FAT filter
        maxiMix mymix,bobbins;//some panning busses
        maxiSample beats;
    
};
