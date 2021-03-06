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
void f1() {
	Student *a;
	a = new Master();
	delete a;
}

class Mammal {
public:
	Mammal() {
		cout << "Mammal()" << endl;
	}
	~Mammal() {
		cout << "~Mammal()" << endl;
	}
	virtual void move() = 0;
};

class Horse : public Mammal {
public:
	Horse() {
		cout << "Horse()" << endl;
	}
	~Horse() {
		cout << "~Horse()" << endl;
	}
	void move() {
		cout << "horse moves" << endl;
	}
};
class Human : public Mammal {
public:
	Human() {
		cout << "Human()" << endl;
	}
	~Human() {
		cout << "~Human()" << endl;
	}
	void move() {
		cout << "human moves" << endl;
	}
};
class Centaur : public Human, Horse{
public:
	Centaur() {
		cout << "Centaur()" << endl;
	}
	~Centaur() {
		cout << "~Centaur()" << endl;
	}
};
int main()
{
	Centaur *c = new Centaur();
	c->Human::move();
	delete c;
	return 0;
}
