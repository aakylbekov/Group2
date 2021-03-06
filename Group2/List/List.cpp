// List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

template <typename T>
class Element {
	//значение элемента
	T value;
	//указатель на следующий элемент
	Element<T> *next;
	Element(T);
	~Element();
};
template <typename T>
Element<T>::Element(T value) {
	this->value = value;
	next = NULL;
}
template <typename T>
Element<T>::~Element() {
	delete next;
}

template <typename T>
class List {
	void addToElements(Element<T>, const T &);
	Element<T> *first;
public:
	List();
	~List();
	void addToLast(const T &);
};
template <typename T>
List<T>::List() {
	first = NULL;
}
template <typename T>
List<T>::~List() {
	delete first;
}
template <typename T>
void List<T>::addToLast(const T &t) {
	if (first == NULL) {
		first = new Element(t);
	}
	else {
		addToElements(first->next, t);
	}
}
template <typename T>
void List<T>::addToElements(Element<T> element, 
	const T &t) {
	if (element == NULL) {
		element = new Element(t);
	}
	else {
		addToElements(element->next, t);
	}
}
int main()
{
	return 0;
}

