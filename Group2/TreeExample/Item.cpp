#include "stdafx.h"
#include "Item.h"

//template <typename T>
Item::Item()
{
	left = right = NULL;
}

//template <typename T>
Item::~Item()
{
}

//template<typename T>
Item::Item(const int &value) :Item()
{
	this->value = value;
}

template class Item<int>;