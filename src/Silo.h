//
//  Silo.h
//  opencvExample
//
//  Created by Oriol Ferrer Mesià on 24/04/13.
//
//

#ifndef opencvExample_Silo_h
#define opencvExample_Silo_h

#include "ofMain.h"
#include "City.h"
//#include "Missile.h"

class Missile;

class Silo : public City{

public:

	void setup(ofImage * img){
		City::setup(img); //superclass needs img ptr
		resetMissiles();
		missileSpeed = BAD_MISSILE_SPEED;
	}


	void resetMissiles(){

		for(int i = 0; i < missiles.size(); i ++){
			delete missiles[i];
		}
		missiles.clear();
		for(int i = 0; i < NUM_STARTUP_MISSILES; i++){
			Missile * m = new Missile();
			m->setSilo(this);
			missiles.push_back(m);
		}
	}


	Missile* launchMissile(){
		if (isAlive()){
			if(missiles.size()>0){
				Missile * m = missiles[0];
				missiles.erase(missiles.begin());
				return m;
			}
		}
		return NULL;
	}


	void setMissileSpeed(float speed){
		missileSpeed = speed;
	}

	
	float getMissileSpeed(){
		return missileSpeed;
	}


	bool canLaunchMissile(){
		return (missiles.size() > 0) && isAlive();
	}


	void draw(ofTrueTypeFont * font){

		if(isAlive()){
			Obj2D::draw();
			ofSetColor(255);
		}else{
			ofSetColor(0,128);
			tex->draw( x, y, width, height );
			ofSetColor(0,128);
		}
		ofSetColor(0);

		font->drawString( ofToString(missiles.size()),  x + ((missiles.size() > 9 ) ? -3 : 5) , y + 46);

	}

	
	float missileSpeed;
	vector<Missile*> missiles;
	
};


#endif
