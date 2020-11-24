#ifndef __SECTION_H__
#define __SECTION_H__

#include <string>
#include "VehicleBase.h"

class Section{
private:
    Section *next;      // Next Section
    Section *prev;      // Previous Section

    VehicleBase *vehicle = nullptr;     // Pointer to a Vehicle occupying this Section
    bool empty;                         // Section is empty

protected:
    bool toBeDeleted = true;            // Sections should be deleted, middle sections not

public:
    Section();
    virtual ~Section(){}

    // Get methods
    virtual inline Section *getNext(){ return next; }   // get next Section
    virtual inline Section *getPrev(){ return prev; }   // get previous Section
    virtual inline bool shouldDelete(){ return toBeDeleted; }

    inline bool isEmpty(){ return empty; }              // Section is empty
    inline VehicleBase *getVehicle(){ return vehicle; } // Get VehicleBase on this Section

    // Set methods
    inline void setNext(Section *section){ next = section; }    // Set the next Section
    inline void setPrev(Section *section){ prev = section; }    // Set the previous Section

    void setEmpty();                    // No more vehicle on this Section
    void setVehicle(VehicleBase *);     // Put a vehicle on this Section
};

#endif
