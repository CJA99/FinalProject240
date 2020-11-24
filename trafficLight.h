#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

class trafficLight{
protected:
	int G;
	int Y;
	int R;

public:
	int countDown;

	trafficLight();
	~trafficLight();
