#include "ofApp.h"

//face variables

int faceWidth = 180;
int faceHeight = 180;

int strokeThickness = 12;

int eyeDistanceX = 40;
int eyeDistanceY = 2;
int eyeSize = 12;

int eyebrowDistanceX = 33;
int eyebrowDistanceY = 32;
int eyebrowWidth = 30;
int eyebrowHeight = 12;

int mouthWidth = 30;

//controls
int slideNumber = 0;
float currentTime = 0;

//sound
of SoundPlayer mySound;


//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    
    ofSetCircleResolution(100);
    ofEnableSmoothing();

    mySound.load("game_music.wav");
}

//--------------------------------------------------------------
void ofApp::update(){
      if ((ofGetFrameNum() % 120) == 0) {
       if (!mySound.isPlaying()) {
            mySound.play();
       }
       if (slideNumber > 2){
           slideNumber = 0;
       } else {
           slideNumber++;
           //reset timer
           currentTime = ofGetFrameNum();
           ofLog(OF_LOG_NOTICE, ofToString(currentTime));
       }
   }
}

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(135, 214, 235);
    drawFace(ofGetWidth()/2, ofGetHeight()/2);
    
    if (slideNumber == 0) {
        drawSadParts(ofGetWidth()/2, ofGetHeight()/2);
      
    }
    if (slideNumber == 1) {
        drawSurprisedParts(ofGetWidth()/2, ofGetHeight()/2);
   }
    if (slideNumber == 2) {
        drawAngryParts(ofGetWidth()/2, ofGetHeight()/2);
        
   }
    if (slideNumber == 3) {
        drawHappyParts(ofGetWidth()/2, ofGetHeight()/2);
    }
    
    if ((ofGetFrameNum() % 120) == 0) {
        if (slideNumber > 2){
            slideNumber = 0;
        } else {
            slideNumber++;
            //reset timer
            currentTime = ofGetFrameNum();
            ofLog(OF_LOG_NOTICE, ofToString(currentTime));
        }
    }
    
}

void ofApp::drawPolygons(){
    path.moveTo(0,0-170,0);
    path.lineTo(-110,-80,0);
    path.lineTo(-37,-80,60);
    path.lineTo(+37,-80,60);
    path.lineTo(+110,-80,0);
    path.lineTo(0,-170,0);
    path.lineTo(-37,-80,60);
    path.lineTo(+37,-80,60);
    
    path.lineTo(0,-170,0);
    path.lineTo(-110,-80,0);
    path.lineTo(-37,-80,-60);
    path.lineTo(+37,-80,-60);
    path.lineTo(+110,-80,0);
    path.lineTo(0,-170,0);
    path.lineTo(-37,-80,-60);
    path.lineTo(+37,-80,-60);
    path.lineTo(0,-170,0);
    
    
    path.close();
    path.setStrokeColor(black);
    path.setStrokeWidth(4);
    path.setFilled(false);
    
    path.draw();
}

void ofApp::drawPolygonsUp(){
    ofPushMatrix();
    ofTranslate(windowWidth*0.5, windowHeight*0.5,0);
    ofRotateYDeg(rAngle);
    drawPolygons();
    ofPopMatrix();
}

