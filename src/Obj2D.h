//
//  Obj2D.h
//  emptyExample
//
//  Created by Oriol Ferrer Mesià on 22/04/13.
//
//

#ifndef __emptyExample__Obj2D__
#define __emptyExample__Obj2D__

#include <iostream>

#include "ofMain.h"

class Obj2D : public ofRectangle{

public:

	void setup( ofImage * img = NULL);
	void update(float dt);
	void draw();
	void setSize();
	bool hitTest(ofVec2f);
	bool hitTest(ofRectangle);

	bool hitTestCircle(ofVec2f center, float radius);

	ofColor color;
	ofVec2f speed;
	ofImage * tex;

};
#endif /* defined(__emptyExample__Obj2D__) */
