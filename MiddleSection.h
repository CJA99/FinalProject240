#ifndef __MIDDLESECTION_H__
#define __MIDDLESECTION_H__

#include "Section.h"

class MiddleSection : public Section{
private:
    Section *north;
    Section *east;
    Section *west;
    Section *south;

public:
    MiddleSection();                              // Default constructor
    MiddleSection(const MiddleSection &other);    // Copy constructor
    ~MiddleSection(){}                            // Destructor

    // Get methods
    Section *getNext() override;    // Get next section dependent on direction
    Section *getPrev() override;    // Get prev section dependent on direction
    Section *getRight();            // Get right section for this middle section

    inline Section *getNorth(){ return north; }
    inline Section *getEast(){ return east; }
    inline Section *getSouth(){ return south; }
    inline Section *getWest(){ return west; }

    // Set methods
    inline void setNorth(Section *north){ this->north = north; }
    inline void setEast(Section *east){ this->east = east; }
    inline void setSouth(Section *south){ this->south = south; }
    inline void setWest(Section *west){ this->west = west; }
};

#endif
