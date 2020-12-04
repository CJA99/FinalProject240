# FinalProject240

to compile the program use the Makefile provided by typing make in the command prompt.
to execute sim: Usage: ./sim [input file] [initial seed]

Design Decisions:
Every Lane is made by linking sections together including four MiddleSections which are connected to each other. There are four invisible buffer sections on both sides so we can keep track of vehicels when they are leaving the lane. When a Vehicle is spawned it is placed in the correct lane and lane returns a vector of Vehiclebase pointers for the animator.
A Vehicle is a subclasss of Vehiclebase which handles the movement. Vehicle accesses TrafficLight through the lane which it is spawned in.
Simulation is a class that includes all the classes and runs and animates the simulation. It reads the input file in the constructor. It creates instances of all needed classes and has a clock to step through the simulation. Simulation uses the std::mt19937 c++ random number generator to handle the probability of vehicle creation it also handles the deletion of all vehicles when they exit their lane. 
