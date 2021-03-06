// Snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Game {
	Snake *snake;
	Food *food;
	Wall *wall;
	bool isActive;
	void draw() {
		snake->draw();
		food->draw();
		wall->draw();
	}
	void checkIfSnakeEatsFood() {
		if (snake->body->at(0) == *food->body) {
			snake->eat(*food->body);
			food->recreate();
			food->draw();
		}
	}
public:
	//оставили прототип
	void play();
	bool checkIfSnakeCrushes();
	Game() {
		isActive = true;
		snake = new Snake(4, 5);
		food = new Food(5, 5);
		wall = new Wall();
	}
	~Game() {
		delete snake;
		delete food;
		delete wall;
	}
};
//реализовали метод вне класса
void Game::play() {
	{
		srand(time(NULL));
		//какое действие предпримет пользователь
		char action = '~';
		//на какую позицию двигаться нашей змейке
		short dx = 1, dy = 0;
		//isActive - работает ли игра сейчас
		draw();
		while (isActive) {
			//прорисовали все объекты в консоли
			//проверить введено ли что-либо, false если не введено
			if (_kbhit()) {
				//получить значение от пользователя через клавиатуру
				action = _getch();
			}

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
			case '~':
				break;
			default:
				cout << "error";
				break;
			}
			Sleep(300);
			//очищаем змейку
			snake->clear();
			//двигаемся
			snake->move(dx, dy);
			//перерисовываем
			snake->body->front().draw(*snake->sign);
			checkIfSnakeEatsFood();
			//если съедаем себя или попадаем в стену, то возвращаем true и 
			//isActive становится false, заканчивается игра
			isActive = !snake->checkIfSnakeEatsItself() && !checkIfSnakeCrushes();
		}
	}
}

bool Game::checkIfSnakeCrushes() {
	for (int i = 0; i < 100; ++i) {
		if (snake->body->at(0) == wall->body[i]) {
			return true;
		}
	}
	return false;
}

int main()
{
	Game *game = new Game();
	game->play();
	delete game;
	return 0;
}