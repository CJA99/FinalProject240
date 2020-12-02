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
    if(!(start->getNext()->isEmpty()))
        return;
    if(start->getNext()->isMiddle() && !(start->isMiddle())){
        std::cout << "1" << std::endl;
        if(lane->getTrafficLight()->getColor() == LightColor::red){
            std::cout << "2" << std::endl;
            return;
        }
        if(lane->getTrafficLight()->getColor() == LightColor::yellow && !(lane->getTrafficLight()->changeTime() >= length + 2)){
            std::cout << "3" << std::endl;
            return;
        }
    }
    else if(start->getNext()->isMiddle() && start->isMiddle() && turningRight){
        std::cout << "4" << std::endl;
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
    end = end->getNext();
    end->getPrev()->setEmpty();
    if(getVehicleOriginalDirection() == Direction::east)
        changeDirection(Direction::south);
    if(getVehicleOriginalDirection() == Direction::north)
        changeDirection(Direction::east);
    if(getVehicleOriginalDirection() == Direction::west)
        changeDirection(Direction::north);
    if(getVehicleOriginalDirection() == Direction::south)
        changeDirection(Direction::west);
}
#endif