//
//  circle.h
//  emptyExample
//
//  Created by firm on 11/11/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#pragma once
// include this once
#include "ofMain.h"
// include of shitsss

class Circle {
    
    public:
    //give access to other code
    //private, protected
    
    Circle();
    
    void setup();
    void draw();
    void update( Circle &w );
    
    ofPoint speed;
    // ofPoint holding x,y position
    ofPoint pos;
    float radius;
    ofColor color;

};