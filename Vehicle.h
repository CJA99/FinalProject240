#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "VehicleBase.h"
#include "Lane.h"
#include "Section.h"

/**
 * Vehicle class is a subclass of VehicleBase.
 * It implements a vehicle movement on a lane.
*/
class Vehicle : public VehicleBase{
private:

    Lane *lane;             // Pointer to the lane on which a vehicle spawns
    Section *start;         // Pointer to the section with the head of a vehicle
    Section *end;           // Pointer to the section with the tail of a vehicle
    int length;             // Length of the vehicle
    bool atTheEnd = false;  // True if a vehicle reached the end of a lane
    bool turningRight;      // True if a vehicle will turn right on the intersection

    // Helper methods to move a vehicle
    void moveForward();
    void turnRight();

public:
    // Constructor
    Vehicle(Lane *spawnLane, VehicleType type, bool willTurn);
    // Destructor
    ~Vehicle(){}

    void move();                                   // Move a vehicle one section forward
    inline bool reachedEnd(){ return atTheEnd; }   // True if a vehicle reached the end of a lane
    inline bool willTurn(){ return turningRight; } // True if a vehicle will turn right on the intersection
};
#endif
