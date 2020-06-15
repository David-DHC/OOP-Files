#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

Student::Student()
{
	grade = "0";
	score[0] = 0;
	score[1] = 0;
	score[2] = 0;
	score[3] = 0;
}

Student::Student(string input)
{
	grade = input;

	int str = 0, len = 0, t = 0; // str means 'start', len means 'length', t means 'temporary'
	for (int i = 0; i < grade.length(); i++)
	{
		if (grade[i] >= 48 && grade[i] <= 57) // using ASCII to check if this character is a number
		{
			str = i;
			for (int j = i; j < i + 4; j++)
			{
				if (grade[j] == ' ')
				{
					len = j - i + 1; // get the numbers' length of this score
					i = j; // skip these numbers
					break;
				}
			}

			score[t] = stoi(grade.substr(str, len)); //transform these number into storage type 'int'
			t++;
			str = 0;
			len = 0;
		}
	}

	string name;
	for (int i = 0; i < grade.length(); i++)
	{
		if (grade[i] == '-')
		{
			t = i;
			break;
		}
	}

	name = grade.substr(0, t);

	score[3] = score[0] + score[1] + score[2];

	string s0 = to_string(score[0]), s1 = to_string(score[1]),
	       s2 = to_string(score[2]), s3 = to_string(score[3]);

	grade =  name + "-Total-" + s3 + "-Chinese-" + s0 + "-Math-" + s1 + "-English-" + s2;
}

bool Student::operator < (const Student& temp)
{
	if (this->score[3] > temp.score[3])
		return false;
	else if (this->score[3] < temp.score[3])
		return true;

	if (this->score[0] > temp.score[0])
		return false;
	else if (this->score[0] < temp.score[0])
		return true;

	if (this->score[1] > temp.score[1])
		return false;
	else if (this->score[1] < temp.score[1])
		return true;

	if (this->score[2] > temp.score[2])
		return false;
	else if (this->score[2] < temp.score[2])
		return true;
}

ostream& operator<< (ostream& out, const Student& otp)
{
	out << otp.grade;
	return out;
}