void ofApp::drawFace(int x, int y) {
    //outline of face
   ofSetColor(black);
//    faceOutline.width = faceWidth + (2 * strokeThickness);
//    faceOutline.height = faceHeight + (2 * strokeThickness);
//    faceOutline.x =  x - (faceOutline.width/2);
//    faceOutline.y = y - (faceOutline.height/2);
   ofDrawCircle( x- (faceWidth + (2 * strokeThickness)/2) ,y (faceHeight + (2 * strokeThickness)/2), 60);
   
   //face
   ofSetColor(white);
//    face.width = faceWidth;
//    face.height = faceHeight;
//    face.x = x - faceWidth/2;
//    face.y = y - faceHeight/2;
   ofDrawRectRounded(x - faceWidth/2, y - faceHeight/2, faceWidth, faceHeight);
   
   //left eye
   ofSetColor(black);
   ofDrawCircle(x - eyeDistanceX , y - eyeDistanceY , eyeSize);

   //right eye
   ofDrawCircle(x + eyeDistanceX , y - eyeDistanceY , eyeSize);
   
   
}
void ofApp::drawAngryParts(int x, int y) {
    
    int leftEBX = x - eyebrowDistanceX/2;
    int leftEBY = y ;
    int rightEBX = x + eyebrowDistanceX/2;
    int rightEBY = y ;
    
    //left eyebrow
    ofPushMatrix();
    ofTranslate(leftEBX, leftEBY);
    ofRotateDeg(0.1 * (ofGetFrameNum() - currentTime));
    ofDrawRectangle(-eyebrowDistanceX/2 - eyebrowWidth, - eyebrowDistanceY/2, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();

    //right eyebrow
    ofPushMatrix();
    ofTranslate(rightEBX, rightEBY);
    ofRotateDeg(-0.1 * (ofGetFrameNum() - currentTime) );
    ofDrawRectangle(eyebrowDistanceX/2, -eyebrowDistanceY/2, eyebrowWidth, eyebrowHeight);
     ofPopMatrix();
    
    //angry mouth
    ofDrawBezier(x - 10, y + 20 + (0.03 * (ofGetFrameNum() - currentTime)),
                 x - 10, y + 20 - (0.05 * (ofGetFrameNum() - currentTime)),
                 x + 10, y + 20 - (0.05 * (ofGetFrameNum() - currentTime)),
                 x + 10, y + 20 + (0.03 * (ofGetFrameNum() - currentTime))
                 );
}

void ofApp::drawSadParts(int x, int y) {
    
    int leftEBX = x - eyebrowDistanceX/2;
    int leftEBY = y ;
    int rightEBX = x + eyebrowDistanceX/2;
    int rightEBY = y ;
    
    //left eyebrow
    ofPushMatrix();
    ofTranslate(leftEBX, leftEBY);
    ofRotateDeg(-0.1 * (ofGetFrameNum() - currentTime));
    ofDrawRectangle(-eyebrowDistanceX/2 - eyebrowWidth, - eyebrowDistanceY, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();

    //right eyebrow
    ofPushMatrix();
    ofTranslate(rightEBX, rightEBY);
    ofRotateDeg(0.1 * (ofGetFrameNum() - currentTime) );
    ofDrawRectangle(eyebrowDistanceX/2, -eyebrowDistanceY, eyebrowWidth, eyebrowHeight);
     ofPopMatrix();

    //angry mouth
    ofDrawBezier(x - 10, y + 20 + 0.03 * (ofGetFrameNum() - currentTime),
                 x - 10, y + 20 - 0.05 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 20 - 0.05 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 20 + 0.03 * (ofGetFrameNum() - currentTime)
                 );
}

void ofApp::drawHappyParts(int x, int y) {
    
    int leftEBX = x - eyebrowDistanceX/2;
    int leftEBY = y ;
    int rightEBX = x + eyebrowDistanceX/2;
    int rightEBY = y ;
    
    //left eyebrow
   ofDrawRectangle(x - eyebrowDistanceX - eyebrowWidth,  y - eyebrowDistanceY
                   - 0.05 * (ofGetFrameNum() - currentTime),
                   eyebrowWidth, eyebrowHeight);
   //right eyebrow
   ofDrawRectangle(x + eyebrowDistanceX, y - eyebrowDistanceY
                   - 0.05 * (ofGetFrameNum() - currentTime),
                   eyebrowWidth, eyebrowHeight);
    
    ofDrawBezier(x - 10, y + 20 + 0.05 * (ofGetFrameNum() - currentTime),
                 x - 10, y + 20 + 0.2 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 20 + 0.2 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 20 + 0.05 * (ofGetFrameNum() - currentTime)
                 );
}
void ofApp::drawSurprisedParts(int x, int y) {
    
    int leftEBX = x - eyebrowDistanceX/2;
    int leftEBY = y ;
    int rightEBX = x + eyebrowDistanceX/2;
    int rightEBY = y ;
    
    //left eyebrow
   ofDrawRectangle(x - eyebrowDistanceX - eyebrowWidth,  y - eyebrowDistanceY
                   - 0.02 * (ofGetFrameNum() - currentTime),
                   eyebrowWidth, eyebrowHeight);
   //right eyebrow
   ofDrawRectangle(x + eyebrowDistanceX, y - eyebrowDistanceY
                   - 0.02 * (ofGetFrameNum() - currentTime),
                   eyebrowWidth, eyebrowHeight);
    
    ofDrawBezier(x - 10, y + 25 ,
                 x - 10, y + 25 - 0.1 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 25 - 0.1 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 25
                 );
    ofDrawBezier(x - 10, y + 25 ,
                 x - 10, y + 25 + 0.08 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 25 + 0.08 * (ofGetFrameNum() - currentTime),
                 x + 10, y + 25
                 );
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

if(key == 'p'){
        mySound.play();
        ofLog(OF_LOG_NOTICE, "p pressed");
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}