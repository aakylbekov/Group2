#pragma once
template <typename T>
class Stack {
	T *stack;
	const int size = 1048576;
	int top;
public:
	Stack();
	~Stack();
	void push(const T &);
	T pop();
};