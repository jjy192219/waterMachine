#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
class ofApp : public ofBaseApp{

    struct CELL{
        ofRectangle     rect;
        bool            bTouched;
        ofSoundPlayer   sound;
    };
    
	public:
		void setup();
		void update();
		void draw();
        void keyReleased(int key);
    
        ofVideoGrabber          mVideoGraber;
        vector<ofSoundPlayer>   mSounds;
        vector<ofRectangle>     mRects;
        vector<CELL>            mCells;
    
        int                     mCamWidth;
        int                     mCamHeight;
        int                     mThreshold;
        int                     mPerCellWidth;
        int                     mPerCellHeight;
        int                     mCellLeftMargin;
        int                     mCellTopMargin;
    
        ofxCvColorImage         mColorImage;
        ofxCvGrayscaleImage     mGrayImage;
        ofxCvGrayscaleImage     mGrayBg;
        ofxCvGrayscaleImage     mGrayDiff;
        ofxCvContourFinder      mContourFinder;
    
		
};
