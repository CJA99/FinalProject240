#ifndef __SECTION_H__
#define __SECTION_H__

#include <string>
#include "VehicleBase.h"

/**
 * Section is a node class needed to construct a lane.
 * It has pointers to next and precious sections and a pointer to a vehicle
 * standing on it.
*/
class Section{
private:
    Section *next;      // Next Section
    Section *prev;      // Previous Section

    VehicleBase *vehicle = nullptr;     // Pointer to a Vehicle occupying this Section
    bool empty;                         // Section is empty

protected:
    bool middle = false;    // Sections should be deleted, middle sections not

public:
    // Constructor
    Section();
    virtual ~Section(){}

    // Get methods
    virtual inline Section *getNext(){ return next; }   // get next Section
    virtual inline Section *getPrev(){ return prev; }   // get previous Section
    virtual inline bool isMiddle(){ return middle; }    // returns true if the section is a MiddleSection

    inline bool isEmpty(){ return empty; }              // Section is empty
    inline VehicleBase *getVehicle(){ return vehicle; } // Get VehicleBase on this Section

    // Set methods
    inline void setNext(Section *section){ next = section; }    // Set the next Section
    inline void setPrev(Section *section){ prev = section; }    // Set the previous Section

    void setEmpty();                    // No more vehicle on this Section
    void setVehicle(VehicleBase *);     // Put a vehicle on this Section
};

#endif
