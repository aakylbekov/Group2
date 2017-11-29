#include "stdafx.h"
#include "Node.h"

template <typename T>
Node<T>::Node()
{
}

template<typename T>
Node<T>::Node(const T &value)
{
	this->value = value;
	prev = next = NULL;
}

template <typename T>
Node<T>::~Node()
{
}
