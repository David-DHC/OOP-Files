#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H

#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

bool cmp(string a, string b);

bool cmp1(Student a, Student b);

class StudentCollection
{

public:
	int now = 0;
	string raw[300];
	Student whole[100];

	bool sorted = false;

	friend istream& operator>> (istream& in, StudentCollection& inp);
	friend ostream& operator<< (ostream& out, const StudentCollection& otp);

	Student& operator[] (string name)
	{
		if (!sorted)
		{
			sort(raw, raw + now, cmp);
			// raw is those 3*n strings input from 'cin'
			// cmp is a bool function which compares two strings under the "dictionary order"
			// sort (array_name, array_name + range, sort_method)
			// sort the array within the range, under the specific method (which should be a bool function)
			sorted = true;
		}
		// after sorted, the 'raw' strings sharing the same 'name' part will get together.

		string a;

		for (int i = 0; i < now; i += 3) // each student has three 'raw' strings
		{
			for (int j = 0; j < raw[i].length(); j++)
			{
				if (raw[i].compare(0, name.length(), name, 0, name.length()) == 0) // if a specific 'name' is found
				{
					a = raw[i] + ' ' + raw[i + 2] + ' ' + raw[i + 1] + ' '; // get an input for the construction of this Student
					break;
				}
			}
		}

		Student* stu = new Student(a);
		return (*stu);
	}

	void sortByScore();

};

#endif