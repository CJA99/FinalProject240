#ifndef __Simulation_CPP__
#define __Simulation_CPP__

#include "Probability.h"
#include "Lane.h"
#include "Vehicle.h"
#include "TrafficLight.h"
#include <random>
#include <string>

Simulation::Simulation(){
    filename = "";
}

Simulation::Simulation(string file){
    filename = file;
}

Simulation::runSim(){
    


