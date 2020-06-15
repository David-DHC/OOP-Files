#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

class ClassSystem // tusht
{
public:
	int n1 = 0;
	string names[300];
	int ptimes[300] = {0};
	int atimes[300] = {0};
	bool in[300] = {0};

	void addStudent(Student stu);

	void addClassNumber();

	void signIn(string name);

	Student getStudentById(int i);

	Student getStudentByName(string name);
};