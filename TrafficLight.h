#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include <string>
#include "VehicleBase.h"
using namespace std;

/**
 * TrafficLight class controls lane traffic.
*/
class TrafficLight{
private:
    int green;
    int yellow;
    int red;
    LightColor color;
    int countDown;   // Time until change of the light

public:

    // Default constructor
    TrafficLight();
    // Typical use constructor
    TrafficLight(int gLight, int yLight, int rLight, LightColor color);
    // Destructor
    ~TrafficLight(){}

    inline LightColor getColor(){ return color; }   // Returns the current light color
    inline int changeTime(){ return countDown; }    // Returns time til change
    void decrement();                               // Decrement time
};

#endif
