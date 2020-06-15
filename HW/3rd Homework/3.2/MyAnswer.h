#define Answer1 Option_C
#define Answer2 Option_B
#define Answer3 Option_D
#define Answer4 Option_F
#define Answer5 Option_A
#define Answer6 Option_E

/*

A B::data1;

A b;
B t;


A f3(A b) //(1)
{
	cout << "------after call------" << endl;
	static A f; //(2)
	cout << "------before return------" << endl;
	return f;
}

auto testC = f3(move(b)); //(3)
//(4)

(1) 传入b时调用移动构造函数
(2) 静态对象f构造时调用默认构造函数
(3) 给testC赋值时调用拷贝构造函数(已开启优化)
(4) 析构b时调用析构函数

优化后的输出：
------before call------
A move constructing...b
------after call------
A constructing...f
------before return------
A copy constructing...testC
A destructing...b
------after return------


A f5(A&& b)
{
	cout << "------after call------" << endl;
	A f = b; //(1)
	cout << "------before return------" << endl;
	return f;
}

(1) 创建f时为了传值调用拷贝构造函数(b本身为左值)

优化后的输出：
------before call------
------after call------
A copy constructing...testF
------before return------
------after return------


------before call------
A move constructing...
------after call------
A constructing...f
------before return------
A copy constructing...return value
A move constructing...testC
A destructing...return value
A destructing...b
------after return------  // static f, testC


A* f2(A& b) {
	cout << "------after call------" << endl;
	A* f = &b;
	cout << "------before return------" << endl;
	return f;
}
// auto testB = f2(b);


A f3(A b) {
	cout << "------after call------" << endl;
	static A f;
	cout << "------before return------" << endl;
	return f;
}
// auto testC = f3(move(b));


A f5(A&& b)
{
	cout << "------after call------" << endl;
	A f = b; (1)
	cout << "------before return------" << endl;
	return f; (2)
}
auto testF = f5(move(b)); (3)



A f1(A b) {
	cout << "------after call------" << endl;
	A f = move(b);
	cout << "------before return------" << endl;
	return f;
}
//auto testA = f1(move(b));


A& f4(A* b) {
	cout << "------after call------" << endl;
	A *f = b;
	cout << "------before return------" << endl;
	return *f;
}
//auto& testE = f4(f);
*/