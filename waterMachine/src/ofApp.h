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
        void intersect();
    
        ofVideoGrabber          mVideoGraber;
        vector<CELL>            mCells;
    
        int                     mCamWidth;
        int                     mCamHeight;
        int                     mThreshold;
        int                     mPerCellWidth;
        int                     mPerCellHeight;
        int                     mCellLeftMargin;
        int                     mCellTopMargin;
        bool                    bLearnBackground;
    
        ofxCvColorImage         mColorImage;
        ofxCvGrayscaleImage     mGrayImage;
        ofxCvGrayscaleImage     mGrayBg;
        ofxCvGrayscaleImage     mGrayDiff;
        ofxCvContourFinder      mContourFinder;
    
		
};
