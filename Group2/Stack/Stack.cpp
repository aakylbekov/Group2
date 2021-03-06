// Stack.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Stack.h"
template <typename T>
Stack<T>::Stack() {
	stack = new T[size];
	top = 0;
}
template <typename T>
Stack<T>::~Stack() {
	delete[] stack;
}
template <typename T>
void Stack<T>::push(const T &t) {
	if (top + 1 <= size) {
		stack[++top] = t;
	}
}
template <typename T>
T Stack<T>::pop() {
	if (top > 0) {
		top--;
	}
	return stack[top + 1];
}



