// Snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Point {
public:
	short *x, *y;
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
	void draw(char sign) {
		goToXY();
		cout << sign;
	}
	void goToXY() {
		COORD position = { *x, *y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	}
};

class Snake {
public:
	vector<Point> *body;
	char *sign;
	Snake(short x, short y) {
		sign = new char('*');
		body = new vector<Point>();
		body->reserve(100);
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
};

class Food {
public:
	Point *body;
	char *sign;
	static int cnt;
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
		++cnt;
	}
};
int Food::cnt = 0;

class Game {
	Snake *snake;
	Food *food;
	bool isActive;
	void draw() {
		snake->draw();
		food->draw();
	}
	void checkIfSnakeEatsFood() {
		if (*snake->body->at(0).x == *food->body->x &&
			*snake->body->at(0).y == *food->body->y) {
			snake->eat(*food->body);
			food->recreate();
		}
	}
public:
	void play() {
		srand(time(NULL));
		//какое действие предпримет пользователь
		char action;
		//на какую позицию двигаться нашей змейке
		short dx = 0, dy = 0;
		//isActive - работает ли игра сейчас
		while (isActive) {
			system("cls");
			//прорисовали все объекты в консоли
			draw();
			//получить значение от пользователя через клавиатуру
			action = _getch();


			switch (action)
			{
			case 'w':
				dx = 0;
				dy = -1;
				break;
			case 'a':
				dx = -1;
				dy = 0;
				break;
			case 's':
				dx = 0;
				dy = 1;
				break;
			case 'd':
				dx = 1;
				dy = 0;
				break;
				//переписать под ESC
			case 'r':
				isActive = false;
			default:
				cout << "error";
				break;
			}
			snake->move(dx, dy);
			checkIfSnakeEatsFood();
			//если съедаем себя, то возвращаем true и 
			//isActive становится false, заканчивается игра
			isActive = !snake->checkIfSnakeEatsItself();
		}
	}
	Game() {
		isActive = true;
		snake = new Snake(10, 10);
		food = new Food(5, 5);
	}
	~Game() {
		delete snake;
		delete food;
	}
};
int main()
{
	Game *game = new Game();
	game->play();
	delete game;
	return 0;
}