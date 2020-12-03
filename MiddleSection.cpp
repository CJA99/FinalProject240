#ifndef __MIDDLESECTION_CPP__
#define __MIDDLESECTION_CPP__

#include "MiddleSection.h"
#include "Vehicle.h"
using namespace std;

// Default constructor
MiddleSection::MiddleSection():Section(){ middle = true; }


/* Get next section dependent on direction 
 *
 * @return returns the next section in the Lane
 */
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

/* Get prev section dependent on direction 
 *
 * @return returns the previous section in the Lane
 */
Section *MiddleSection::getPrev(){
    if(getVehicle() == nullptr)
        return Section::getPrev();

    Vehicle *veh = dynamic_cast<Vehicle *>(getVehicle());
    Direction direction = veh->getVehicleOriginalDirection();
    if(veh->willTurn()){
        if(direction == Direction::north)
            return east;
        else if(direction == Direction::east)
            return south;
        else if(direction == Direction::west)
            return north;
        else if(direction == Direction::south)
            return west;
    }
    else{
        if(direction == Direction::north)
            return south;
        else if(direction == Direction::east)
            return west;
        else if(direction == Direction::west)
            return east;
        else if(direction == Direction::south)
            return north;
    }
    return nullptr;

}

/* Get right section dependent on direction 
 *
 * @return returns the section to the right of the MiddleSection for right turns
 */
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
