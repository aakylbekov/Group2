#include "stdafx.h"
#include "Item.h"

template <typename T>
Item<T>::Item()
{
	left = right = NULL;
}

template <typename T>
Item<T>::~Item()
{
}

template<typename T>
Item<T>::Item(const T &value) :Item()
{
	this->value = value;
}
