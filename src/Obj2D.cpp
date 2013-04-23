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


bool Obj2D::hit( ofVec2f p){
	return inside(p);
}


bool Obj2D::hit( ofRectangle r ){
	return inside(r);
}


void Obj2D::draw(){
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(color);
	if(tex){
		tex->draw( x, y, width, height );
	}else{
		ofRect( x, y, width, height );
	}
	ofSetRectMode(OF_RECTMODE_CORNER);
}
