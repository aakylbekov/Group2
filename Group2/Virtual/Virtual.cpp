// Virtual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A {
public:
	A() { cout << "A()" << endl; }
	virtual void say() {
		cout << "I'm A" << endl;
	}
	virtual ~A() { cout << "~A()" << endl; }
};
class B :public A {
public:
	void say() {
		cout << "I'm B" << endl;
	}
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
};
class IProgrammer {
public:
	IProgrammer() {}
	virtual void usePC() = 0;
	virtual string doReport() = 0;
};
class Worker :public IProgrammer {
	void usePC() {
		cout << "I use PC" << endl;
	}
	string doReport() {
		return "Job is done";
	}
};
//1. Требования - абстрактный класс
//2. Вы - наследующий класс

int main()
{
	/*A **a = new A*[2];
	a[0] = new B();
	a[1] = new A();
	for (int i = 0; i < 2; i++) {
		a[i]->say();
	}*/
	/*A *b = new B();
	delete b;*/
	IProgrammer *a = new Worker();
	return 0;
}
