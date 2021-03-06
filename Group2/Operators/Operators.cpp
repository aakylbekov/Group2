// Operators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//class Test {
//	void testUnit(Unit u) {
//		u.injure();
//		assert(u.hp == 75);
//	}
//	void testInteger(Integer i) {
//
//	}
//};
class Integer {
	int value;
public:
	explicit Integer() = delete;
	//конструктор копирования
	Integer(const Integer& i) {
		value = i.value;
	}
	//конструктор переноса
	//&& - двойная ссылка - объект передаваемый по ссылке будет уничтожена
	//при выходе из функции, передана будет только копия
	explicit Integer(const Integer&& i) {
		value = move(i.value);
	}
	explicit Integer(int x) : value(x) {
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
	Integer& operator [](int i) {
	}
	Integer& operator ()(int i) {
	}	
	//перегрузка преобразования типов
	explicit operator double() {
		return value;
	}
	explicit operator int() {
		return value;
	}
	explicit operator char() {
		return value;
	}
	friend void print(Integer& i);
	friend void test(Integer& i);
	friend class Test;
	friend ostream& operator <<(ostream& os, Integer& x);
};
ostream& operator <<(ostream& os, Integer& x) {
	os << x.value << endl;
	return os;
}

class Unit {
	int hp;
	Unit() {
		hp = 100;
	}
	void injure() {
		hp -= 25;
	}
	void heal() {
		hp += 25;
	}
	friend class Test;
};

void test(Integer& i) {
	Integer x = i + Integer(6);
}

void print(Integer& i) {
	cout << i.value;
}

//арифметическая прогрессия
class Progression {
public:
	int a1, d;
	explicit Progression(int a1, int d) {
		this->a1 = a1;
		this->d = d;
	}
	//перегрузка квадратных скобок
	int operator [](int i) {
		return a1 + (i - 1) * d;
	}
	//перегрузка обычных скобок
	int operator ()(int i) {
		return (2 * a1 + d * (i - 1)) * i / 2;
	}
};

//ostream& operator <<(ostream& os, Integer& x) {
//	os << x.value;
//	return os;
//}

void f1() {
	////попадает в конструктор
	//Integer y(5);
	//int x = 6;
	////попадает в перегруженный оператор
	//y = x;
	//cout << y.value << endl;
}
//void f2() {
//	//Integer a(5);
//	//Integer b(6);
//	////c=11
//	//Integer c = a + b;	//Integer c = a.+(b);
//	//cout << c.value << endl;
//	////c=11
//	//cout << c++.value << endl;
//	////c=12
//	//cout << c.value << endl;
//
//	Integer x(11);
//	int y = 5;
//	x = y;
//	cout << x.value << endl;
//
//	cout << x++.value << endl;	//тут вернется old(value) со старым значением
//	cout << x.value << endl;
//}
//void f3(){
//	int x = 5, y = 6;
//	bool z = x == y;
//	Integer a(5), b(5), c(6);
//	cout << (a == b) << endl;	//true
//	cout << (a == c) << endl;	//false
//}
//void f4() {
//	Integer a(1);
//	Integer b = move(a);
//}
//void f5() {
//	Progression p(5, 2);
//	cout << p[5] << endl;
//	cout << p(5) << endl;
//}
//void f6() {
//	Integer a(5);
//	double b;
//	b = (double)a;
//	char x;
//	x = (char)a;
//	cout << x << endl;
//}
void f7(){
	Integer x(5);
	print(x);
}
int main()
{
	Integer x(5);
	cout << x;
	system("pause");
	return 0;
}