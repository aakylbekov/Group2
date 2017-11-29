#pragma once
#include "Node.h"
// описание класса двусвязный список и 
// прототипы его функции

template <class T>
class DoubleLinkedList
{
public:
	Node<T> *first, *last;
	//пустой конструктор для создания двусвязного списка
	DoubleLinkedList();
	~DoubleLinkedList();
	template<class T> void addToLast(const T &);
	template<class T> void addToFirst(const T &);
	//template<typename T> void show();
};
