#include "Particle.h"

//--------------------------------------------------------------
Particle::Particle() {

	this->radius = (int)(ofRandom(160, 300) / 20) * 20;
	this->deg = (int)(ofRandom(360) / 10) * 10;
}

//--------------------------------------------------------------
Particle::~Particle() {

}

//--------------------------------------------------------------
void Particle::Upate() {

	if (ofGetFrameNum() % 20 == 0) {

		ofPoint directions[4];
		directions[0] = ofPoint(1, 0);
		directions[1] = ofPoint(-1, 0);
		directions[2] = ofPoint(0, 2);
		directions[3] = ofPoint(0, -2);

		if (this->radius <= 160) {

			directions[3] = directions[2];
		}
		else if (this->radius >= 300) {

			directions[2] = directions[3];
		}

		this->direction = directions[(int)ofRandom(4)];
	}

	this->deg += this->direction.x;
	this->radius += this->direction.y;

	ofPoint point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
	this->logs.push_front(point);
	while (this->logs.size() > 45) { this->logs.pop_back(); }
}

//--------------------------------------------------------------
void Particle::Draw() {

	ofFill();
	ofDrawCircle(this->logs.front(), 5);

	ofNoFill();
	ofBeginShape();
	for (ofPoint& log : this->logs) {

		ofVertex(log);
	}
	ofEndShape();
}