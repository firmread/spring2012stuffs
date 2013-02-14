#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    video.initGrabber(320,240);
    //pixels is actually = pixels [thexx.width * thexx.height * 3];
    
	ofSoundStreamSetup(0, 2, this, 44100, 512, 4);
	inputBufferCopy = new float [512 *2];
    
    spreadbase = 3;
    spreadmultiplier = .5;
    
    boxbase = 1;
    boxmultiplier = 20;
    
    setGUI(); 
}

//--------------------------------------------------------------
void testApp::update(){

    video.update();
    if(video.isFrameNew()){
        pixels = video.getPixels();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(red, blue, green);
    
    //grid
    ofEnableAlphaBlending();
    if(bdrawGrid)
	{
		ofSetColor(255, 255, 255, 25);	
		drawGrid(8,8); 
	}
    
    //cloud
    int spread = spreadbase + volume* spreadmultiplier;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2,-400+spread*100);
    ofRotateX(ofMap(mouseY, 0, ofGetHeight(), 60, -60));
    ofRotateY(ofMap(mouseX, 0, ofGetWidth(), -60, 60));
    ofPushMatrix();
    ofTranslate((-320*spread)/2, (-240*spread)/2);
    for (int y=0; y<video.getHeight(); y+=2) {
        //first row
        for(int x=0; x<video.getWidth(); x+=2){
            //pixel by pixel on each row
            // this is going to loop through every (x,y) coordinate

            int i = ((y*video.getWidth()) + x) * 3;
            int r = pixels [i];
            int g = pixels [i+1];
            int b = pixels [i+2];
            int brightness = (r+g+b)/3.0;
            
            ofPushMatrix();
            ofTranslate(0, 0, -brightness*1.5);
            ofSetColor(r, g, b);
            int boxsize;
            boxsize = boxbase + volume* boxmultiplier;
            if(boxsize > boxbase + boxmultiplier) boxsize = boxbase + boxmultiplier;
            
//            ofBox(x*spread, y*spread, -brightness*1.5, boxsize);
//            ofRect(x*spread, y*spread, boxsize, boxsize);
            ofCircle(x*spread, y*spread, boxsize);
            
            ofPopMatrix();
        }
    }
    
    ofPopMatrix();
    ofPopMatrix();
    
    //volume UI
    ofSetColor(255, 255, 255, 150);	
    ofCircle(125, 650, volume*100);
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::audioReceived(float *input, int bufferSize, int nChannels){
	memcpy(inputBufferCopy, input, bufferSize*nChannels*sizeof(float));
	volume = 0;
	for(int i = 0; i < bufferSize * nChannels; i++){
		volume+= input[i]*input[i]; // add the square value to emliminate any negative values
	}
	volume /= bufferSize *nChannels; // get the average of all square values
	volume = sqrt(volume);
}


//--------------------------------------------------------------
void testApp::exit()
{
	delete gui; 
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) 
	{			
		case 'f':
			ofToggleFullscreen(); 
			break;
            
		case 'h':
            gui->toggleVisible();            
			break;
            
		case 'p':
			bdrawPadding = !bdrawPadding; 
			gui->setDrawPadding(bdrawPadding); 			            
			break;			
			
		default:
			break;
	}

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
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName(); 
	int kind = e.widget->getKind(); 
	cout << "got event from: " << name << endl; 	
	
	if(name == "RED")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "RED " << slider->getScaledValue() << endl; 
		red = slider->getScaledValue(); 
	}
	else if(name == "GREEN")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "GREEN " << slider->getScaledValue() << endl; 
		green = slider->getScaledValue(); 
	}
	else if(name == "BLUE")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "BLUE " << slider->getScaledValue() << endl; 
		blue = slider->getScaledValue(); 		
	}
    
    else if(name == "Spread Base")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Spread Base" << slider->getScaledValue() << endl; 
		spreadbase = slider->getScaledValue(); 		
	}	
    else if(name == "Spread Multiplier")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Spread Multiplier " << slider->getScaledValue() << endl; 
		spreadmultiplier = slider->getScaledValue(); 		
	}	
    else if(name == "Boxsize Base")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Boxsize Base " << slider->getScaledValue() << endl; 
		boxbase = slider->getScaledValue(); 		
	}	
    else if(name == "Boxsize Multiplier")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Boxsize Multiplier " << slider->getScaledValue() << endl; 
		boxmultiplier = slider->getScaledValue(); 		
	}
	else if(name == "Draw Grid")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget; 
		bdrawGrid = toggle->getValue(); 
	}
	
	
	
}

