#pragma once

#include "ofMain.h"
#include "ofxHistoryPlot.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofSerial mySerial;
    int slaveByte = 0;
    int masterByte = 0;
    
    unsigned char myByte = 65;
    
    static const int analogNumber = 6;
    int analogValue[analogNumber];
    
    ofxHistoryPlot * plot[analogNumber];
    void setupHistoryPlot(int number);
    float currentFrameRate = 0;
		
};
