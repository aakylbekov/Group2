// Const.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Contact {
	//объявление
	string *name, *phone;
	bool *option;
public:
	Contact() {}
	Contact(string name, string phone, bool option) {
		//инициализация
		this->option = new bool(option);
		this->name = new string(name);
		this->phone = new string(phone);
	}
	Contact(const Contact &contact) {
		this->name = new string(*contact.name);
		this->phone = new string(*contact.phone);
	}
	~Contact() {
		delete name;
		delete phone;
	}
	//const - внутри метода не будут меняться значения любых объектов

	string getName() const {
		return *name;
	}
	void setName(string name) {
		*this->name = name;
	}
	string getPhone() const {
		return *phone;
	}
	void setPhone(string phone) {
		*this->phone = phone;
	}
};

class Integer {
public:
	int value;
	Integer(int x): value(x) {
	}
	//явная перегрузка оператора требует явный вызов
	explicit operator float() {
		return value * 1.0;
	}
	explicit operator int() {
		return value;
	}
};
void f1() {
	Integer a(1);
	float x = (float)a;
	int y = (int)a;
	cout << x << endl;
}
int main()
{	
    return 0;
}