#pragma once

#include "ofMain.h"
// variable to be accessed by .h
// similar to CSS is for HTML


class testApp : public ofBaseApp{
// class name declared here
	public:
		void setup();
        // the same as in processing   
        void update();
        // buffering math in the computer,,, run continously not up to framerate
        // never show
		void draw();
        // to the screen
    
		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
