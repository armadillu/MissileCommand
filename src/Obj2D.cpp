//
//  Obj2D.cpp
//  emptyExample
//
//  Created by Oriol Ferrer Mesià on 22/04/13.
//
//

#include "Obj2D.h"


void Obj2D::setup(ofImage * img ){

	tex = img;
	if (img){
		width = img->width;
		height = img->height;
	}
}



void Obj2D::update(float dt){
	x += speed.x * dt;
	y += speed.y * dt;
}


bool Obj2D::hitTest( ofVec2f p){
	return inside(p);
}


bool Obj2D::hitTest( ofRectangle r ){
	return inside(r);
}

bool Obj2D::hitTestCircle(ofVec2f center, float radius){

	bool t0 = inside(center);
	if (t0) return true;
	bool t1 = center.distance( getTopLeft() ) < radius;
	if (t1) return true;
	bool t2 = center.distance( getTopRight() ) < radius;
	if (t2) return true;
	bool t3 = center.distance( getBottomLeft() ) < radius;
	if (t3) return true;
	bool t4 = center.distance( getBottomRight() ) < radius;
	if (t4) return true;
	return false;
}


void Obj2D::draw(){
	ofSetColor(color);
	if(tex){
		tex->draw( x, y, width, height );
	}else{
		ofRect( x, y, width, height );
	}

}
