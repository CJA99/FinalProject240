#ifndef __LANE_CPP__
#define __LANE_CPP__

#include "Lane.h"

// Default constructor creates a lane by linking sections
Lane::Lane(Direction direction, int halfSize, MiddleSection *middleSection1,
    MiddleSection *middleSection2, TrafficLight light){
    trafficLight = light;
    length = 2 + halfSize * 2;
    this->direction = direction;
    Section *lastSection = nullptr;

    // Link first half of sections
    for (int i = 0; i < halfSize + 4; i++){
        Section *section = new Section();

    // First section of the buffer
        if (i == 3)
            buffer = section;

        if (lastSection != nullptr){
            section->setPrev(lastSection);
            lastSection->setNext(section);
        }

        lastSection = section;
        lane.push_back(section);
    }

    // Add middle sections to the vector of all sections
    lane.push_back(middleSection1);

    // Link first middle section
    lastSection->setNext(middleSection1);
    middleSection1->setPrev(lastSection);

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
    for (int i = 0; i < halfSize + 3; i++){
        Section *section = new Section();

        if (lastSection != nullptr){
            section->setPrev(lastSection);
            lastSection->setNext(section);
        }

        lastSection = section;
        lane.push_back(section);
    }
}

// Destructor deallocates every section except middle ones
Lane::~Lane(){
    for (size_t i = 0; i < lane.size(); i++){
        if (lane[i]->shouldDelete())
            delete this->lane[i];
    }
    lane.clear();
}

// Get a vector of VehicleBase for the Animator class
vector<VehicleBase *> Lane::getLaneVector(){
    vector<VehicleBase *> laneVector(length, nullptr);

    for (int i = 0; i < length; i++){
        if (!lane[i + 4]->isEmpty())
            laneVector[i] = lane[i + 4]->getVehicle();
    }
    return laneVector;
}

// If the buffer is empty return true
bool Lane::canCreate(){
    for (size_t i = 0; i < 4; i++){
        if (lane[i]->isEmpty())
            return false;
    }
    return true;
}

#endif