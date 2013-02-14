/*
 *  circle.cpp
 *  emptyExample
 *
 *  Created by chris on 11/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "circle.h"

Circle::Circle() {
	
}

void Circle::setup() {

	speed.x = ofRandom(2, 3);
	speed.y = ofRandom(2, 3);
	
	radius = ofRandom(5, 15);
	
	pos.set( ofRandom( radius, ofGetWidth() - radius ), 
			   ofRandom( radius, ofGetHeight() - radius ) );
	
	//this is the same as above written in different syntax
	//pos.x = ofRandom( radius, ofGetWidth() - radius );
	//pos.y = ofRandom( radius, ofGetHeight() - radius );
	
	color.set( ofRandom(255), ofRandom(255), ofRandom(255) );
	
	
}


void Circle::update( Circle &w ) {

	
	pos.x += speed.x;
	pos.y += speed.y;
	
	
	if (pos.x < radius || pos.x > ofGetWidth() - radius) {
		speed.x *= -1;
	}
	
	if (pos.y < radius || pos.y > ofGetHeight() - radius) {
		speed.y *= -1;
	}
	
	//check the distances of our circles
	//to see if they are too close to eachother.
	float dist;
	float diam;
	
	diam = radius + w.radius;
	
	dist = ofDist(pos.x, pos.y, w.pos.x, w.pos.y);
	
	if ( dist <= diam ) {
	
		speed.x *= -1;
		speed.y *= -1;
		w.speed.x *= -1;
		w.speed.y *= -1;
		
	}

}


void Circle::draw() {

	ofSetColor(color);
	ofCircle(pos.x, pos.y, radius);
	

}






