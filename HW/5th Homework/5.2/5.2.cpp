#include <bits/stdc++.h>
using namespace std;

class student
{
public:
	string name;
	int year;
	int month;
	int day;
	string number;
	string email;

	student()
	{
		name = "";
		year = 0;
		month = 0;
		day = 0;
		number = "";
		email = "";
	}

	student(string a, int b1, int b2, int b3, string c, string d)
	{
		name = a;
		year = b1;
		month = b2;
		day = b3;
		number = c;
		email = d;
	}

	bool operator < (const student& temp)
	{
		if (this->year > temp.year)
			return false;
		else if (this->year < temp.year)
			return true;

		if (this->month > temp.month)
			return false;
		else if (this->month < temp.month)
			return true;

		if (this->day > temp.day)
			return false;
		else if (this->day < temp.day)
			return true;

		return true;
	}
};

int main()
{
	string raw;
	getline(cin, raw);
	int n = stoi(raw);
	student s[n];

	for (int i = 0; i < n; i++)
	{
		getline(cin, raw);

		string tmpname, tmpnumber, tmpemail;
		int tmpy = 0, tmpm = 0, tmpd = 0;

		bool checked[4] = {0};

		for (int j = 0; j < raw.length(); j++)
		{
			if (!checked[0] && (raw.substr(j, 3) == " am" || raw.substr(j, 3) == " is")) // name
			{
				j += 4;
				for (int k = j; k < raw.length(); k++)
				{
					if (raw[k] == '.')
					{
						tmpname = raw.substr(j, k - j);
						j = k;
						break;
					}
				}

				checked[0] = true; // name is found
			}

			if (!checked[1] && (raw[j] == '1' || raw[j] == '2') && (raw[j + 4] == '-' || raw[j + 4] == '.')) // birthday
			{
				tmpy = stoi(raw.substr(j, 4));
				j += 5;

				for (int k = j; k < raw.length(); k++)
				{
					if (!tmpm && (raw[k] == '-' || raw[k] == '.'))
					{
						tmpm = stoi(raw.substr(j, k - j));
						j = k + 1;
					}

					else if (!tmpd && (raw[k] == '.' || raw[k] == ' '))
					{
						tmpd = stoi(raw.substr(j, k - j));
						j = k + 1;
						break;
					}
				}

				checked[1] = true; // birthday is found
			}

			if (!checked[2] && raw[j] == '1')
			{
				for (int k = j; k < j + 11; k++)
				{
					if (raw[k] < 48 || raw[k] > 57)
						break;

					if (k == j + 10)
					{
						tmpnumber = raw.substr(j, 11);
						checked[2] = true;
					}
				}
			}

			if (!checked[3] && raw[j] == '@')
			{
				int s, f;

				for (int k = j; k > 0; k--)
				{
					if (raw[k] == ' ' || raw[k] == '(')
					{
						s = k + 1;
						break;
					}
				}

				for (int k = j; k < raw.length(); k++)
				{
					if ((raw[k] == ',' || raw[k] == '.' || raw[k] == ')')
					        && (raw.substr(k - 3, 3) == "com"
					            || raw.substr(k - 3, 3) == "net"
					            || raw.substr(k - 2, 2) == "cn"))
					{
						f = k;
						break;
					}
				}

				tmpemail = raw.substr(s, f - s);
				checked[3] = true;
			}
		}

		student tmp(tmpname, tmpy, tmpm, tmpd, tmpnumber, tmpemail);
		s[i] = tmp;
	}

	sort(s, s + n);

	for (int i = 0; i < n; i++)
	{
		cout << s[i].name << '-' << s[i].year << '.';

		if (s[i].month < 10)
			cout << '0';

		cout << s[i].month << '.';

		if (s[i].day < 10)
			cout << '0';

		cout << s[i].day << '-' << s[i].number << '-' << s[i].email << endl;
	}

	return 0;
}