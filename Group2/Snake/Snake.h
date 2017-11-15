#pragma once

class Snake {
public:
	//объявление
	vector<Point> *body;
	char *sign;
	Snake(short x, short y) {
		sign = new char('*');
		//инициализация
		body = new vector<Point>();
		body->reserve(100);
		//добавление первой точки
		body->push_back(*(new Point(x, y)));
	}
	~Snake() {
		delete body;
		delete sign;
	}
	void draw() {
		//vector->size() = array->length() for vector
		for (int i = 0; i < body->size(); ++i) {
			//at(i) = [i] for vector
			body->at(i).draw(*sign);
		}
	}
	void move(short dx, short dy) {
		//передвинуть все элементы вперед до первого элемента
		for (int i = body->size() - 1; i > 0; --i) {
			*body->at(i).x = *body->at(i - 1).x;
			*body->at(i).y = *body->at(i - 1).y;
		}
		//первая точка двигается по координатам
		*body->at(0).x += dx;
		*body->at(0).y += dy;
	}
	void eat(Point point) {
		body->push_back(*(new Point(point)));
	}
	bool checkIfSnakeEatsItself() {
		if (body->size() > 1) {
			for (int i = 1; i < body->size() - 1; ++i) {
				if (*body->at(0).x == *body->at(i).x &&
					*body->at(0).y == *body->at(i).y)
					return true;
			}
		}
		return false;
	}
	void clear() {
		//"очистка" последнего элемента в консоли
		body->back().draw(' ');
	}
};