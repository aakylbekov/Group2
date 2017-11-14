#pragma once

class Wall
{
	Point * wall;
	char *sign;
public:
	Wall() {
		sign = new char('#');
		wall = new Point[100];
		for (int i = 0; i < 25; ++i) {
			wall[i] = *(new Point(i, 0));
			wall[i + 25] = *(new Point(0, i));
			wall[i + 50] = *(new Point(25, i));
			wall[i + 75] = *(new Point(i, 25));
		}
	}
	void draw() {
		for (int i = 0; i < 100; ++i) {
			wall[i].draw(*sign);
		}
	}

	~Wall(){
		delete[] wall;
		delete sign;
	}
};