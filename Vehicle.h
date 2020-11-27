#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "VehicleBase.h"
#include "Lane.h"

class Vehicle : public VehicleBase{
private:
    int length;
    Lane lane;
    bool atTheEnd;

public:
    Vehicle(Lane spawnLane, VehicleType type);
    ~Vehicle();

    void move();
    void spawn();
    inline bool reachedEnd(){ return atTheEnd; }
};
#endif