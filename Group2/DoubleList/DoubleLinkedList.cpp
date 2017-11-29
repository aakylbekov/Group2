#include "stdafx.h"
#include "DoubleLinkedList.h"

// реализация функции класса двусвязный список

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	first = last = NULL;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
}

template<typename T>
void DoubleLinkedList<T>::add(const T &value)
{
	if (first == NULL) {
		last = first = new Node<T>(value);
	}
	else {
		last->next = new Node<T>(value);
		last = last->next;
	}
}
