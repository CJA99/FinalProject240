#ifndef __VEHICLE_BASE_CPP__
#define __VEHICLE_BASE_CPP__

#include "Probability.h"
#include <iostream>
#include <fstream>

int Probability::maximum_simulated_time;
int Probability::number_of_sections_before_intersection;
int Probability::green_north_south;
int Probability::yellow_north_south;
int Probability::green_east_west;
int Probability::yellow_east_west;
double Probability::prob_new_vehicle_northbound;
double Probability::prob_new_vehicle_southbound;
double Probability::prob_new_vehicle_eastbound;
double Probability::prob_new_vehicle_westbound;
double Probability::proportion_of_cars;
double Probability::proportion_of_suvs;
double Probability::proportion_of_trucks;
double Probability::proportion_right_turn_cars;
double Probability::proportion_left_turn_cars;
double Probability::proportion_right_turn_suvs;
double Probability::proportion_left_turn_suvs;
double Probability::proportion_right_turn_trucks;
double Probability::proportion_left_turn_trucks;

int Probability::getMaximulationTime(){
  return maximum_simulated_time;
}
int Probability::getNumberOfSectionsBeforeIntersection(){
  return number_of_sections_before_intersection;
}
int Probability::getGreenNorthSouth(){
  return green_north_south;
}
int Probability::getYellowNorthSouth(){
  return yellow_north_south;
}
int Probability::getGreenEastWest(){
  return green_east_west;
}
int Probability::getYellowEastWest(){
  return yellow_east_west;
}
double Probability::getProbNewVehicleNorthbound(){
  return prob_new_vehicle_northbound;
}
double Probability::getProbNewVehicleSouthbound(){
  return prob_new_vehicle_southbound;
}
double Probability::getProbNewVehicleEastbound(){
  return prob_new_vehicle_eastbound;
}
double Probability::getProbNewVehicleWestbound(){
  return prob_new_vehicle_westbound;
}
double Probability::getProportionOfCars(){
  return proportion_of_cars;
}
double Probability::getProportionOfSuvs(){
  return proportion_of_suvs;
}
double Probability::getProportionOftrucks(){
  return proportion_of_trucks;
}
double Probability::getProportionRightTurnCars(){
  return proportion_right_turn_cars;
}
double Probability::getProportionLeftTurnCars(){
  return proportion_left_turn_cars;
}
double Probability::getProportionRightTurnSuvs(){
  return proportion_right_turn_suvs;
}
double Probability::getProportionLeftTurnSuvs(){
  return proportion_left_turn_suvs;
}
double Probability::getProportionRightTurnTrucks(){
  return proportion_right_turn_trucks;
}
double Probability::getProportionLeftTurnTrucks(){
  return proportion_left_turn_trucks;
}

void Probability::readInputTextFile(std::string filename){
  //open text file
  ifstream inputFile(filename);

  if(!inputFile.is_open()){
    cout<<"file could not open"<< endl;
    exit(1);
  }

  string name;
  string value;

  inputFile >> name >> value;
  maximum_simulated_time = stoi(value);
  //Test below...
  // std::cout << "name: "<< name << '\n';
  // std::cout << "value: " << value << '\n';
  // std::cout << "maximum_simulated_time: "<< maximum_simulated_time << '\n';
  inputFile >> name >> value;
  maximum_simulated_time = stoi(value);
  inputFile >> name >> value;
  number_of_sections_before_intersection = stoi(value);
  inputFile >> name >> value;
  green_north_south = stoi(value);
  inputFile >> name >> value;
  yellow_north_south = stoi(value);
  inputFile >> name >> value;
  green_east_west = stoi(value);
  inputFile >> name >> value;
  yellow_east_west = stoi(value);
  inputFile >> name >> value;
  prob_new_vehicle_northbound = stod(value);
  inputFile >> name >> value;
  prob_new_vehicle_southbound = stod(value);
  inputFile >> name >> value;
  prob_new_vehicle_eastbound = stod(value);
  inputFile >> name >> value;
  prob_new_vehicle_westbound = stod(value);
  inputFile >> name >> value;
  proportion_of_cars = stod(value);
  inputFile >> name >> value;
  proportion_of_suvs = stod(value);
  inputFile >> name >> value;
  proportion_of_trucks = stod(value);
  inputFile >> name >> value;
  proportion_right_turn_cars = stod(value);
  inputFile >> name >> value;
  proportion_left_turn_cars = stod(value);
  inputFile >> name >> value;
  proportion_right_turn_suvs = stod(value);
  inputFile >> name >> value;
  proportion_left_turn_suvs = stod(value);
  inputFile >> name >> value;
  proportion_right_turn_trucks = stod(value);
  inputFile >> name >> value;
  proportion_left_turn_trucks = stod(value);
  inputFile.close();


}
#endif
