#ifndef __TrafficLight_CPP__
#define __TrafficLight_CPP__

#include <string>
#include "TrafficLight.h"

using namespace std;

// Default constructor
TrafficLight::TrafficLight(){
	G = 0;
	Y = 0;
	R = 0;
	countDown = 0;
	color = "";
}

TrafficLight::TrafficLight(int gLight, int yLight, int rLight, string c){
	G = gLight;
	Y = yLight;
	R = rLight;
	countDown = yLight;
	color = c;
}

TrafficLight::~TrafficLight(){};

void TrafficLight::setColor(string c){
	color = c;
}

string TrafficLight::getColor(){
	return color;
}

#endif		
