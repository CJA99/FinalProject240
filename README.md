# CMSC240 Traffic Simulation Project
Authors: Nat Asmelash, Nikita Morozov, Deborah Maidoh, Carter Angelus

## Direction for compiling:
To compile the program use the Makefile provided, type: make
To execute the simulation: ./sim [input file] [initial seed]

## Design Decisions:
### Lane
Every Lane is made by linking Sections together including four MiddleSections, like nodes
in a doubly linked list. There are four invisible buffer sections on both sides, so we can
spawn Vehicles there and see Vehicles when they are leaving the lane. When a Vehicle
is spawned, it is placed in the correct buffer section of a lane. A lane goes over the
vector of every section in it and returns a vector of Vehiclebase pointers for the animator.

### Vehicle
A Vehicle is a subclass of Vehiclebase, which handles the movement. A Vehicle accesses
a TrafficLight through the lane which it is spawned in.

### Simulation
Simulation is a class that includes all the classes; it runs and animates the simulation.
It reads the input file in the constructor. It creates instances of all needed classes
and has an integer clock to step through the simulation in runSim() method.
Simulation uses the std::mt19937 C++ random number generator to handle the probability
of Vehicle creation. With every iteration it asks Vehicles to move and also handles the
deletion of all Vehicles when they exit their lane.
