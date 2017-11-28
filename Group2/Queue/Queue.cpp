// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
template<typename T>
class Queue
{
	T *queue;
	const int size = 1048576;
	int first, last, cnt;
public:
	Queue();
	~Queue();
	void enqueue(const T &);
	T dequeue();
};
template <typename T>
Queue<T>::Queue() {
	queue = new T[size];
	first = last = cnt = 0;
}
template <typename T>
Queue<T>::~Queue() {
	delete[] queue;
}
template <typename T>
void Queue<T>::enqueue(const T &t) {
	if (cnt < size) {
		queue[last++] = t;
		++cnt;
		if (last > size) {
			last -= size + 1;
		}
	}
}
template <typename T>
T Queue<T>::dequeue() {
	if (cnt > 0) {
		T temp = queue[first++];
		--cnt;
		if (first > size) {
			first -= size + 1;
		}
		return temp;
	}
}
int main()
{
	return 0;
}

