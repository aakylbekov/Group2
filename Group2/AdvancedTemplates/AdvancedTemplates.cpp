// AdvancedTemplates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
template <typename T>
class Matrix {
public:
	T **arr;
	int height, width;
	Matrix(int height, int width) {
		this->height = height;
		this->width = width;
		arr = new T*[width];
		for (int i = 0; i < width; ++i) {
			arr[i] = new T[height];
		}
	}
	~Matrix() {
		for (int i = 0; i < width; ++i) {
			delete arr[i];
		}
		delete arr;
	}
	void print();
	void random() {
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height; ++j) {
				arr[i][j] = rand() % 100;
			}
		}
	}
	//friend Matrix<T> & random(T **t);
};
//template <typename T>
//T** random(T **t) {
//	srand(time(NULL));
//	for (int i = 0; i < t->width; ++i) {
//		for (int j = 0; j < t->height; ++j) {
//			arr[i][j] = rand() % 100;
//		}
//	}
//	return t;
//}
template <typename T>
void Matrix<T>::print() {
	for (int i = 0; i < width; ++i) {
		for (int j = 0; j < height; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
//template <typename T1, typename T2>
//auto sum(T1 t1, T2 t2) {
//	return t1 + t2;
//}
//void f1() {
//	//auto определяет сам тип переменной
//	auto x = 123;
//	//объявить переменную y с таким же типом что и x
//	decltype(x) y = 5;
//}

int main() {
	int x, y;
	cin >> x >> y;
	Matrix<int> *a = new Matrix<int>(x, y);
	//a->arr = random(a->arr);
	srand(time(NULL));
	a->random();
	a->print();
	delete a;
	system("pause");
	return 0;
}
