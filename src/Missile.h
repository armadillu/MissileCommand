//
//  Missile.h
//  opencvExample
//
//  Created by Oriol Ferrer Mesià on 22/04/13.
//
//

#ifndef opencvExample_Missile_h
#define opencvExample_Missile_h

#include "Constants.h"
#include "ofMain.h"
#include "City.h"
//#include "Silo.h"

class Silo;

class Missile{
public:
	
	Missile(){
		exploded = false;
		countDown = ofRandom(LEVEL_TIME * 0.7);
	}

	void setSilo(Silo* silo_){silo = silo_;}

	void startBad(){
		color = BAD_MISSILE_COLOR;
		bad = TRUE;
		pos.x = origin.x = ofRandom(0, ofGetWidth());
		pos.y = origin.y = -2;
		speed = ofVec2f(ofGetWidth()*0.5, ofGetHeight()) - pos;
		speed = speed.normalized() * BAD_MISSILE_SPEED;
		speed.rotate( ofRandom(-30, 30));
		explosionTimeLine = 0;
	}


	void startGood( ofVec2f target_ );

	
	void update(float dt){
		if ( countDown < 0 || bad == FALSE){
			if (!exploded){
				currentExplosionRadius = 0;
				pos = pos + speed * dt;
				if (bad){
					if (pos.y >= ofGetHeight()-60){ //explode
						exploded = true;
					}
				}else{
					if (pos.distance(target) <  0.5 * speed.length() * dt ){
						exploded = true;
						pos = target;
					}
				}
			}else{
				
				explosionTimeLine+=dt;
			}
		}else{
			countDown -= dt;
		}
	}
	
	void explode(){
		exploded = true;
	}

	void draw(){
		glLineWidth(2);
		if(countDown < 0 || bad == FALSE){
			ofSetColor(color);
			ofLine(origin, pos);
			ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
			ofCircle(pos, 1);
			if (exploded){
				float time = 1 - fabs(-1 + 2 * explosionTimeLine / EXPLOSION_DURATION) ; // http://www.wolframalpha.com/input/?i=y+%3D+1+-+abs%28-1+%2B+2x+%29
				currentExplosionRadius = EXPLOSION_RADIUS * time;
				if (currentExplosionRadius > 0) ofCircle(pos, currentExplosionRadius);
				//printf("%f\n", time);
			}else{
				int len = 6;

				ofLine( target.x - len, target.y + len, target.x + len, target.y - len);
				ofLine( target.x + len, target.y + len, target.x - len, target.y - len);
			}
		}
	}

	bool dead(){
		return exploded && (explosionTimeLine > EXPLOSION_DURATION);
	}

	float explosionRadius(){
		return currentExplosionRadius;
	}

	ofVec2f origin;
	ofVec2f speed;
	ofVec2f pos;
	ofVec2f target;
	ofColor color;
	bool exploded;
	float countDown;
	float explosionTimeLine; //[0..EXPLOSION_DURATION]
	bool bad;
	float currentExplosionRadius;

	Silo* silo;
};


#endif
