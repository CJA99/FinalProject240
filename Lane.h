#ifndef __LANE_H__
#define __LANE_H__

#include "MiddleSection.h"
#include "Section.h"
#include "TrafficLight.h"
#include "VehicleBase.h"
#include <vector>
using namespace std;

class Lane{
private:
    vector<Section *> lane; // Vector of all sections making a lane
    int length;             // Length of a lane
    Direction direction;    // Direction of a lane
    Section *buffer;        // First section of a buffer where, vehicle spawns
    TrafficLight *trafficLight;

public:
    // Constructor
    Lane(){};
    Lane(Direction direction, int halfSize, MiddleSection *middleSection1,
        MiddleSection *middleSection2, TrafficLight *light);
    // Destructor
    ~Lane();

    // Get methods
    vector<VehicleBase*> getLaneVector();          // Returns a vector of VehicleBase
    inline Section *getBuffer(){ return buffer; }   // Returns the first section of a buffer
    inline Direction getDirection(){ return direction; } // Returns the direction associated with the Lane
    bool canCreate();                                    // Returns whether there it is possible to create a new Vehicle
    inline TrafficLight *getTrafficLight(){ return trafficLight; }
};

#endif