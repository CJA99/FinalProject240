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
    //std::cout << this->vehicleID << std::endl;
    if((!start->getNext()->isEmpty()))
        return;
    if(start->getNext()->isMiddle() && !(start->isMiddle())){
        if (lane->getTrafficLight()->getColor() == LightColor::red)
            return;
        if (lane->getTrafficLight()->getColor() == LightColor::yellow && !(lane->getTrafficLight()->changeTime() >= length + 2)){
            return;
        }
    }
    moveForward();

    if(start->getNext() == nullptr){
        atTheEnd = true;
        //std::cout << vehicleID << " is at the end"<< std::endl;
        Section *sec = start;
        while(sec != end){
            sec->setEmpty();
            sec = sec->getPrev();
        }
        end->setEmpty();
        //std::cout << vehicleID << " nice " << reachedEnd() << std::endl;
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