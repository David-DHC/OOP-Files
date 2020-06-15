#include <bits/stdc++.h>
#include "Shape.h"

using namespace std;

Shape::Shape()
{
	a = 0;
	b = 0;
	c = 0;
}

float Shape::getArea()
{
	cout << "You are an idiot" << endl;
	return 2.33;
}

Rectangle::Rectangle(int a0, int b0)
{
	a = a0;
	b = b0;
}

float Rectangle::getArea()
{
	return (a * b);
}

Circle::Circle(int c0)
{
	c = c0;
}

float Circle::getArea()
{
	return 3.14 * (c * c);
}