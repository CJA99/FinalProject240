#ifndef __MIDDLESECTION_CPP__
#define __MIDDLESECTION_CPP__

#include "MiddleSection.h"
using namespace std;

// Default constructor
MiddleSection::MiddleSection():Section(){ toBeDeleted = false; }


// Get next section dependent on direction
Section *MiddleSection::getNext(){
    Direction direction = getVehicle()->getVehicleOriginalDirection();
    if(direction == Direction::north)
        return north;
    else if(direction == Direction::east)
        return east;
    else if(direction == Direction::west)
        return west;
    else if(direction == Direction::south)
        return south;
    else
        Section::getNext();
    return nullptr;
}

// Get prev section dependent on direction
Section *MiddleSection::getPrev(){
    if(getVehicle() == nullptr)
        return Section::getPrev();

    Direction direction = getVehicle()->getVehicleOriginalDirection();
    if(direction == Direction::north)
        return south;
    else if(direction == Direction::east)
        return west;
    else if(direction == Direction::west)
        return east;
    else if(direction == Direction::south)
        return north;
    return nullptr;
}

// Get right section dependent on direction
Section *MiddleSection::getRight(){
    Direction direction = getVehicle()->getVehicleOriginalDirection();
    if(direction == Direction::north)
        return east;
    else if(direction == Direction::east)
        return south;
    else if(direction == Direction::west)
        return north;
    else if(direction == Direction::south)
        return west;
    return nullptr;
}

#endif
