#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "VehicleBase.h"
#include "Lane.h"
#include "Section.h"

class Vehicle : public VehicleBase{
private:
    Lane *lane;
    bool atTheEnd;

    Section *start;
    Section *end;
    int length;

    bool turningRight;

public:
    Vehicle(Lane *spawnLane, VehicleType type, bool willTurn);
    ~Vehicle(){}

    void move();
    inline bool reachedEnd(){ return atTheEnd; }
};
#endif