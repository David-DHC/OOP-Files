#include "wheel.h"
#include "engine.h"
#include "vehicle.h"
#include <bits/stdc++.h>

using namespace std;

Vehicle::Vehicle(int num, string engine) : 	e(engine), w(num) {};

void Vehicle::describe()
{
	cout << "Finish building a vehicle with "
	     << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
	cout << "A vehicle with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
	return;
}