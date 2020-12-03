#ifndef __LANE_CPP__
#define __LANE_CPP__

#include "Lane.h"

/**
 * Helper method to link sections
 * @param numOfSections number of sections to be connected
 * @param lastSection a pointer to the last section to connect to
 * @return a pointer to the last section
*/
Section* Lane::linkSections(int numOfSections, Section *lastSection){
    for (int i = 0; i < numOfSections; i++){
        Section *section = new Section();
        section->setPrev(lastSection);
        lastSection->setNext(section);
        lastSection = section;
        lane.push_back(section);
    }
    return lastSection;
}


/**
 * Typical use constructor creates a lane by linking sections
 * @param direction the direction which traffic flows on the lane
 * @param halfSize the amount of sections before the intersection
 * @param middleSection1 a pointer to the first middlesection
 * @param middleSection2 a pointer to the second middleSection
 * @param light a pointer to the trafficLight associated with the lane
*/
Lane::Lane(Direction direction, int halfSize, MiddleSection *middleSection1,
    MiddleSection *middleSection2, TrafficLight *light){
    // Member initialization
    trafficLight = light;
    length = 2 + halfSize * 2;      // 2 middleSections and sections on both sides
    this->direction = direction;

    // Link 4 sections of a buffer
    Section *lastSection = nullptr;
    for (int i = 0; i < 4; i++){
        Section *section = new Section();

        // Set the buffer section, where vehicles will spawn
        if (i == 3)
            buffer = section;

        if (lastSection != nullptr){
            section->setPrev(lastSection);
            lastSection->setNext(section);
        }
        lastSection = section;
        lane.push_back(section);
    }

    // Link first half of sections before the intersections
    lastSection = linkSections(halfSize, lastSection);

    // Add middle sections to the vector of all sections
    lane.push_back(middleSection1);

    // Link first middle section
    lastSection->setNext(middleSection1);
    middleSection1->setPrev(lastSection);

    // Create a section right after the intersection
    Section *startOfSecondHalf = new Section();

    // Link North East West South for middle sections based on the direction
    if(direction == Direction::north){
        middleSection1->setSouth(lastSection);
        middleSection1->setNorth(middleSection2);
        middleSection2->setSouth(middleSection1);
        middleSection2->setNorth(startOfSecondHalf);
    }else if(direction == Direction::east){
        middleSection1->setWest(lastSection);
        middleSection1->setEast(middleSection2);
        middleSection2->setWest(middleSection1);
        middleSection2->setEast(startOfSecondHalf);
    }else if(direction == Direction::west){
        middleSection1->setEast(lastSection);
        middleSection1->setWest(middleSection2);
        middleSection2->setEast(middleSection1);
        middleSection2->setWest(startOfSecondHalf);
    }else if(direction == Direction::south){
        middleSection1->setNorth(lastSection);
        middleSection1->setSouth(middleSection2);
        middleSection2->setNorth(middleSection1);
        middleSection2->setSouth(startOfSecondHalf);
    }

    // Link middlesection2 and startofSecondHalf
    lane.push_back(middleSection2);
    lane.push_back(startOfSecondHalf);
    startOfSecondHalf->setPrev(middleSection2);
    lastSection = startOfSecondHalf;

    // Link the second half and the end buffer
    linkSections(halfSize + 4, lastSection);
}

// Destructor deallocates every section except middle ones
Lane::~Lane(){
    for (size_t i = 0; i < lane.size(); i++){
        if (!lane[i]->isMiddle())
            delete this->lane[i];
    }
    lane.clear();
}

/**
 * Get a vector of VehicleBase references for the Animator class
 * @return the vector containing all Vehicles in the lane
 */
vector<VehicleBase *> Lane::getLaneVector(){
    vector<VehicleBase *> laneVector(length, nullptr);

    // Take buffer sections into account
    for (int i = 0; i < length; i++){
        if (!lane[i + 4]->isEmpty())
            laneVector[i] = lane[i + 4]->getVehicle();
    }
    return laneVector;
}

/**
 * If the buffer is empty return true
 * @return returns a bool to state whether it is possible to create a vehicle
 */
bool Lane::canCreate(){
    for (size_t i = 0; i < 4; i++){
        if (!lane[i]->isEmpty())
            return false;
    }
    return true;
}

#endif
