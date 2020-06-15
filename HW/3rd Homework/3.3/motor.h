#pragma once

#include "wheel.h"
#include "engine.h"
#include "vehicle.h"

using namespace std;

class Motor: public Vehicle
{
public:

	using Vehicle::Vehicle;
	Motor(int num, string engine);

	void describe();
	void sell();
};