#ifndef __Section_CPP__
#define __Section_CPP__

#include "Section.h"
using namespace std;

// Default constructor
Section::Section(){
    empty = true;
    setNext(nullptr);
    setPrev(nullptr);
}

// removes a vehicle from a Section
void Section::setEmpty(){
    empty = true;
    this->vehicle = nullptr;
}

// Sets a vehicle to be placed in a particular section
void Section::setVehicle(VehicleBase *vehicle){
    empty = false;
    this->vehicle = vehicle;
}

#endif
