#pragma once

#include "ofMain.h"
#include "Obj2D.h"
#include "Missile.h"
#include "City.h"
#include "Silo.h"
#include "Constants.h"
#include "LaserPointer.h"
#include "ofxRemoteCameraClient.h"

#include "Explosion.h"



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
		Silo * bestSiloForTarget(ofVec2f target);
		vector<City> cities;
		vector<Silo*> silos;
		vector<Missile*> badMissiles;
		vector<Missile*> playerMissiles;
		float levelTime;
		Explosion e;



		gameState state;
		ofImage city;
		ofImage silo;
		ofImage bg;
		ofSoundPlayer startup, launch, explode;

		///////////
		
		ofxRemoteCameraClient	remoteCam;
		LaserPointer			laser;

	//////////

	//expolosions

	float strength;
	float numP;
	float friction;
	float life;
	float offset;
	float spawnOffset;
	float smokeLife;
	float gravity;

};
