#pragma once

#include "Node.h"

using namespace std;

class Array
{
public:

	int length;
	Node *arr;

	Node&& operator[] (int i)
	{
		return move(arr[i]);
	}

	Array (int n);
	~Array();

	void update(int q, int r);

	void swap(int q, int r);

	void insert(int q, int r);


};