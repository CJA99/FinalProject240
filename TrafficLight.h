#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include <string>
using namespace std;

class trafficLight{
protected:
	int G;
	int Y;
	int R;
	string color; 

public:
	int countDown;

	trafficLight();
	trafficLight(int gLight, int yLight, int rLight, string c);

	~trafficLight();
	
	void setColor(string c);
	string getColor();
	
};

#endif	
