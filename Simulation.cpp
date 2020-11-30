#ifndef __Simulation_CPP__
#define __Simulation_CPP__

#include "Simulation.h"
#include <random>
#include <fstream>
#include <iostream>

using namespace std;

Simulation::Simulation(string file, int seed){
	this->seed = seed;
    ifstream infile;
    infile.open(file);

    if(!infile){
        cerr << "Error: could not open file: " << file << endl;
	}

	int count{};
	string name;
	string value;

	while (infile.good()){
		count++;
		infile >> name >> value;

		if(count == 1)
			simTime	 = stoi(value);
		else if(count == 2)
			sectionsBeforeIntersection = stoi(value);
		else if(count == 3)
			greenNS = stoi(value);
		else if(count == 4)
			yellowNS = stoi(value);
		else if(count == 5)
			greenEW = stoi(value);
		else if(count == 6)
			yellowEW = stoi(value);
		else if(count == 7)
			probNewVehicleN = stod(value);
		else if(count == 8)
			probNewVehicleS = stod(value);
		else if(count == 9)
			probNewVehicleE = stod(value);
		else if(count == 10)
			probNewVehicleW = stod(value);
		else if(count == 11)
			proportionCars = stod(value);
		else if(count == 12)
			proportionSUVs = stod(value);
		else if(count == 13)
			probRightCars = stod(value);
		else if(count == 14)
			probLeftCars = stod(value);
		else if(count == 15)
			probRightSUVs = stod(value);
		else if(count == 16)
			probLeftSUVs = stod(value);
		else if(count == 17)
			probRightTrucks = stod(value);
		else if(count == 18)
			probLeftTrucks = stod(value);
	}
	infile.close();
	proportionTrucks = 1 - proportionCars - proportionSUVs;
}

Simulation::~Simulation(){
	for (size_t i = 0; i < vehicleVector.size(); i++)
      delete vehicleVector[i];
	vehicleVector.clear();
}

void Simulation::runSim(){
	char dummy;

	Animator anim(sectionsBeforeIntersection);

    MiddleSection ms1;
    MiddleSection ms2;
    MiddleSection ms3;
    MiddleSection ms4;

	TrafficLight trafficLightNS(greenNS, yellowNS, greenEW + yellowEW, LightColor::green);
    TrafficLight trafficLightEW(greenEW, yellowEW, greenNS + yellowNS, LightColor::red);

    Lane northbound(Direction::north, sectionsBeforeIntersection, &ms1, &ms2, &trafficLightNS);
    Lane southbound(Direction::south, sectionsBeforeIntersection, &ms3, &ms4, &trafficLightNS);
    Lane eastbound(Direction::east, sectionsBeforeIntersection, &ms4, &ms1, &trafficLightEW);
    Lane westbound(Direction::west, sectionsBeforeIntersection, &ms2, &ms3, &trafficLightEW);

	anim.setVehiclesNorthbound(northbound.getLaneVector());
    anim.setVehiclesWestbound(westbound.getLaneVector());
    anim.setVehiclesSouthbound(southbound.getLaneVector());
    anim.setVehiclesEastbound(eastbound.getLaneVector());

    std::mt19937 mt;
    std::uniform_real_distribution<double> rand_double(0,1);
    mt.seed(seed);

	for (int i = 0; i < simTime; i++){
		createVehicle(&northbound, probNewVehicleN, rand_double(mt), rand_double(mt), rand_double(mt));
		createVehicle(&westbound, probNewVehicleW, rand_double(mt), rand_double(mt), rand_double(mt));
		createVehicle(&southbound, probNewVehicleS, rand_double(mt), rand_double(mt), rand_double(mt));
		createVehicle(&eastbound, probNewVehicleE, rand_double(mt), rand_double(mt), rand_double(mt));

		anim.setLightNorthSouth(trafficLightNS.getColor());
        anim.setLightEastWest(trafficLightEW.getColor());

		anim.setVehiclesNorthbound(northbound.getLaneVector());
        anim.setVehiclesWestbound(westbound.getLaneVector());
        anim.setVehiclesSouthbound(southbound.getLaneVector());
        anim.setVehiclesEastbound(eastbound.getLaneVector());

		anim.draw(i);
        std::cin.get(dummy);

		step();
		trafficLightNS.decrement();
        trafficLightEW.decrement();
	}
}

void Simulation::createVehicle(Lane *lane, double laneProb, double createProb,
	double vehicleProb, double turnProb){
		std::cout << lane->canCreate() << std::endl;
		if(!lane->canCreate())
			std::cout << "Buffer is empty?: " << lane->getBuffer()->getVehicle()->vehicleID << std::endl;
	if((lane->canCreate()) && (createProb <= laneProb)){
		if(vehicleProb <= proportionCars){
			Vehicle *car;
			if(turnProb <= probRightCars){
				car = new Vehicle(lane, VehicleType::car, true);
				vehicleVector.push_back(car);
			}
			else{
				car = new Vehicle(lane, VehicleType::car, false);
				vehicleVector.push_back(car);
			}
		}
		else if(vehicleProb <= proportionCars + proportionSUVs){
			Vehicle *suv;
			if(turnProb <= probRightSUVs){
				suv = new Vehicle(lane, VehicleType::suv, true);
				vehicleVector.push_back(suv);
			}
			else{
				suv = new Vehicle(lane, VehicleType::suv, false);
				vehicleVector.push_back(suv);
			}
		}
		else{
			Vehicle *truck;
			if(turnProb <= probRightCars){
				truck = new Vehicle(lane, VehicleType::truck, true);
				vehicleVector.push_back(truck);
			}
			else{
				truck = new Vehicle(lane, VehicleType::truck, false);
				vehicleVector.push_back(truck);
			}
		}
	}
}

void Simulation::step(){
	vector<int> indices;
	for (size_t i = 0; i < vehicleVector.size(); i++){
        if (vehicleVector[i]->reachedEnd())
			indices.push_back(i);
    }
	for(size_t i = 0; i < indices.size(); i++){
		int index = indices[i] - i;
		// Create a pointer to a vehicle because deletes vector's memory otherwise
        Vehicle* vehiclePtr = vehicleVector[index];
        vehicleVector.erase(vehicleVector.begin() + index);
        delete vehiclePtr;
	}
	for (size_t i = 0; i < vehicleVector.size(); i++){
		vehicleVector[i]->move();
	}

}

#endif
