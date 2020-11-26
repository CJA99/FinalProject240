#ifndef __PROBABILITY_H__
#define __PROBABILITY_H__

#include <iostream>

using namespace std;

class Probability{
  public:
    int static       getMaximulationTime();
    int static       getNumberOfSectionsBeforeIntersection();
    int static       getGreenNorthSouth();
    int static       getYellowNorthSouth();
    int static       getGreenEastWest();
    int static       getYellowEastWest();
    double static    getProbNewVehicleNorthbound();
    double static    getProbNewVehicleSouthbound();
    double static    getProbNewVehicleEastbound();
    double static    getProbNewVehicleWestbound();
    double static    getProportionOfCars();
    double static    getProportionOfSuvs();
    double static    getProportionOftrucks();
    double static    getProportionRightTurnCars();
    double static    getProportionLeftTurnCars();
    double static    getProportionRightTurnSuvs();
    double static    getProportionLeftTurnSuvs();
    double static    getProportionRightTurnTrucks();
    double static    getProportionLeftTurnTrucks();

    void readInputTextFile(std::string filename);

  private:
    int static       maximum_simulated_time;
    int static       number_of_sections_before_intersection;
    int static       green_north_south;
    int static       yellow_north_south;
    int static       green_east_west;
    int static       yellow_east_west;
    double static    prob_new_vehicle_northbound;
    double static    prob_new_vehicle_southbound;
    double static    prob_new_vehicle_eastbound;
    double static    prob_new_vehicle_westbound;
    double static    proportion_of_cars;
    double static    proportion_of_suvs;
    double static    proportion_of_trucks;
    double static    proportion_right_turn_cars;
    double static    proportion_left_turn_cars;
    double static    proportion_right_turn_suvs;
    double static    proportion_left_turn_suvs;
    double static    proportion_right_turn_trucks;
    double static    proportion_left_turn_trucks;

};
#endif
