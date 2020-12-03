#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "MiddleSection.h"
#include "Vehicle.h"
#include <iostream>

/**
 * Typical use constructor
 * @param spawnLane - pointer to a lane where to spawn a vehicle
 * @param vehicleType - type of a vehicle
 * @param willTurn - true if a vehicle will turn right
 */
Vehicle::Vehicle(Lane *spawnLane, VehicleType type, bool willTurn) : VehicleBase(type, spawnLane->getDirection()){
    // Member initialization
    lane = spawnLane;
    turningRight = willTurn;
    if(type == VehicleType::car)
        length = 2;
    else if(type == VehicleType::suv)
        length = 3;
    else
        length = 4;

    // Spawn vehicle's head and tail on the buffer section of a lane
    start = lane->getBuffer();
    start->setVehicle(this);
    end = start;

    // Move tail on length distance
    for(int i = 0; i < length - 1; i++){
        end = end->getPrev();
        end->setVehicle(this);
    }
}

/**
 * Move vehicle exactly one section forward or to the right
 */
void Vehicle::move(){
    // If the next section is not empty or null
    if(!(start->getNext()->isEmpty()) || (start->getNext() == nullptr))
        return;
    // If a vehicle is on the intersection
    else if(start->getNext()->isMiddle() && !(start->isMiddle())){
        LightColor trafficColor = lane->getTrafficLight()->getColor();
        // Stop if the color is red
        if(trafficColor == LightColor::red){
            return;
        }
        // Stop if the color is yellow and a vehicle has no time to proceed
        else if(trafficColor == LightColor::yellow){
            int timeTilChange = lane->getTrafficLight()->changeTime();
            // It takes less time to turn right than go straight
            if(turningRight && (timeTilChange < length + 1))
                return;
            if(!turningRight && (timeTilChange < length + 2))
                return;
        }
    }
    // Turn right if the head is already at the intersection
    else if(start->getNext()->isMiddle() && start->isMiddle() && turningRight){
        turnRight();
        return;
    }
    // In any other case proceed straight
    moveForward();

    // If next section is null, vehicle has reached the end
    if(start->getNext() == nullptr){
        atTheEnd = true;
        Section *sec = start;
        // Empty the sections where was a vehicle
        while(sec != end){
            sec->setEmpty();
            sec = sec->getPrev();
        }
        end->setEmpty();
    }
}

/**
 * Helper method used by move()
 * Move vehicle exactly one section forward
 */
void Vehicle::moveForward(){
    start = start->getNext();
    start->setVehicle(this);
    end = end->getNext();
    end->getPrev()->setEmpty();
}

/**
 * Helper method used by move()
 * When a vehicle is on the intersection turn right
 */
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
