#pragma once

class Wall
{
public:
	Point * body;
	char *sign;
	Wall() {
		sign = new char('#');
		body = new Point[100];
		for (int i = 0; i < 25; ++i) {
			body[i] = *(new Point(i, 0));
			body[i + 25] = *(new Point(0, i));
			body[i + 50] = *(new Point(25, i));
			body[i + 75] = *(new Point(i, 25));
		}
	}
	void draw() {
		for (int i = 0; i < 100; ++i) {
			body[i].draw(*sign);
		}
	}
	~Wall(){
		delete[] body;
		delete sign;
	}
};