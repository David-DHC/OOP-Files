#include <bits/stdc++.h>
#include "StudentCollection.h"
using namespace std;

bool cmp(string a, string b)
{
	if (b > a)
		return true;
	return false;
}

bool cmp1(Student a, Student b)
{
	if (a < b)
		return false;
	return true;
}

istream& operator>> (istream& in, StudentCollection& inp)
{
	in >> inp.raw[inp.now];
	inp.now++;
	return in;
}

ostream& operator<< (ostream& out, const StudentCollection& otp)
{
	for (int i = 0; i < otp.now / 3; i++)
	{
		out << otp.whole[i].grade << endl;
	}
	return out;
}

void StudentCollection::sortByScore()
{
	string a;
	for (int i = 0; i < now / 3; i++)
	{
		a = this->raw[3 * i] + " " + this->raw[3 * i + 2] + " " + this->raw[3 * i + 1] + " ";
		Student *temp = new Student(a);
		this->whole[i] = (*temp);
		delete temp;
	}

	sort(whole, whole + now / 3, cmp1);
}