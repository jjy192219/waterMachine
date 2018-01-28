#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mCamWidth = 640;
    mCamHeight = 480;
    
    mVideoGraber.setDeviceID(1);
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


