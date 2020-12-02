#include <iostream>
#include "Animator.h"
#include "VehicleBase.h"
#include "Section.h"
#include "MiddleSection.h"
#include "Lane.h"
#include "TrafficLight.h"
#include "Vehicle.h"
#include "Simulation.h"

int main(int argc, char* argv[])
{
    // int seed = 8675309;
    // std::cout << argv[1] << std::endl;
    // Simulation sim(argv[1], seed);
    // sim.runSim();

    int halfSize = 4;
    Animator anim(halfSize);
    vector<VehicleBase *> vehicles;

    MiddleSection ms1;
    MiddleSection ms2;
    MiddleSection ms3;
    MiddleSection ms4;

    char dummy;

    //anim.setLightNorthSouth(LightColor::red);
    //anim.setLightEastWest(LightColor::green);

    TrafficLight lightNS{5, 2, 7, LightColor::red};
    TrafficLight lightEW{5, 2, 7, LightColor::green};

    Lane northbound(Direction::north, halfSize, &ms1, &ms2, &lightNS);
    Lane southbound(Direction::south, halfSize, &ms3, &ms4, &lightNS);
    Lane eastbound(Direction::east, halfSize, &ms4, &ms1, &lightEW);
    Lane westbound(Direction::west, halfSize, &ms2, &ms3, &lightEW);

    //anim.setLightNorthSouth(LightColor::green);
    //anim.setLightEastWest(LightColor::red);

    anim.setVehiclesNorthbound(northbound.getLaneVector());
    anim.setVehiclesWestbound(westbound.getLaneVector());
    anim.setVehiclesSouthbound(southbound.getLaneVector());
    anim.setVehiclesEastbound(eastbound.getLaneVector());

    Vehicle *car1 = new Vehicle(&westbound, VehicleType::car, true);
    Vehicle car2(&southbound, VehicleType::car, false);

    for (size_t i = 0; i < 1000; i++){

        anim.setLightNorthSouth(lightNS.getColor());
        anim.setLightEastWest(lightEW.getColor());


        anim.setVehiclesNorthbound(northbound.getLaneVector());
        anim.setVehiclesWestbound(westbound.getLaneVector());
        anim.setVehiclesSouthbound(southbound.getLaneVector());
        anim.setVehiclesEastbound(eastbound.getLaneVector());

        anim.draw(i);
        std::cin.get(dummy);

        if(car1->reachedEnd()){
            delete car1;
        }else
            car1->move();
        //car2.move();
        lightNS.decrement();
        lightEW.decrement();
    }

    // // Vehicle suv1(&southbound, VehicleType::car, false);

    // // for (size_t i = 0; i < 200; i++){

    // //     anim.setLightNorthSouth(lightNS.getColor());
    // //     anim.setLightEastWest(lightEW.getColor());


    // //     anim.setVehiclesNorthbound(northbound.getLaneVector());
    // //     anim.setVehiclesWestbound(westbound.getLaneVector());
    // //     anim.setVehiclesSouthbound(southbound.getLaneVector());
    // //     anim.setVehiclesEastbound(eastbound.getLaneVector());

    // //     anim.draw(i);
    // //     std::cin.get(dummy);

    // //     suv1.move();
    // //     lightNS.decrement();
    // //     lightEW.decrement();
    // // }
}
