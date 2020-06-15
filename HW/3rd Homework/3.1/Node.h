#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	static int num_createfunc, num_copyfunc, num_movefunc, num_copyassign, num_moveassign, num_delfunc;
	int val;
public:
	Node(int v = 0);
	~Node();
	Node(const Node &y);
	Node(Node &&y);
	Node& operator=(const Node &y);
	Node& operator=(Node &&y);
	friend istream& operator>>(istream& in, Node& x);
	friend ostream& operator<<(ostream& out, const Node& x);
	static void outputResult(int ref_ans);
};
