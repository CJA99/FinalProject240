#ifndef __Section_CPP__
#define __Section_CPP__

#include "Section.h"
using namespace std;

/**
 * Default constructor
*/
Section::Section(){
    empty = true;
    setNext(nullptr);
    setPrev(nullptr);
}

/**
 * Remove a vehicle from this section
*/
void Section::setEmpty(){
    empty = true;
    this->vehicle = nullptr;
}

/**
 * Place a vehicle on this section
*/
void Section::setVehicle(VehicleBase *vehicle){
    empty = false;
    this->vehicle = vehicle;
}

#endif
