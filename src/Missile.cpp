//
//  Missile.cpp
//  opencvExample
//
//  Created by Oriol Ferrer Mesià on 24/04/13.
//
//

#include "Missile.h"
#include "Silo.h"

void Missile::startGood( ofVec2f target_ ){
	origin = pos = silo->getCenter();
	target = target_;
	color = GOOD_MISSILE_COLOR;
	bad = FALSE;
	pos = origin;
	speed = target - pos;

	speed =  speed.normalized() * silo->getMissileSpeed();
	explosionTimeLine = 0;
}
