#pragma once
#include <bits/stdc++.h>
using namespace std;

class Student
{
public:

	string name;
	int p = 0;
	int a = 0;

	Student(string tush);
	string getName();

	int getAbsentTimes();

	int getPresentTimes();
};