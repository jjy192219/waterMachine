#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    mCamWidth = ofGetWindowWidth();
    mCamHeight = ofGetWindowHeight();
    
    mPerCellWidth = mCamWidth*0.08;
    mPerCellHeight = mCamHeight/5;
    mCellTopMargin = 0;
    mCellLeftMargin = mCamWidth/2;
    
    mVideoGraber.setDeviceID(0);
    mVideoGraber.initGrabber(mCamWidth, mCamHeight);
    mColorImage.allocate(mCamWidth, mCamHeight);
    mGrayImage.allocate(mCamWidth, mCamHeight);
    mThreshold = 100;
    bLearnBackground = true;
    
    mCells.clear();
    for (int i =0; i <= 4; i++){
        CELL tempCell;
        ofRectangle tempRect;
        tempRect.set(mCellLeftMargin, mPerCellHeight*i , mPerCellWidth,  mPerCellHeight);
        tempCell.rect = tempRect;
        tempCell.sound.load( "tone"+ofToString(i)+".mp3");
        tempCell.bTouched = false;
        mCells.push_back(tempCell);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    mVideoGraber.update();
    if (mVideoGraber.isFrameNew()) {
        mColorImage.setFromPixels(mVideoGraber.getPixels());
        mGrayImage = mColorImage;
        if (bLearnBackground) {
            mGrayBg = mGrayImage;
            bLearnBackground = false;
        }
        mGrayDiff.absDiff(mGrayBg, mGrayImage);
        mGrayDiff.threshold(mThreshold);
        mContourFinder.findContours(mGrayDiff, 3, mCamWidth*mCamHeight/3, 10, false);
        intersect();
    }
}

void ofApp::intersect(){
    for (auto i:mCells) {
        for (auto j:mContourFinder.blobs) {
            if(j.boundingRect.intersects(i.rect)){
                i.bTouched = true;
                if(!i.sound.isPlaying()){
                    i.sound.play();
                }
            }else{
                i.bTouched = false;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(0, 0, 0);
    mVideoGraber.draw(0, 0, mCamWidth,mCamHeight);
    
    for (auto i:mCells) {
        if(i.sound.isPlaying()){
            ofFill();
            ofSetColor(204, 0, 0, 50);
            ofDrawRectangle(i.rect);
        }else{
            ofNoFill();
            ofSetColor(255, 255, 255);
            ofDrawRectangle(i.rect);
        }
    }
    
    for (auto i:mContourFinder.blobs) {
        i.draw();
    }
    
    ofSetHexColor(0xffffff);
    stringstream reportStr;
    reportStr << "bg subtraction and blob detection" << endl
    << "press ' ' to capture bg" << endl
    << "threshold " << mThreshold << " (press: +/-)" << endl
    << "num blobs found " << mContourFinder.nBlobs << ", fps: " << ofGetFrameRate();
    ofDrawBitmapString(reportStr.str(), 20, 600);
}

void ofApp::keyReleased(int key){
    switch (key){
        case ' ':
            bLearnBackground = true;
            break;
        case '+':
            mThreshold ++;
            if (mThreshold > 255) mThreshold = 255;
            break;
        case '-':
            mThreshold --;
            if (mThreshold < 0) mThreshold  = 0;
            break;
    }
}


