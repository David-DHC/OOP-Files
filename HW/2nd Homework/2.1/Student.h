#ifndef STUDENT_H
#define STUDENT_H

#include <bits/stdc++.h>
using namespace std;

class Student
{
	int score[4];

public:

	string grade;

	Student();

	Student(string input);

	friend ostream& operator<< (ostream& out, const Student& otp);

	bool operator < (const Student& temp);
};

#endif