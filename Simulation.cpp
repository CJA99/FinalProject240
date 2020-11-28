#ifndef __Simulation_CPP__
#define __Simulation_CPP__

#include "Probability.h"
#include "Animator.h"
#include "Lane.h"
#include "Vehicle.h"
#include "TrafficLight.h"
#include <random>
#include "VehicleBase.h"
#include "Simulation.h"
#include <random>
#include <string>
#include <vector>

Simulation::Simulation(){
    filename = "";
    //vVector<Vehicle>;

}

Simulation::Simulation(string file){
    filename = file;
    //vVector<Vehicle>;
}

Simulation::runSim(int seed){
    Probability::readInputTextFile(filename);

    int halfsize = Probability::getHalfsize();

    MiddleSection ms1;
    MiddleSection ms2;
    MiddleSection ms3;
    MiddleSection ms4;

    TrafficLight NS{Probability::getGreenNorthSouth(), Probability::getYellowNorthSouth(), (Probility::getGreenEastWest() + Probability::getYellowEastWest()), "Green"};
    TrafficLight EW{Probability::getGreenEastWest(), Probability::getYellowEastWest(), (Probility::getGreenNorthSouth() + Probability::getYellowNothSouth()), "Red"};

    Animator anim(halfsize);

    Lane northbound(Direction::north, halfSize, &ms1, &ms2, NS);
    Lane southbound(Direction::south, halfSize, &ms3, &ms4, EW);
    Lane eastbound(Direction::east, halfSize, &ms4, &ms1, EW);
    Lane westbound(Direction::west, halfSize, &ms2, &ms3, NS);

    std::mt19937 randomNumberGenerator;
    std::uniform_real_distribution<double> rand_double(0,1);

    randomNumberGenerator.seed(seed);

    for (i = 0; i < Probability::getMaximumSimulatedTime(); i++){
	double randNum = rand_double(randomNumberGenerator);

	if (randNum < Probability::getProportionOfCars()){
	    VehicleBase type{car};
	}
	else if (randNum < (Probability::getProportionOfSuvs() + Probability::getProportionOfCars()){
	    VehicleBase type{suv};
	}
	else {
	    VehicleBase type{truck};
	}

        double randNum1 = rand_double(randomNumberGenerator);

	if (randNum1 < Probability::getProbNewVehicleNorthbound()){
	    &Lane lane{&northbound};
	}
	else if (randNum1 < (Probability::getProbNewVehicleNorthbound() + Probability::getProbNewVehicleSouthbound())){
	    &Lane lane(&southbound};
	}
	else if (randNum1 < (Probability::getProbNewVehicleNorthbound() + Probability::getProbNewVehicleSouthbound() + Probability::getProbNewVehicleEastbound())){
	    &Lane lane(&eastbound);
	}
	else if (randNum1 < (Probability::getProbNewVehicleNorthbound() + Probability::getProbNewVehicleSouthbound() + Probability::getProbNewVehicleEastbound() + Probability::getProbNewVehicleWestbound())){
            &Lane lane(&westbound);
	}
	else{
	    continue;
	}

	double randNum2 = rand_double(randomNumberGenerator);

    switch(type){

        case VehicleType::car:
        ///////
            if(randNum2 < Probability::getProportionRightTurnCars()){
        	bool RTurn = true;
            }
	    else{
        	bool Rturn = false;
            }
    	case VehicleType::suvs:
    	///////
    	    if(randNum2 < Probability::getProportionRightTurnSuvs()){
      		bool RTurn = true;
	    }
	    else{
      		bool Rturn = false;
    	    }
    	//////
    	case VehicleType::trucks:
    	    if(randNum2 < Probability::getProportionRightTurnTrucks()){
      		bool RTurn = true;
	    }
	    else{
      		bool Rturn = false;
    	    }
    }
}

#endif
