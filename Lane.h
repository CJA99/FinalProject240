#ifndef __LANE_H__
#define __LANE_H__

#include "MiddleSection.h"
#include "Section.h"
#include "TrafficLight.h"
#include "VehicleBase.h"
#include <vector>
using namespace std;

/**
 * Lane class consists of linked sections and middle sections.
 * It stores the information about traffic light and vehicles,
 * used to spawn vehicles and provide them to the animator.
 * It has 4 invisible sections of buffer needed to spawn vehicles and keep them in
 * the system even if a part of a vehicle lefts the visible part
*/
class Lane{
private:
    vector<Section *> lane;     // Vector of all sections making a lane
    int length;                 // Length of a lane
    Direction direction;        // Direction of a lane
    Section *buffer;            // First section of a buffer, where vehicle spawns
    TrafficLight *trafficLight; // The TrafficLight corresponding to the lane

    // Helper method to link sections
    Section *linkSections(int numOfSections, Section *lastSection);

public:
    // Default constructor
    Lane(){};
    // Typical use contructor
    Lane(Direction direction, int halfSize, MiddleSection *middleSection1,
        MiddleSection *middleSection2, TrafficLight *light);
    // Destructor
    ~Lane();

    vector<VehicleBase*> getLaneVector();                          // Returns a vector of VehicleBase pointers for Animator
    inline Section *getBuffer(){ return buffer; }                  // Returns a pointer to the first section of a buffer
    inline Direction getDirection(){ return direction; }           // Returns the direction of this lane
    inline TrafficLight *getTrafficLight(){ return trafficLight; } // Returns a pointer to the lane TrafficLight
    bool canCreate();                                              // Returns whether there it is possible to create a new Vehicle
};

#endif
