#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(Lane *spawnLane, VehicleType type, bool willTurn) : VehicleBase(type, spawnLane->getDirection()){
    lane = spawnLane;
    turningRight = willTurn;
    if(type == VehicleType::car)
        length = 2;
    else if(type == VehicleType::suv)
        length = 3;
    else
        length = 4;

    start = lane->getBuffer();
    start->setVehicle(this);
    end = start;

    for(int i = 0; i < length - 1; i++){
        end = end->getPrev();
        end->setVehicle(this);
    }
}

void Vehicle::move(){
    if((!start->getNext()->isEmpty()))
        return;
    if ((start->getNext()->isMiddle() && lane->getTrafficLight()->getColor() == LightColor::red))
        return;
    moveForward();

    if(start->getNext() == nullptr){
        atTheEnd = true;
    }
}

void Vehicle::moveForward(){
    start = start->getNext();
    start->setVehicle(this);
    end = end->getNext();
    end->getPrev()->setEmpty();
}

void Vehicle::turnRight(){

}
#endif