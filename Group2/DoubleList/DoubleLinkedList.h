#pragma once
#include "Node.h"
// описание класса двусвязный список и 
// прототипы его функции

template <typename T>
class DoubleLinkedList
{
public:
	Node<T> *first, *last;
	//пустой конструктор для создания двусвязного списка
	DoubleLinkedList();
	~DoubleLinkedList();
	void add(const T &);
};
