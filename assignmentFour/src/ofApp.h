#pragma once

#include "ofMain.h"
#include "AudioAnalyser.h"
#include "ofxAssimpModelLoader.h"
#include "consts.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);

        ofFmodSoundPlayer m_soundPlayer;

        AudioAnalyser m_audioAnalyser;

        ofTrueTypeFont m_font;

        bool m_currentMode;

        static const int m_numberOfInstruments = 4;

        float m_circleBrightness[m_numberOfInstruments];
        float m_instrument[m_numberOfInstruments];

        void graphMode();
        void visualizerMode();
		
};
