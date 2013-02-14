#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(30);
    
    mode = 0;
    
    // 0 == add to stack
    // 1 = nothing
    // 2 = draw
    // 3 = move
    
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofBackground(128);
    
    
    ofSetColor(255);
    for(int i=0; i<lines.size(); i++){
        ofPushMatrix();
        ofTranslate(centers[i]);
        lines[i].draw();
        ofPopMatrix();
    }
    
    if( currentLine.size() ){
        ofPushMatrix();
        ofTranslate(currentCenter);
        currentLine.draw();
        ofPopMatrix();
    }

 ofDrawBitmapString("mode "+ofToString(mode), 5, 20);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case '0':
        {
            ofPolyline p;
            p.addVertexes(currentLine.getVertices());
            cout << p.size() << endl;
            lines.push_back(p);
            centers.push_back(currentCenter);
            currentLine.clear();
            mode = 1;
            break;
        }
        case 1:
            break;
        case '2':
            mode = 2;
            break;
        case '3':
            mode = 3;
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

    
    
  }

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    if(mode == 2){
        currentLine.addVertex(x, y);
        currentCenter = ofPoint(0, 0);
        //currentCenter = ofPoint(320, 240);
    }
    if(mode == 3){
        currentCenter = ofPoint(x, y);
    }
    


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