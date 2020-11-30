#ifndef __TrafficLight_CPP__
#define __TrafficLight_CPP__

#include <string>
#include "TrafficLight.h"

using namespace std;

// Default constructor
TrafficLight::TrafficLight(){
	green = 0;
	yellow = 0;
	red = 0;
	countDown = 0;
	color = LightColor::red;
}

TrafficLight::TrafficLight(int gLight, int yLight, int rLight, LightColor color){
	green = gLight;
	yellow = yLight;
	red = rLight;
	this->color = color;
	if(color == LightColor::green)
		countDown = green;
	else if(color == LightColor::yellow)
		countDown = yellow;
	else
		countDown = red;
}

void TrafficLight::decrement(){
	countDown--;
	if(countDown == 0){
		if (color == LightColor::green){
      		color = LightColor::yellow;
      		countDown = yellow;
    	}
		else if (color == LightColor::yellow){
      		color = LightColor::red;
      		countDown = red;
    	}
		else{
      		color = LightColor::green;
      		countDown = green;
    	}
	}
}


#endif
