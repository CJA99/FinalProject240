#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "MiddleSection.h"
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
    if(!(start->getNext()->isEmpty()) || (start->getNext() == nullptr))
        return;
    if(start->getNext()->isMiddle() && !(start->isMiddle())){
        LightColor trafficColor = lane->getTrafficLight()->getColor();
        if(trafficColor == LightColor::red){
            return;
        }
        else if(trafficColor == LightColor::yellow){
            int timeTilChange = lane->getTrafficLight()->changeTime();
            if(turningRight && (timeTilChange < length + 1))
                return;
            if(!turningRight && (timeTilChange < length + 2))
                return;
        }
    }
    if(start->getNext()->isMiddle() && start->isMiddle() && turningRight){
        turnRight();
        return;
    }
        moveForward();

    if(start->getNext() == nullptr){
        atTheEnd = true;
        Section *sec = start;
        while(sec != end){
            sec->setEmpty();
            sec = sec->getPrev();
        }
        end->setEmpty();
    }
}

void Vehicle::moveForward(){
    start = start->getNext();
    start->setVehicle(this);
    end = end->getNext();
    end->getPrev()->setEmpty();
}

void Vehicle::turnRight(){
    MiddleSection *ms = dynamic_cast<MiddleSection *>(start);
    start = ms->getRight();
    start->setVehicle(this);
    end->setEmpty();
    end = end->getNext();
    if(getVehicleOriginalDirection() == Direction::east)
        changeDirection(Direction::south);
    else if(getVehicleOriginalDirection() == Direction::north)
        changeDirection(Direction::east);
    else if(getVehicleOriginalDirection() == Direction::west)
        changeDirection(Direction::north);
    else if(getVehicleOriginalDirection() == Direction::south)
        changeDirection(Direction::west);
}
#endif
