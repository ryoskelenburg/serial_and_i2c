#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    ofBackground(0, 0, 0);
    mySerial.setup("/dev/cu.usbmodem14101",9600);
    
    for (int i = 0; i < TOTAL_ANALOG_NUM; i++) {
        setupHistoryPlot(i);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    currentFrameRate = ofGetFrameRate();
    if (mySerial.isInitialized()) {
        while (mySerial.available() >= TOTAL_ANALOG_NUM) {
            for (int i = 0; i < TOTAL_ANALOG_NUM; i++){
                analogValue[i] = mySerial.readByte();
                plot[i]->update(analogValue[i]);
            }
            mySerial.writeByte(myByte);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < TOTAL_ANALOG_NUM - 3; i++) {
        plot[i]->draw(0, 200 * i + 50, ofGetWidth(), 150);
    }
    for (int i = 3; i < TOTAL_ANALOG_NUM; i++) {
        plot[i]->draw(0, 200 * (i-3) + 50, ofGetWidth(), 150);
    }
    
    //std::cout << ofToString(mySerial.available()) << endl;
}

void ofApp::setupHistoryPlot(int number){
    plot[number] = new ofxHistoryPlot(&currentFrameRate, "number:00" + ofToString(number), ofGetWidth()/2, false);
    plot[number]->setBackgroundColor(ofColor(0,0,0,0));
    plot[number]->setColor(ofColor(ofRandom( 100, 255 ),ofRandom( 100, 255 ),ofRandom( 100, 255 )));
    plot[number]->setRange(-10, 100 + 10);
    plot[number]->setRespectBorders(false);
    plot[number]->setLineWidth(2);
    plot[number]->setCropToRect(false);
    plot[number]->setShowSmoothedCurve(false);
    plot[number]->setSmoothFilter(0.1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
    
    mySerial.writeByte(myByte);
    //if ( !byteWasWritten )
     //   printf("byte was not written to serial port");
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
