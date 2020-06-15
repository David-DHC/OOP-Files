#include "wheel.h"
#include "engine.h"
#include "vehicle.h"
#include "motor.h"
#include <bits/stdc++.h>

using namespace std;

Motor::Motor(int num, string engine): Vehicle(num, engine) {};

void Motor::describe()
{
	cout << "Finish building a motor with "
	     << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
	cout << "A motor with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
	return;
}

void Motor::sell()
{
	cout << "A motor is sold!" << endl;
	return;
}