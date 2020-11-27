#include <iostream>
#include "Animator.h"
#include "VehicleBase.h"
#include "Section.h"
#include "MiddleSection.h"
#include "Lane.h"
#include "TrafficLight.h"
#include "Vehicle.h"

int main()
{
    int halfSize = 4;
    Animator anim(halfSize);
    vector<VehicleBase *> vehicles;

    MiddleSection ms1;
    MiddleSection ms2;
    MiddleSection ms3;
    MiddleSection ms4;


    // std::vector<VehicleBase*> westbound(halfSize * 2 + 2, nullptr);
    // std::vector<VehicleBase*> eastbound(halfSize * 2 + 2, nullptr);
    // std::vector<VehicleBase*> southbound(halfSize * 2 + 2, nullptr);
    // std::vector<VehicleBase*> northbound(halfSize * 2 + 2, nullptr);

    //VehicleBase vb1(VehicleType::car, Direction::east);
    VehicleBase vb2(VehicleType::car, Direction::west);
    VehicleBase vb3(VehicleType::car, Direction::north);

    char dummy;

    //anim.setLightNorthSouth(LightColor::red);
    //anim.setLightEastWest(LightColor::green);

    TrafficLight NS{5, 5, 5, "Green"};
    TrafficLight EW{5, 5, 5, "Red"};

    Lane northbound(Direction::north, halfSize, &ms1, &ms2, NS);
    Lane southbound(Direction::south, halfSize, &ms3, &ms4, EW);
    Lane eastbound(Direction::east, halfSize, &ms4, &ms1, EW);
    Lane westbound(Direction::west, halfSize, &ms2, &ms3, NS);

    //anim.setLightNorthSouth(LightColor::green);
    //anim.setLightEastWest(LightColor::red);

    if (NS.getColor() == "Green"){
	anim.setLightNorthSouth(LightColor::green);
	anim.setLightEastWest(LightColor::red);
    }

    Vehicle car1(&westbound, VehicleType::car, false);
    // westbound.getBuffer()->setVehicle(&vb2);
    // westbound.getBuffer()->getNext()->setVehicle(&vb2);
    // westbound.getBuffer()->getNext()->getNext()->setVehicle(&vb2);

    //northbound.getBuffer()->setVehicle(&vb3);
    //northbound.getBuffer()->getNext()->setVehicle(&vb3);
    //northbound.getBuffer()->getNext()->getNext()->setVehicle(&vb3);
    //northbound.getBuffer()->getNext()->getNext()->getNext()->setVehicle(&vb3);
    //northbound.getBuffer()->getNext()->getNext()->getNext()->getNext()->setVehicle(&vb3);
    //northbound.getBuffer()->getNext()->getNext()->getNext()->getNext()->getNext()->setVehicle(&vb3);
    //northbound.getBuffer()->getNext()->getNext()->getNext()->getNext()->getNext()->getNext()->setVehicle(&vb3);
    //northbound[4] = northbound[5] = &vb3;

    anim.setVehiclesNorthbound(northbound.getLaneVector());
    anim.setVehiclesWestbound(westbound.getLaneVector());
    anim.setVehiclesSouthbound(southbound.getLaneVector());
    anim.setVehiclesEastbound(eastbound.getLaneVector());

    anim.draw(0);

    std::cin.get(dummy);

    // southbound.assign(halfSize * 2 + 2, nullptr); // reset vector
    // northbound.assign(halfSize * 2 + 2, nullptr); // reset
    // eastbound.assign(halfSize * 2 + 2, nullptr); // reset
    // westbound.assign(halfSize * 2 + 2, nullptr); // reset



    // southbound[6] = southbound[7] = &vb1;
    // westbound[1] = westbound[2] = &vb2;
    // //northbound[4] = northbound[5] = &vb3;

    // anim.setVehiclesNorthbound(northbound);
    // anim.setVehiclesWestbound(westbound);
    // anim.setVehiclesSouthbound(southbound);
    // anim.setVehiclesEastbound(eastbound);

    // anim.draw(1);

    // std::cin.get(dummy);

    // //southbound.assign(halfSize * 2 + 2, nullptr); // reset vector
    // //northbound.assign(halfSize * 2 + 2, nullptr); // reset
    // eastbound.assign(halfSize * 2 + 2, nullptr); // reset
    // westbound.assign(halfSize * 2 + 2, nullptr); // reset
}
