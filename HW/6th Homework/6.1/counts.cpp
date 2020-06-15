#include <iostream>
#include <cmath>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

static mutex locker[100];

void check(int begin, int end, int array[], int count[], int v)
{
	int *localcount = new int[v + 1];

	for (int i = begin; i < end; i++)
	{
		locker[array[i]].lock();
		localcount[array[i]]++;
		locker[array[i]].unlock();
	}

	for (int i = 0; i <= v; i++)
	{
		count[i] += localcount[i];
	}
}

void parallel_count(int array[], int arrsize, int count[], int v)
{
	thread* threads[4];
	int divide = arrsize / 4, mi = 0, x = arrsize % 4;

	for (int i = 0; i < 4; i++)
	{
		x += divide;
		if (x > arrsize)
		{
			x = arrsize + 1;
		}
		threads[i] = new thread(check, mi, x, array, count, v);
		mi = x;
	}

	for (int i = 0; i < 4; i++)
	{
		threads[i]->join();
	}

	for (int i = 0; i < 4; i++)
	{
		delete threads[i];
	}
}