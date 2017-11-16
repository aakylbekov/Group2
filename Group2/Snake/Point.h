#pragma once

class Point {
public:
	short *x, *y;
	Point() {}
	Point(short x, short y) {
		this->x = new short(x);
		this->y = new short(y);
	}
	Point(const Point &point) {
		this->x = new short(*point.x);
		this->y = new short(*point.y);
	}
	~Point() {
		delete x;
		delete y;
	}
	bool operator ==(Point& point) {
		return *point.x == *this->x && *point.y == *this->y;
	}
	void draw(char sign) {
		goToXY();
		cout << sign;
	}
	void goToXY() {
		COORD position = { *x, *y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
};