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
#define GOOD_MISSILE_SPEED		1550
#define EXPLOSION_RADIUS		40
#define EXPLOSION_DURATION		2.5
#define NUM_BAD_MISSILES		20
#define NUM_CITIES				4
#define NUM_SILOS				3
#define NUM_STARTUP_MISSILES	10
#define SILO_LEFT				ofVec2f( ofGetWidth() * 0.02, ofGetHeight() * 0.9 )
#define SILO_MID				ofVec2f( ofGetWidth() * 0.5, ofGetHeight() * 0.9 )
#define SILO_RIGHT				ofVec2f( ofGetWidth() * 0.98, ofGetHeight() * 0.9 )
#define START_BUTTON_POS		ofGetWidth()/2 - startButton.getWidth()/2, ofGetHeight()/2 + 2 * startButton.getHeight(), startButton.getWidth(), startButton.getHeight()

#define GAME_OVER_TIME			5
#define USE_REMOTE_CAMERA		

enum TextureID{
	TEX_SMOKE, TEX_EXPLOSION, TEX_FIRE
};

#define PIXEL_SCALE 2


#endif
