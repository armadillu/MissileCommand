//
//  City.h
//  opencvExample
//
//  Created by Oriol Ferrer Mesià on 24/04/13.
//
//

#ifndef opencvExample_City_h
#define opencvExample_City_h

#include "ofMain.h"
#include "Obj2D.h"

class City : public Obj2D{

public:

	City(){
		alive = true;
	}

	void kill(){ alive = false;}
	void revive(){ alive = true;}
	bool isDead(){return !alive;}
	bool isAlive(){return alive;}

	void draw(){
		if(alive){
			Obj2D::draw();
		}else{
			ofSetColor(0,255);
			tex->draw( x, y, width, height );
		}
	}
private:

	bool alive;


};

#endif
