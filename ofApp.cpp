#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetColor(239);

	for (int i = 0; i < 80 * 4; i++) { this->particles.push_back(Particle()); }
}
//--------------------------------------------------------------
void ofApp::update() {

	for (Particle& particle : particles) { particle.Upate(); }
}

//--------------------------------------------------------------
void ofApp::draw() {

	vector<ofPoint> locations;
	locations.push_back(ofPoint(-350, -350));
	locations.push_back(ofPoint(-350, 350));
	locations.push_back(ofPoint(350, -350));
	locations.push_back(ofPoint(350, 350));

	this->cam.begin();

	int count = 0;
	for (Particle& particle : particles){
		
		ofPushMatrix();
		ofTranslate(locations[count++ / 80]);

		particle.Draw();

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}