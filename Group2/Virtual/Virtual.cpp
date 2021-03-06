// Virtual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class A {
public:
	A() { cout << "A()" << endl; }
	virtual void say() {
		cout << "I'm A" << endl;
	}
	virtual ~A() { cout << "~A()" << endl; }
};
class B :public A {
public:
	void say() {
		cout << "I'm B" << endl;
	}
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
};
class IProgrammer {
public:
	IProgrammer() {}
	virtual void usePC() = 0;
	virtual string doReport() = 0;
};
class Worker :public IProgrammer {
	void usePC() {
		cout << "I use PC" << endl;
	}
	string doReport() {
		return "Job is done";
	}
};
//1. Требования - абстрактный класс
//2. Вы - наследующий класс

class List {
public:
	List() {}
	virtual ~List() {}
	virtual int remove() = 0;
	virtual void add(const int &) = 0;
};

class Stack :public List {
	int *stack;
	const int size = 1048576;
	int top;
public:
	Stack() {
		stack = new int[size];
		top = 0;
	}
	~Stack() {
		delete[] stack;
	}
	void push(const int &value) {
		if (top + 1 <= size) {
			stack[++top] = value;
		}
	}
	int pop() {
		if (top > 0) {
			top--;
		}
		return stack[top + 1];
	}
	void add(const int &value) {
		push(value);
	}
	int remove() {
		return pop();
	}
};

class Queue :public List
{
	int *queue;
	const int size = 1048576;
	int first, last, cnt;
public:
	Queue() {
		queue = new int[size];
		first = last = cnt = 0;
	}
	~Queue() {
		delete[] queue;
	}
	void enqueue(const int &value) {
		if (cnt < size) {
			queue[last++] = value;
			++cnt;
			if (last > size) {
				last -= size + 1;
			}
		}
	}
	int dequeue() {
		if (cnt > 0) {
			int temp = queue[first++];
			--cnt;
			if (first > size) {
				first -= size + 1;
			}
			return temp;
		}
	}
	int remove() {
		return dequeue();
	}
	void add(const int &value) {
		enqueue(value);
	}
};
int main()
{
	/*A **a = new A*[2];
	a[0] = new B();
	a[1] = new A();
	for (int i = 0; i < 2; i++) {
		a[i]->say();
	}*/
	/*A *b = new B();
	delete b;*/
	/*IProgrammer *a = new Worker();*/

	List *stack = new Stack();
	List *queue = new Queue();
	stack->add(1);
	stack->add(2);
	cout << stack->remove() << endl;
	cout << stack->remove() << endl;
	queue->add(1);
	queue->add(2);
	cout << queue->remove() << endl;
	cout << queue->remove() << endl;
	delete stack;
	delete queue;
	return 0;
}