//--------------------------------------------------------------

void testApp::drawGrid(float x, float y)
{
    float w = ofGetWidth(); 
    float h = ofGetHeight(); 
    
    for(int i = 0; i < h; i+=y)
    {
        ofLine(0,i,w,i); 
    }
    
    for(int j = 0; j < w; j+=x)
    {
        ofLine(j,0,j,h); 
    }    
}
//--------------------------------------------------------------

void testApp::setGUI()
{
	red = 233; blue = 52; green = 27; 
	
	float dim = 16; 
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 255-xInit; 
	hideGUI = false; 
	
	gui = new ofxUICanvas(0, 0, length+xInit, ofGetHeight()); 
	gui->addWidgetDown(new ofxUILabel("PIXEL POINT CLOUD", OFX_UI_FONT_LARGE)); 
    gui->addWidgetDown(new ofxUILabel("Press 'h' to Hide GUIs", OFX_UI_FONT_SMALL)); 
    
    gui->addWidgetDown(new ofxUISpacer(length-xInit, 2)); 
	gui->addWidgetDown(new ofxUILabel("Background Color", OFX_UI_FONT_MEDIUM)); 
	gui->addWidgetDown(new ofxUISlider(length-xInit,dim, 0.0, 255.0, red, "RED")); 
	gui->addWidgetDown(new ofxUISlider(length-xInit,dim, 0.0, 255.0, green, "GREEN")); 
	gui->addWidgetDown(new ofxUISlider(length-xInit,dim, 0.0, 255.0, blue, "BLUE")); 	
    
    gui->addWidgetDown(new ofxUISpacer(length-xInit, 2)); 
    gui->addWidgetDown(new ofxUILabel("Spread", OFX_UI_FONT_MEDIUM)); 
	gui->addWidgetDown(new ofxUISlider(length-xInit,dim, 1.0, 10.0, spreadbase, "Spread Base")); 
	gui->addWidgetDown(new ofxUISlider(length-xInit,dim, 0.0, 2.0, spreadmultiplier, "Spread Multiplier")); 
    
	gui->addWidgetDown(new ofxUISpacer(length-xInit, 2)); 
    gui->addWidgetDown(new ofxUILabel("Boxsize", OFX_UI_FONT_MEDIUM)); 
	gui->addWidgetDown(new ofxUISlider(length-xInit,dim, 1.0, 10.0, boxbase, "Boxsize Base")); 
	gui->addWidgetDown(new ofxUISlider(length-xInit,dim, 0.0, 20.0, boxmultiplier, "Boxsize Multiplier")); 
    
    gui->addWidgetDown(new ofxUISpacer(length-xInit, 2)); 	
	gui->addWidgetDown(new ofxUILabel("Grid", OFX_UI_FONT_MEDIUM)); 
	gui->addWidgetDown(new ofxUIToggle( dim, dim, false, "Draw Grid")); 	
    
	gui->addWidgetDown(new ofxUILabel("Volume", OFX_UI_FONT_MEDIUM)); 
    
    
//    gui->addWidgetDown(new ofxUISpacer(length-xInit, 2)); 
//    gui->addWidgetDown(new ofxUILabel("RANGE SLIDER", OFX_UI_FONT_MEDIUM)); 
//	  gui->addWidgetDown(new ofxUIRangeSlider(length-xInit,dim, 0.0, 255.0, 50.0, 100.0, "RSLIDER")); 	
    	
    
    bdrawGrid = true; 
	bdrawPadding = false; 
	ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);
}
