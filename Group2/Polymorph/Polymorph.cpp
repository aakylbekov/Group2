// Polymorph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A {
public:
	void S() {
		cout << "A";
	}
};
class B :public A {
public:
	void S() {
		cout << "B";
	}
};

int main()
{
	A a;
	a.S();
	B b;
	b.S();
	A *x = new B();
	x->S();
	delete x;
    return 0;
}

