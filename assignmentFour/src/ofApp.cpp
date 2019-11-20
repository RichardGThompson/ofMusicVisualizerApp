#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(consts::windowWidth, consts::windowHeight);
    
    m_font.load(consts::fontPath, 10, true);
    
    m_soundPlayer.load(consts::musicPath);
    m_soundPlayer.setLoop(true);
    m_soundPlayer.play();

    m_audioAnalyser.init(&m_soundPlayer, 20);

    m_currentMode = 0;

    //m_soundPlayer.setPositionMS(31 * 1000);
}

//--------------------------------------------------------------
void ofApp::update(){
    m_audioAnalyser.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //Drawing based on the current mode the program is in.
    switch (m_currentMode) {
    //Draw the graph mode (basically the debugging mode)
    case 0:
        graphMode();
        break;
    //Draw the regular music visualizer mode.
    case 1:
        visualizerMode();
        break;
    }
}

void ofApp::keyPressed(int key) {
    if (key == 32) {
        //Set the current mode to the opposite of the current mode.
        m_currentMode = !m_currentMode;
    }
}

void ofApp::graphMode() {
    ofBackground(ofColor::black);
    ofSetColor(255);

    ofSetColor(ofColor::white);
    m_font.drawString("Volume Level", 140, 50);

    ofDrawCircle(100, 100, m_audioAnalyser.getLeftLevel() * 100.0f);
    ofDrawCircle(200, 100, m_audioAnalyser.getRightLevel() * 100.0f);
    ofDrawCircle(300, 100, m_audioAnalyser.getMixLevel() * 100.0f);

    m_audioAnalyser.drawWaveform(40, 300, 1200, 90);
    m_audioAnalyser.drawSpectrum(40, 460, 1200, 128);

    m_audioAnalyser.drawLinearAverages(40, 650, 1200, 128);

    //Bass Drum - min 100 max 200.
    /*m_instrument[0] = m_audioAnalyser.getLinearAverage(1);
    m_circleBrightness[0] = ofMap(m_instrument[0], 150.0f, 200.0f, 0.0f, 1.0f, true);
    ofSetColor(ofFloatColor(m_circleBrightness[0], 0, 0));
    ofDrawCircle(500, 100, 50);
    m_font.drawString("Bass Drum", 500, 170);*/

    ofSetColor(255);
    float timeInSeconds = m_soundPlayer.getPositionMS() / 1000.0f;
    m_font.drawString("Song Time: " + ofToString(timeInSeconds), 40, 250);
}

void ofApp::visualizerMode() {
    m_audioAnalyser.styleSpectrum(0, consts::windowHeight/2.0f - 250, consts::windowWidth, 250);
}