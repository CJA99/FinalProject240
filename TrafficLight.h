#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include <string>
#include "VehicleBase.h"
using namespace std;

class TrafficLight{
private:
    int green;
    int yellow;
    int red;
    LightColor color;
    int countDown;

public:

    TrafficLight();
    TrafficLight(int gLight, int yLight, int rLight, LightColor color);
    ~TrafficLight(){}

    inline LightColor getColor(){ return color; }
    inline int changeTime(){ return countDown; }
    void decrement();
};

#endif
