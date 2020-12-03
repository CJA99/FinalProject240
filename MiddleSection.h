#ifndef __MIDDLESECTION_H__
#define __MIDDLESECTION_H__

#include "Section.h"

/**
 * MiddleSection class is a subclass of Section.
 * It adds functionality to connect Sections in all 4 directions
*/
class MiddleSection : public Section{
private:
    Section *north;     // the section to the north of the MiddleSection
    Section *east;      // the section to the east of the MiddleSection
    Section *west;      // the section to the west of the MiddleSection
    Section *south;     // the section to the south of the MiddleSection

public:
    MiddleSection();    // Default constructor
    ~MiddleSection(){}  // Destructor

    // Get methods
    Section *getNext() override;    // Get next section dependent on direction
    Section *getPrev() override;    // Get prev section dependent on direction
    Section *getRight();            // Get right section for this middle section

    inline Section *getNorth(){ return north; }     // returns the north Section
    inline Section *getEast(){ return east; }       // returns the east Section
    inline Section *getSouth(){ return south; }     // returns the south Section
    inline Section *getWest(){ return west; }       // returns the west Section

    // Set methods
    inline void setNorth(Section *north){ this->north = north; }    // sets the north Section using *north
    inline void setEast(Section *east){ this->east = east; }        // sets the east Section using *east
    inline void setSouth(Section *south){ this->south = south; }    // sets the south Section using *south
    inline void setWest(Section *west){ this->west = west; }        // sets the west Section using *west
};

#endif
