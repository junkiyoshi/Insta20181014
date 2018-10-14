#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle();
	~Particle();
	void Upate();
	void Draw();

private:

	float radius;
	float deg;
	ofPoint direction;

	std::deque<ofPoint> logs;
};