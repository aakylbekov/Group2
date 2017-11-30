#pragma once
#include "Node.h"
// описание класса двусвязный список и 
// прототипы его функции

template <class T>
class DoubleLinkedList
{
public:
	Node *first, *last;
	//пустой конструктор для создания двусвязного списка
	DoubleLinkedList();
	~DoubleLinkedList();
	void addToLast(const T &);
	void addToFirst(const T &);
	void show();
};
