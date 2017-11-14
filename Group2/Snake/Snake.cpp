// Snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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