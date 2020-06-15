#include "wrapper_counter.h"

class AbstractWrapper {

protected:
	string uid;

public:
	AbstractWrapper() {}
	virtual ~AbstractWrapper() {}
	virtual string type() = 0;
	virtual string to_string() = 0;
	friend ostream &operator <<(ostream &out, AbstractWrapper *w) {
		return out << w->uid << ": " << w->to_string();
	}
};

class IntegerWrapper : public AbstractWrapper {
	int *pointer;
public:
	IntegerWrapper(int *ptr) : pointer(ptr)
	{
		uid = WrapperCounter::getUID(type());
	}
	~IntegerWrapper() { delete pointer; }
	string type() { return "int"; }
	string to_string() {
		return std::to_string(*pointer);
	}
};

class StringWrapper : public AbstractWrapper {
protected:
	char *pointer;
	int len;
public:
	StringWrapper(): pointer(nullptr), len(0) {};

	StringWrapper(char *ptr, int len) : pointer(ptr), len(len)
	{
		uid = WrapperCounter::getUID(type());
	}

	~StringWrapper() { delete[] pointer; }
	int length() { return len; }
	string type() { return "string"; }
	string to_string() {
		return string(pointer, len);
	}
};

class ChineseStringWrapper : public StringWrapper {
	// 用三个char表示一个汉字
public:
	ChineseStringWrapper(char *ptr, int length)
	{
		StringWrapper();
		pointer = ptr;
		len = length;
		uid = WrapperCounter::getUID(type());
	}
	~ChineseStringWrapper() {}
	int length(bool rawChars = true) {
		// 如果rawChars为false，则返回中文字符数；否则返回实际char数组长度
		if (rawChars) return len;
		else return len / 3;
	}
	string type() { return "chineseString"; }
};