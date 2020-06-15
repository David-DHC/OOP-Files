#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

Student::Student(string tush)
{
	name = tush;
}

string Student::getName()// tushut
{
	return name;
}

int Student::getAbsentTimes()
{
	return a;
}

int Student::getPresentTimes()
{
	return p;
}