#include "testApp.h"


void testApp::setup(){

	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);
	ofEnableAlphaBlending();

	city.loadImage("city.png");
	bg.loadImage("bg.png");

	int numCities = NUM_CITIES;
	for(int i = 0; i < numCities; i++){
		Obj2D o;
		o.setup(&city);
		o.color = ofColor(30,30,100);
		o.position.y = ofGetHeight() - city.height;
		o.position.x = ofGetWidth() * 0.15 + ofGetWidth() * 0.7 * i / (numCities - 1);
		cities.push_back(o);
	}

	///////////

	remoteCam.initGrabber(640,480);
	remoteCam.start();
	remoteCam.setRequestedImageType(OF_IMAGE_GRAYSCALE);
	remoteCam.setRequestedCompressionQuality( 90 );//jpeg, [0..100]
	laser.setup(ofRectangle(0,0, ofGetWidth(), ofGetHeight()), this, 640, 480, OF_IMAGE_GRAYSCALE);

}


void testApp::update(){

	float dt = 1/60.;

	///////////////

	remoteCam.update();

	if(remoteCam.isFrameNew()){
		laser.update( remoteCam.getPixels() );
	}

	/////////////////



	switch (state) {

		case PLAYING:{

			for(int i = playerMissiles.size()-1; i >= 0 ; i--){
				playerMissiles[i]->update(dt);
				if (playerMissiles[i]->dead()){
					playerMissiles.erase(playerMissiles.begin() + i);
				}
			}
			for(int i = badMissiles.size() - 1; i >= 0; i--){
				badMissiles[i]->update(dt);
				if (badMissiles[i]->dead()){
					badMissiles.erase(badMissiles.begin() + i);
				}
			}

			vector<int> badMissilesToDelete;
			for(int j = 0; j < playerMissiles.size(); j++){
				for(int i = 0; i < badMissiles.size(); i++){
					if ( playerMissiles[j]->pos.distance(badMissiles[i]->pos) < playerMissiles[j]->currentExplosionRadius){
						if ( std::find(badMissilesToDelete.begin(), badMissilesToDelete.end(), i) == badMissilesToDelete.end() ){
							badMissilesToDelete.push_back(i);
						}
					}
				}
			}


			for(int i = 0; i < badMissilesToDelete.size() ; i++){
				delete badMissiles[ badMissilesToDelete[i] ];
				badMissiles.erase(badMissiles.begin() + badMissilesToDelete[i]);
			}

			}break;

		default:
			break;
	}
}




void testApp::draw(){

	
	ofSetColor(255);
	bg.draw(0, 0, ofGetWidth(), ofGetHeight());

	ofSetColor(255, 128);
	laser.draw();

	//ofViewport(0,0,320,240);

	if (state == PLAYING){
		for(int i = 0; i < cities.size(); i++){
			cities[i].draw();
		}
		for(int i = 0; i < badMissiles.size(); i++){
			badMissiles[i]->draw();
		}
		for(int i = 0; i < playerMissiles.size(); i++){
			playerMissiles[i]->draw();
		}
	}

	//ofDrawBitmapString( ofToString(ofGetWidth()), 30,30);
	
	for(int i = 0; i < cities.size(); i++){
		cities[i].draw();
	}

}


void testApp::startLevel(){
	state = PLAYING;
	levelTime = LEVEL_TIME;
	playerMissiles.clear();
	badMissiles.clear();
	for(int i = 0; i <NUM_BAD_MISSILES; i++){
		Missile *m = new Missile();
		m->startBad();
		badMissiles.push_back(m);
	}	
}


void testApp::exit(){
	remoteCam.close();
}



void testApp::keyPressed(int key){

	startLevel();
}


void testApp::keyReleased(int key){

}


void testApp::mouseMoved(int x, int y){

}
void testApp::mouseDragged(int x, int y, int button){

}


void testApp::mousePressed(int x, int y, int button){

}


void testApp::mouseReleased(int x, int y, int button){

	Missile *m = new Missile();
	m->startGood( ofVec2f(x,y) );
	playerMissiles.push_back(m);

}




void testApp::windowResized(int w, int h){

}


void testApp::gotMessage(ofMessage msg){

}


void testApp::dragEvent(ofDragInfo dragInfo){ 

}