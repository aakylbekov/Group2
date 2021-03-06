// Args.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Point {
public:
	int x, y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

template <typename... T>
int check(T... args) {
	int cnt = 0, r = 5;
	for (auto&& i :
		initializer_list<Point>{ args... }) {
		if (
			i.x * i.x +
			i.y * i.y <=
			r * r) {
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	cout <<
		check(Point{ 1, 2 },
			Point{ 2, 3 },
			Point{ 6, 7 },
			Point{ 4, 3 }) << endl;
	system("pause");
	return 0;
}
