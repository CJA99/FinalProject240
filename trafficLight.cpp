#ifndef __trafficLight_CPP__
#define __trafficLight_CPP__

#include <string>
#include "trafficLight.h"

using namespace std;

// Default constructor
trafficLight::trafficLight(){
	G = 0;
	Y = 0;
	R = 0;
	countDown = 0;
}

trafficLight::trafficLight(int gLight, int yLight, int rLight){
	G = gLight;
	Y = yLight;
	R = rLight;
	countDown = yLight;
}

void trafficLight::setColor(string c){
	color = c;
}
	
#endif		
