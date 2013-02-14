//
//  circle.cpp
//  emptyExample
//
//  Created by firm on 11/11/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "circle.h"

//instantiator 
Circle::Circle (){
    
}

void Circle:: setup(){
    speed.x = ofRandom(1,3);
    speed.y = ofRandom(1,3);
    radius = ofRandom(5,15);
    
    pos.set(ofRandom(radius, ofGetWidth() - radius), 
               ofRandom(radius, ofGetHeight()- radius));
    
    //this is the same as above written in different syntax
    //pos[i].x=ofRandom(radius[i], ofGetWidth() - radius[i];
    //pos[i].y=ofRandom(radius[i], ofGetHeight()- radius[i];
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    
    //color[i].r = 
    //color[i].g = 
    //color[i].b = 
    //color[i].a = 
    
}

void Circle:: update( Circle &w ){
    pos.x += speed.x;
    pos.y += speed.y;
    
    if (pos.x < radius || pos.x > ofGetWidth() - radius){
        speed.x *= -1;
    }
    
    if (pos.y < radius || pos.y > ofGetHeight() - radius){
        speed.y *= -1; 
    }
    
    //check the distances of our circles
    //to see close to each other
    ofPoint dist;
    float diam;
    
    diam = radius + w.radius;
    
    dist = pos - w.pos;
    
    if(dist.x < diam || dist.y < diam) {
        speed.x *= -1;
        speed.y *= -1;
        w.speed.x *= -1;
        w.speed.y *= -1;
    }
}

void Circle:: draw(){
    ofSetColor(color);
    ofCircle(pos.x, pos.y, radius);

}