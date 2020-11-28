#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include <string>
#include <vector>
#include "Animator.h"

using namespace std;

class Simulation{
    protected:
	Vector<Vehicle> vVector;
	string filename;

    public:
	Simuation();
	Simulation(string file);
	~Simulation();

	void runSim();
}
