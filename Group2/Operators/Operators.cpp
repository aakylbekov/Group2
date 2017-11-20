// Operators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Integer {
public:
	int value;
	explicit Integer(){}
	explicit Integer(int x) : value(x){}
	Integer& operator =(const int& x) {
		value = x;
		return *this;
	}
	//lvalue vs rvalue - &, &&
	Integer& operator +(Integer& )
};

//ostream& operator <<(ostream& os, Integer& x) {
//	os << x.value;
//	return os;
//}

int main()
{
	//попадает в конструктор
	Integer y(5);
	int x = 5;
	//попадает в перегруженный оператор
	y = x;
	cout << y.value << endl;
    return 0;
}

