#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include <string>
#include "VehicleBase.h"
using namespace std;

class TrafficLight{
private:
    int green;          // length of a green light
    int yellow;         // length of a yellow light
    int red;            // length of a red light
    LightColor color;   // the color of the light
    int countDown;      // the time left on the light 

public:

    // constructors
    TrafficLight();
    TrafficLight(int gLight, int yLight, int rLight, LightColor color);
    ~TrafficLight(){}

    
    inline LightColor getColor(){ return color; }   // returns the color of the light
    inline int changeTime(){ return countDown; }    // returns the amount of time before the light changes
    void decrement();                               // counts down the time left on the light
};

#endif
