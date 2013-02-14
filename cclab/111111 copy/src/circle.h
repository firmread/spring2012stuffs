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
    void setup();
    void draw();
    void update();
    
    ofPoint speed[NUM_CIRCLES];
    // ofPoint holding x,y position
    ofPoint pos[NUM_CIRCLES];
    float radius[NUM_CIRCLES];
    ofColor color[NUM_CIRCLES];

};