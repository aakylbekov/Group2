// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

//шаблонная функция
//template <class T>

//template <typename T>

template <typename T>
T getAverageOfArrayElements(T a[], int size) {
	T sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += a[i];
	}
	return sum / size;
}


int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	double b[5] = { 6., 7., 8., 9., 10. };
	float c[5] = { 11., 12., 13., 14., 15. };
	char d[5] = { 'a', 'b', 'c', 'd', 'e' };
	cout << getAverageOfArrayElements(a, 5) << endl;
	cout << getAverageOfArrayElements(b, 5) << endl;
	cout << getAverageOfArrayElements(c, 5) << endl;
	cout << getAverageOfArrayElements(d, 5) << endl;
	system("pause");
	return 0;
}
