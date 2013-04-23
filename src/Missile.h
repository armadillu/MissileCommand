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

class Missile{
public:
	
	Missile(){
		exploded = false;
		countDown = ofRandom(LEVEL_TIME * 0.7);
	}

	ofVec2f bestSiloForShot(ofVec2f target){
		
		ofVec2f p1 = SILO_LEFT;
		ofVec2f p2 = SILO_MID;
		ofVec2f p3 = SILO_RIGHT;
		float d1 = p1.distance(target);
		float d2 = p2.distance(target);
		float d3 = p3.distance(target);
		if (d1 > d2){
			if (d2 > d3){
				return p3;
			}else{
				return p2;
			}
		}else{
			if (d1 > d3){
				return p3;
			}else{
				return p1;
			}
		}
	}

	void startBad(){
		color = ofColor(200,0,0);
		bad = TRUE;
		pos.x = origin.x = ofRandom(0, ofGetWidth());
		pos.y = origin.y = -2;
		speed = ofVec2f(ofGetWidth()*0.5, ofGetHeight()) - pos;
		speed = speed.normalize() * BAD_MISSILE_SPEED;
		speed.rotate( ofRandom(-30, 30));
		explosionTimeLine = 0;
	}


	void startGood(ofVec2f target_){
		target = target_;
		color = ofColor(50,50,200);
		bad = FALSE;
		ofVec2f silo = bestSiloForShot(target);
		pos = origin = silo;
		speed = target - pos;
		speed = speed.normalize() * GOOD_MISSILE_SPEED;
		explosionTimeLine = 0;
	}

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
					if (pos.distance(target) < 5){
						exploded = true;
					}
				}
			}else{
				
				explosionTimeLine+=dt;
			}
		}else{
			countDown -= dt;
		}

	}

	void draw(){
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
			}
		}
	}

	bool dead(){
		return exploded && (explosionTimeLine > EXPLOSION_DURATION);
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
};


#endif
