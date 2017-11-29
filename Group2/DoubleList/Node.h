#pragma once
template <typename T>
class Node
{
public:
	T value;
	Node<T> *prev, *next;
	Node();
	Node(const T &);
	~Node();
};
