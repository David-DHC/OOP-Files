#include <bits/stdc++.h>
using namespace std;

bool checker(char const *a[])
{
	if (a[1][0] == '-' )
	{
		if (a[1][1] == 'e' || a[1][1] == 'n' || a[1][1] == 'E')
		{
			if (a[1][2] == 'e' || a[1][2] == 'n' || a[1][2] == 'E' || a[1][2] == NULL)
				return true;
		}
	}

	return false;
}

int main(int argc, char const *argv[])
{
	if (!checker(argv))
	{
		for (int i = 1; i < argc - 1; i++)
		{
			cout << argv[i] << ' ';
		}

		cout << argv[argc - 1] << '\n';
		return 0;
	}

	if (argv[1][1] == 'n' && argv[1][2] == NULL)
	{
		for (int i = 2; i < argc - 1; i++)
		{
			cout << argv[i] << ' ';
		}

		cout << argv[argc - 1];
		return 0;
	}

	if (argv[1][1] == 'n' && argv[1][2] == 'e')
	{
		cout << "asd" << '\n';
		return 0;
	}

	if (argv[1][1] == 'e' && argv[2][1] != '?' && argv[2][0] != '-')
	{
		cout << '\t' << 't' << '\e' << 'e';
		return 0;
	}

	if (argv[1][1] == 'e' && argv[2][1] == '?')
	{
		cout << '\134' << '?' << endl;
		return 0;
	}

	if (argv[1][1] == 'E' && argv[1][2] == 'n')
	{
		cout << "asd"  << '\134' << 'n';
		return 0;
	}

	cout << "-a -e" << endl;
	return 0;
}