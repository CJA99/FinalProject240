#include "Probability.h"
#include "Lane.h"
#include "Vehicle.h"
#include "TrafficLight.h"
#include <random>

int main(int argc, char* argv[]){
    std::mt19937 randomNumberGenerator; 
    std::uniform_real_distribution<double> rand_double(0,1);

    randomNumberGenerator.seed(238);

    return 0;
}
