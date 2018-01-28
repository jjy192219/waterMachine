#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyReleased(int key);
    
        ofVideoGrabber          mVideoGraber;
        vector<ofSoundPlayer>   mSounds;
        vector<ofRectangle>     mRects;
        int                     mCamWidth;
        int                     mCamHeight;
        int                     mThreshold;
    
        ofxCvColorImage         mColorImage;
        ofxCvGrayscaleImage     mGrayImage;
        ofxCvGrayscaleImage     mGrayBg;
        ofxCvGrayscaleImage     mGrayDiff;
        ofxCvContourFinder      mContourFinder;
    
		
};
