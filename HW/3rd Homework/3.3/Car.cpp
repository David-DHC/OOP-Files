#include "wheel.h"
#include "engine.h"
#include "vehicle.h"
#include "car.h"
#include <bits/stdc++.h>

using namespace std;

Car::Car(int num, string engine): Vehicle(num, engine) {};

void Car::describe()
{
	cout << "Finish building a car with "
	     << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
	cout << "A car with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
	return;
}

// g++ main.cpp wheel.cpp engine.cpp Motor.cpp Car.cpp Vehicle.cpp -o main -std=c++14