#pragma once

class Food {
public:
	Point *body;
	char *sign;
	Food(short x, short y) {
		body = new Point(x, y);
		sign = new char('@');
	}
	~Food() {
		delete sign;
		delete body;
	}
	void draw() {
		body->draw(*sign);
	}
	void recreate() {
		*this->body->x = rand() % 39 + 1;
		*this->body->y = rand() % 39 + 1;
	}
};