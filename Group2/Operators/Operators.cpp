// Operators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Integer {
public:
	int value;
	explicit Integer() {}
	explicit Integer(int x) {
		value = x;
	}
	Integer& operator =(const int& x) {
		value = x;
		return *this;
	}
	//lvalue vs rvalue - &, &&
	Integer& operator +(const Integer& x) {
		//конструктор Integer y
		Integer y(value + x.value);
		return y;
	}
	//префикс ++i
	Integer& operator ++() {
		++this->value;
		return *this;
	}
	//постфикс i++
	Integer& operator ++(int) {
		Integer old(value);
		++value;
		return old;
	}
	bool operator ==(const Integer& x) {
		return value == x.value;
	}
	bool operator <(const Integer& x) {
		return value < x.value;
	}
};

//ostream& operator <<(ostream& os, Integer& x) {
//	os << x.value;
//	return os;
//}

void f1() {
	//попадает в конструктор
	Integer y(5);
	int x = 6;
	//попадает в перегруженный оператор
	y = x;
	cout << y.value << endl;
}
void f2() {
	//Integer a(5);
	//Integer b(6);
	////c=11
	//Integer c = a + b;	//Integer c = a.+(b);
	//cout << c.value << endl;
	////c=11
	//cout << c++.value << endl;
	////c=12
	//cout << c.value << endl;

	Integer x(11);
	int y = 5;
	x = y;
	cout << x.value << endl;

	cout << x++.value << endl;	//тут вернется old(value) со старым значением
	cout << x.value << endl;
}
int main()
{
	int x = 5, y = 6;
	bool z = x == y;
	Integer a(5), b(5), c(6);
	cout << (a == b) << endl;	//true
	cout << (a == c) << endl;	//false
	return 0;
}