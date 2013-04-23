#pragma once

#include "ofMain.h"
#include "Obj2D.h"
#include "Missile.h"
#include "Constants.h"
#include "LaserPointer.h"
#include "ofxRemoteCameraClient.h"


class testApp : public ofBaseApp{

	enum gameState{PLAYING};

	public:

		void setup();
		void update();
		void draw();
		void exit();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void startLevel();
		vector<Obj2D> cities;
		vector<Missile*> badMissiles;
		vector<Missile*> playerMissiles;
		float levelTime;

	gameState state;
	ofImage city;
	ofImage bg;

///////////
	
	ofxRemoteCameraClient	remoteCam;
	LaserPointer			laser;

};
