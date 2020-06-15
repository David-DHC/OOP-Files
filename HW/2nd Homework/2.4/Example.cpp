#include <iostream>
#include "Example.h"

using namespace std;

extern int now = 0;
extern Example* e6;

Example::Example(int data)
{
	now ++;
	number = now;
	context = data;
	cout << "Example #" << number << " is created" << endl;
}

void Example::getData()
{
	cout << "The data of Example #" << number << " is " << context << endl;
}

Example::~Example() {
	cout << "Example #" << number << " is destroyed" << endl;
	if (number == 2)
		cout << "Example #" << 6 << " is destroyed" << endl;
}