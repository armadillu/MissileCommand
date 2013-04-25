//
//  Constants.h
//  opencvExample
//
//  Created by Oriol Ferrer Mesià on 22/04/13.
//
//

#ifndef opencvExample_Constants_h
#define opencvExample_Constants_h

#define LEVEL_TIME				30.
#define BAD_MISSILE_SPEED		45
#define GOOD_MISSILE_SPEED		1050
#define EXPLOSION_RADIUS		40
#define EXPLOSION_DURATION		2.5
#define NUM_BAD_MISSILES		20
#define NUM_CITIES				6
#define NUM_SILOS				3
#define NUM_STARTUP_MISSILES	10
#define SILO_LEFT				ofVec2f( ofGetWidth() * 0.085, ofGetHeight() * 0.88 )
#define SILO_MID				ofVec2f( ofGetWidth() * 0.5, ofGetHeight() * 0.88 )
#define SILO_RIGHT				ofVec2f( ofGetWidth() * 0.915, ofGetHeight() * 0.88 )
#define START_BUTTON_POS		ofGetWidth()/2 - startButton.getWidth()/2, ofGetHeight()/2 + 2 * startButton.getHeight(), startButton.getWidth(), startButton.getHeight()

#define GAME_OVER_TIME			5
#define USE_REMOTE_CAMERA		

#define BAD_MISSILE_COLOR	ofColor(255,0,0)
#define GOOD_MISSILE_COLOR	ofColor(0,255,255)
#define CITY_COLOR			ofColor(255,255,255)
#define SILO_COLOR			ofColor(255,128,255)

enum TextureID{
	TEX_SMOKE, TEX_EXPLOSION, TEX_FIRE
};

#define PIXEL_SCALE 2


#endif
