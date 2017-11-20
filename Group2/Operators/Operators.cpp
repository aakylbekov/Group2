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
};

//ostream& operator <<(ostream& os, Integer& x) {
//	os << x.value;
//	return os;
//}

void f1() {
	//попадает в конструктор
	Integer y(5);
	int x = 5;
	//попадает в перегруженный оператор
	y = x;
	cout << y.value << endl;
}
int main()
{
	Integer a(5);
	Integer b(6);
	//c=11
	Integer c = a + b;	//Integer c = a.+(b);
	cout << c.value << endl;
	//c=11
	cout << c++.value << endl;
	//c=12
	cout << c.value << endl;
	return 0;
}