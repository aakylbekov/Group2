// PracticeOnOperators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

enum Month {
	January = 1, February, March, April, May, June,
	Jule, August, September, October, November, December
};
class Date {
	//TODO: сделать switch-case дней месяцев и високосного года
	int *day, *month, *year;
	//Month *month;
public:
	int getMonthMultiplier() const {
		switch (*month) {
		case 1:
			return 31;
		case 2:
			if (*year % 4 == 0 && *year % 100 != 0 || *year % 400 == 0) {
				return 29;
			}
			return 28;
		case 3:
			return 31;
		case 4:
			return 30;
		case 5:
			return 31;
		case 6:
			return 30;
		case 7:
			return 31;
		case 8:
			return 31;
		case 9:
			return 30;
		case 10:
			return 31;
		case 11:
			return 30;
		case 12:
			return 31;
		default:
			break;
		}
	}

	Date(int day, int month, int year) {
		this->day = new int(day);
		//this->month = new Month((Month)month);
		this->month = new int(month);
		this->year = new int(year);
	}
	~Date() {
		delete day, month, year;
	}
	friend int operator -(const Date& d1, const Date& d2);
};

int operator -(const Date& d1, const Date& d2) {
	return (*d1.day + (*d1.month * (d1.getMonthMultiplier())) + (*d1.year * 365)) -
		(*d2.day + (*d2.month * (d2.getMonthMultiplier())) + (*d2.year * 365));
}

class String {
	string value;
	friend String operator *(const string a, const string b);
	friend ostream& operator <<(ostream& os, String& s);
};

ostream& operator <<(ostream& os, String& s) {
	os << s.value;
	return os;
}

String operator *(const string a, const string b) {
	String s;
	for (int i = 0; i < a.length(); ++i) {
		for (int j = 0; j < b.length(); ++j) {
			if (a[i] == b[j]) {
				s.value.push_back(a[i]);
			}
		}
	}
	return s;
}

void f1() {
	Date d1(22, 1, 1900);
	Date d2(22, 11, 2017);
	cout << d2 - d1 << endl;
}
int main()
{
	string a = "sdqcg";
	string b = "rgfas34";
	String s = a * b;
	cout << s << endl;
	system("pause");
	return 0;
}
