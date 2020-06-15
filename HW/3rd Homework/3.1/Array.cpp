#include "Array.h"
#include "Node.h"

using namespace std;

Array::Array (int n)
{
	length = n;
	arr = new Node[n];
}

Array::~Array()
{
	delete[] arr;
}

void Array::update(int q, int r)
{
	arr[q] = arr[r];
}

void Array::swap(int q, int r)
{
	Node tmp = move(arr[q]);
	arr[q] = move(arr[r]);
	arr[r] = move(tmp);
}

void Array::insert(int q, int r)
{
	for (int i = length - 1; i >= q + 1; i--)
	{
		arr[i] = move(arr[i - 1]);
	}

	arr[q] = move(Node(r));
}