// Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//базовый - base
class Student {
public:
	Student() {
		cout << "Student()" << endl;
	}
	~Student() {
		cout << "~Student()" << endl;
	}
};

//дочерный - derived
class Master :public Student {
public:
	Master() {
		cout << "Master()" << endl;
	}
	~Master() {
		cout << "~Master()" << endl;
	}
};

int main()
{
	Student *a;
	a = new Master();
	delete a;
	return 0;
}
