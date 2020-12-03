#include <iostream>
#include <fstream>
#include "Animator.h"
#include "VehicleBase.h"
#include "Section.h"
#include "MiddleSection.h"
#include "Lane.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include "Simulation.h"

int main(int argc, char* argv[]) {

    if(argc < 3){
        cerr << "Usage: ./sim [input file] [initial seed]" << endl;
        exit(1);
    }

    ifstream infile(argv[1]);
    if (!infile){
        cerr << "Error: could not open file: " << argv[1] << endl;
        exit(1);
    }

    int seed;
    try{
        seed = stoi(argv[2]);
    }catch(exception& e){
        cerr << "Invalid integer for the initial seed: " << argv[2] << endl;
        exit(1);
    }

    // Rin simulation
    Simulation sim(argv[1], seed);
    sim.runSim();

    return 0;
}
