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

// No more vehicle on this Section
void Section::setEmpty(){
    empty = true;
    this->vehicle = nullptr;
}

// Makes a section occupied with a vehicle on it
void Section::setVehicle(VehicleBase *vehicle){
    empty = false;
    this->vehicle = vehicle;
}

#endif
