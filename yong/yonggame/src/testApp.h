#pragma once

#include "ofMain.h"

////added
//int RandomDog, RandomCat;
//
//ofImage dog;
//ofImage cat;
// 
//int totalNumber;
//// added



class baseScene {
    
    public:
    
    virtual void setup(){}
    virtual void update(){}
    virtual void draw(){}
    
};

// 1st screen
class channel1Scene : public baseScene {
    
    
    
    void setup(){
        test.loadImage("images/screenone.png");
    }
    void update() { }
    void draw(){ 
        
        ofSetColor(255);    //      no background
        test.draw(0,0);     //      draw 
        
        ofSetColor(128,0,255);
       // ofRect(20,20, 100,100);  
        ofDrawBitmapString("channel 1", 20, 530); 


    
    }
    
    ofImage test;
    

    
    
};

//2nd screen
class channel2Scene : public baseScene {
    ofImage dog;
    ofImage cat;
    ofImage test;
    
    float pos;
    
    //added
    int RandomDog, RandomCat;

     
    int totalNumber;
    // added

    
    void setup(){  
        test.loadImage("images/screentwo.png");
        
        // added
        dog.loadImage("images/dog.png");
        cat.loadImage("images/cat.png");
        
        RandomDog = ofRandom(5);
        RandomCat = ofRandom(5);   
        // added
        
        
     //   pos = 100;
    }
    void update() { pos += ofRandom(-1,1); }
    void draw(){ 
  
        
        ofSetColor(255);    //      no background
        test.draw(0,0);     //      draw 
        
        
        ofDrawBitmapString("channel 2", 20, 530); 
        
        for( int i = 0; i< RandomDog; i++){
            dog.draw(i*115+200, 430);
            
        }
        
        for( int i = 0; i< RandomCat; i++){
            cat.draw(i*115+200, 101+430);
            
        }
        
        totalNumber = RandomDog + RandomCat;
        cout << totalNumber << "\n";

    }
    
    
 
    
};

// 3rd screen
class channel3Scene : public baseScene {
    
    void setup(){
         test.loadImage("images/screenthree.png");
    }
    void update() { }
    void draw(){  
        ofSetColor(255);    //      no background
        test.draw(0,0);     //      draw 
        
        ofLine(50,50,300,300);
        ofDrawBitmapString("channel 3", 20, 530); 
        
//        test.draw(ofGetWidth()/2,ofGetHeight()/2); //center point
    }
    
    ofImage test;
    
    
};





class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        float translate;
        float translateTarget;
    
        vector < baseScene * > scenes;
        int whichScene;
    
    
        ofImage dog;
        ofImage cat;
    
        int RandomDog, RandomCat;
        int totalNumber;
    
    
    

};
