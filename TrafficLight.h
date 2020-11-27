#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include <string>
using namespace std;

class TrafficLight{
protected:
	int G;
	int Y;
	int R;
	string color; 

public:
	int countDown;

	TrafficLight();
	TrafficLight(int gLight, int yLight, int rLight, string c);

	~TrafficLight();
	
	void setColor(string c);
	string getColor();
	
};

#endif	
