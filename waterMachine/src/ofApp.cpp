#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mCamWidth = 320;
    mCamHeight = 240;
    
    mPerCellWidth = mCamWidth*0.05;
    mPerCellHeight = mCamHeight/5;
    mCellTopMargin = 0;
    mCellLeftMargin = mCamWidth/2;
    
    mVideoGraber.setDeviceID(0);
    mVideoGraber.setVerbose(true);
    mVideoGraber.initGrabber(mCamWidth, mCamHeight);
    mColorImage.allocate(mCamWidth, mCamHeight);
    mGrayImage.allocate(mCamWidth, mCamHeight);
    
    mSounds.clear();
    for (int i =0; i<=4; i++) {
        ofSoundPlayer tempSound;
        string fileName = "tone"+ofToString(i)+".mp3";
        tempSound.load(fileName);
        mSounds.push_back(tempSound);
    }
    
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
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(0, 0, 0);
//    mVideoGraber.draw(0, 0, mCamWidth,mCamHeight);
    mColorImage.draw(0, 0);
    for (auto i:mCells) {
        ofNoFill();
        ofSetColor(204, 204, 204);
        ofDrawRectangle(i.rect);
    }
}

void ofApp::keyReleased(int key){

    switch (key){
        case '0': mSounds[0].play();
        case '1': mSounds[1].play();
        case '2': mSounds[2].play();
        case '3': mSounds[3].play();
        case '4': mSounds[4].play();
            
    }
}


