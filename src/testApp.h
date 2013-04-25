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

	enum gameState{PLAYING, START_SCREEN, END_LEVEL};

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

		void nextLevel();
		void gameOver();
		float gameOverTimer;

		Silo * bestSiloForTarget(ofVec2f target);
		vector<City> cities;
		vector<Silo*> silos;
		vector<Missile*> badMissiles;
		vector<Missile*> playerMissiles;
		float levelTime;
		Explosion e;


		gameState state;
		int currentLevel;
	
		ofImage city;
		ofImage silo;
		ofImage bg;
		ofImage logo;
		ofImage startButton;

		ofSoundPlayer startup, launch, explode, empty;

		ofTrueTypeFont font;	

		///////////
		
		ofxRemoteCameraClient	remoteCam;
		LaserPointer			laser;


	//GRAFFITI

	int currentLine;
	vector< vector<ofPoint> > lines;

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
