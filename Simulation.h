#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include "Animator.h"
#include "Section.h"
#include "MiddleSection.h"
#include "Lane.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include <string>
#include <vector>

using namespace std;

class Simulation{
private:
    vector<Vehicle *> vehicleVector;    // a vector that stores all the vehicles in the simulation
    int seed;                           // the random seed

    int simTime;                       // Maximum simulation time
    int sectionsBeforeIntersection;    // Number of tiles before intersection for each road
    int greenNS;                       // Time that the north-south light is green
    int yellowNS;                      // Time that the north-south light is yellow
    int greenEW;                       // Time that the east-west light is green
    int yellowEW;                      // Time that the east-west light is yellow
    double probNewVehicleN;            // Probability a new vehicle is generated northbound
    double probNewVehicleS;            // Probability a new vehicle is generated southbound
    double probNewVehicleE;            // Probability a new vehicle is generated eastbound
    double probNewVehicleW;            // Probability a new vehicle is generated westbound
    double proportionCars;             // Proportion of generated vehicles that are cars
    double proportionSUVs;             // Proportion of generated vehicles that are SUV
    double proportionTrucks;           // Proportion of generated vehicles that are trucks
    double probRightCars;              // Probability a car turns right
    double probRightSUVs;              // Probability a SUV turns right
    double probRightTrucks;            // Probability a truck turns right
    double probLeftCars;               // Probability a car turns left
    double probLeftSUVs;               // Probability a SUV turns left
    double probLeftTrucks;             // Probability a truck turns left

    // this method creates a vehicle
    void createVehicle(Lane *lane, double laneProb, double createProb,
        double vehicleProb, double turnProb);
    void step();

public:
    // constructors
    Simulation(){}
    Simulation(string file, int seed);
    ~Simulation();

    // method which runs the simulation
    void runSim();
};
#endif
