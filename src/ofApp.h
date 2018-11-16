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
    
    ofTrueTypeFont font;
    
    ofSerial mySerial;
    int slaveByte = 0;
    int masterByte = 0;
    
    unsigned char myByte = 65;
    
    static const int TOTAL_ANALOG_NUM = 6;
    int analogValue[TOTAL_ANALOG_NUM];
    
    ofxHistoryPlot * plot[TOTAL_ANALOG_NUM];
    void setupHistoryPlot(int number);
    float currentFrameRate = 0;
    
    int delta[3] = {0};
		
};
