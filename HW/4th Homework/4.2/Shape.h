#pragma once

#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
	int a, b, c;
	Shape();
	virtual float getArea();
};

class Rectangle: public Shape
{
public:
	Rectangle(int a0, int b0);
	float getArea();
};

class Circle: public Shape
{
public:
	Circle(int c);
	float getArea();
};