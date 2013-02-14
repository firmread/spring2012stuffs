#pragma once

#include "ofMain.h"
#include "ofxUI.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
        void draw();
        void exit();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        
        ofVideoGrabber video;
        unsigned char* pixels;
    
        //sound
        void audioReceived(float *input, int bufferSize, int nChannels);
        float volume;
        float *inputBufferCopy;
    
        //ofxUI
        void drawGrid(float x, float y); 
        
        void setGUI(); 
        ofxUICanvas *gui; 
    
        bool hideGUI; 
        bool bdrawGrid; 
        bool bdrawPadding; 
    
        void guiEvent(ofxUIEventArgs &e);
    
        float red, green, blue; 
    
        float spreadbase;
        float spreadmultiplier;
        
        float boxbase;
        float boxmultiplier;
};
