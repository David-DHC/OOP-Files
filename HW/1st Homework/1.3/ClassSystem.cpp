#include <bits/stdc++.h>
#include "ClassSystem.h"
using namespace std;

void ClassSystem::addStudent(Student stu)
{
	names[n1] = stu.name;
	n1++;
}

void ClassSystem::addClassNumber()
{
	for (int i = 0; i < n1; i++)
	{
		atimes[i]++;
		in[i] = false;
	}
}

void ClassSystem::signIn(string name)
{
	for (int i = 0; i < n1; i++)
	{
		if (in[i])
			continue;

		if (names[i] == name)
		{
			in[i] = true;
			atimes[i]--;
			ptimes[i]++;
			break;
		}
	}
}

Student ClassSystem::getStudentById(int i)
{
	Student stu(names[i]);
	stu.p = ptimes[i];
	stu.a = atimes[i];

	return stu;
}

Student ClassSystem::getStudentByName(string name)
{
	int k;
	for (k = 0; k < 300; k++)
	{
		if (names[k] == name)
			break;
	}

	Student stu(names[k]);
	stu.p = ptimes[k];
	stu.a = atimes[k];

	return stu;
}