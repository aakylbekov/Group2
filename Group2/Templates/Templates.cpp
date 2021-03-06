// Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

//шаблонная функция
//template <class T>
//template <typename T>

template <typename T>
T getAverageOfArrayElements(T a[], int size) {
	if (size < 1) {
		cout << "array is empty!" << endl;
	}
	T sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += a[i];
	}
	return sum / size;
}
char getAverageOfArrayElements(char a[], int size) {
	if (size < 1) {
		cout << "array is empty!" << endl;
	}
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += (int)a[i];
	}
	return (char)(sum / size);
}

template <typename T>
T getMinimumOfArrayElements(T a[], int size) {
	if (size < 1) {
		cout << "array is empty!" << endl;
	}
	T min = a[0];
	for (int i = 1; i < size; ++i) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}
template <typename T>
void quicksort(T* a, int low, int high) {
	int i = low, j = high;
	T pivot = a[(low + high) / 2];

	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	};

	if (low < j)
		quicksort(a, low, j);
	if (i < high)
		quicksort(a, i, high);
}
template <typename T>
int search(T* a, const int& size, T t) {

}

void f1() {
	int a[5] = { 2, 1, 4, 3, 5 };
	double b[5] = { 6., 7., 8., 9., 10. };
	float c[5] = { 11., 12., 13., 14., 15. };
	char d[5] = { 'a', 'b', 'c', 'd', 'e' };
	/*cout << getAverageOfArrayElements(a, 5) << endl;
	cout << getAverageOfArrayElements(b, 5) << endl;
	cout << getAverageOfArrayElements(c, 5) << endl;*/
	cout << getAverageOfArrayElements(d, 5) << endl;
	/*int size = 5;
	quicksort(a, 0, size - 1);
	for (int i = 0; i < 5; ++i) {
		cout << a[i] << endl;
	}*/
}
int main()
{
	f1();
	system("pause");
	return 0;
}
