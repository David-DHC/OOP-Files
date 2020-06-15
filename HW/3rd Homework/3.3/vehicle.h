#pragma once

#include "wheel.h"
#include "engine.h"

using namespace std;

class Vehicle
{
public:
	Engine e;
	Wheel w;

	Vehicle(int num, string engine);
	void describe();
};