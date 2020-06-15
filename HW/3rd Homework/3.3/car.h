#pragma once

#include "wheel.h"
#include "engine.h"
#include "vehicle.h"

using namespace std;

class Car: public Vehicle
{
public:

	using Vehicle::Vehicle;
	Car(int num, string engine);

	void describe();
};