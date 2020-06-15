#pragma once
#include <bits/stdc++.h>
using namespace std;

class MyQueriable
{
public:
	vector<float> vec;

	int size()
	{
		return vec.size();
	}

	float operator[](int i)
	{
		return this->vec[i];
	}

	float sum()
	{
		float T;
		for (float i : vec)
		{
			T += i;
		}

		return T;
	}

	MyQueriable where(function<bool(float)> op1)
	{
		MyQueriable tmp;
		for (float i : this->vec)
		{
			if (op1(i))
				tmp.vec.push_back(i);
		}
		return tmp;
	}

	MyQueriable apply(function<float(float)> op2)
	{
		MyQueriable tmp;
		for (float i : this->vec)
		{
			tmp.vec.push_back(op2(i));
		}
		return tmp;
	}
};

template <class T>
MyQueriable from (vector<T> a)
{
	MyQueriable tmp;
	for (T i : a)
	{
		tmp.vec.push_back(i);
	}
	return tmp;
}

template <class T>
MyQueriable from (list<T> a)
{
	MyQueriable tmp;
	for (T i : a)
	{
		tmp.vec.push_back(i);
	}
	return tmp;
}