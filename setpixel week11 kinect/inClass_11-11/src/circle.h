/*
 *  circle.h
 *  emptyExample
 *
 *  Created by chris on 11/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#pragma once
#include "ofMain.h"


class Circle {
	
	public:
		Circle();
		
		void setup();
		void update( Circle  &w );
		void draw();

		ofPoint speed;
		ofPoint pos;
		float radius;
		ofColor color;

};