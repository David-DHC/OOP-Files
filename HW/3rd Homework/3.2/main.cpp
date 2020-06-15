#include <iostream>
#include "MyAnswer.h"
using namespace std;

#define Option_A auto testA = f1(move(b));
#define Option_B auto testB = f2(b);
#define Option_C auto testC = f3(move(b));
#define Option_D auto testD = f3(move(b));
#define Option_E auto& testE = f4(f);
#define Option_F auto testF = f5(move(b));

int times = 0;

string names[26] = {
	"B::data1",
	"b",
	"t.data2",
	"f[0]",
	"f[1]",
	"b",
	"f",
	"testC",
	"b",
	"b",
	"testD",
	"b",
	"testF",
	"b",
	"testA",
	"b",
	"testA",
	"testF",
	"testD",
	"testC",
	"f[1]",
	"f[0]",
	"t.data2",
	"b",
	"f",
	"B::data1"
};

class A {
public:
	A() {
		cout << "A constructing..." << names[times] << endl;
		times++;
	}
	A(const A &a) {
		cout << "A copy constructing..." << names[times] << endl;
		times++;
	}
	A(A&& a) {
		cout << "A move constructing..." << names[times] << endl;
		times++;
	}
	~A() {
		cout << "A destructing..." << names[times] << endl;
		times++;
	}
};

class B {
private:
	static A data1;
	A data2;
public:
	B() {
		cout << "B constructing...t" << endl;
	}
	~B() {
		cout << "B destructing...t" << endl;
	}
};

A B::data1;

A f1(A b) {
	cout << "------after call------" << endl;
	A f = move(b);
	cout << "------before return------" << endl;
	return f;
}

A* f2(A& b) {
	cout << "------after call------" << endl;
	A* f = &b;
	cout << "------before return------" << endl;
	return f;
}


A f3(A b) {
	cout << "------after call------" << endl;
	static A f;
	cout << "------before return------" << endl;
	return f;
}

A& f4(A* b) {
	cout << "------after call------" << endl;
	A *f = b;
	cout << "------before return------" << endl;
	return *f;
}

A f5(A&& b) {
	cout << "------after call------" << endl;
	A f = b;
	cout << "------before return------" << endl;
	return f;
}

void work()
{
	cout << "=======entering work=======" << endl;
	A b;
	B t;

	A f[2];

	cout << "------before call------" << endl;
	Answer1 // (1)
	cout << "------after return------" << endl << endl;

	cout << "------before call------" << endl;
	Answer2 //(2)
	cout << "------after return------" << endl << endl;

	cout << "------before call------" << endl;
	Answer3 //(3)
	cout << "------after return------" << endl << endl;

	cout << "------before call------" << endl;
	Answer4 //(4)
	cout << "------after return------" << endl << endl;

	cout << "------before call------" << endl;
	Answer5 //(5)
	cout << "------after return------" << endl << endl;

	cout << "------before call------" << endl;
	Answer6 //(6)
	cout << "------after return------" << endl << endl;

	cout << "=======exiting work=======" << endl;
}

int main() {
	cout << "=======entering main=======" << endl;
	work();
	cout << "=======exiting main=======" << endl;
	return 0;
}
