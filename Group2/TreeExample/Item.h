#pragma once
template <typename T>
class Item
{
public:
	T value;
	Item<T> *left, *right;
	Item();
	~Item();
};

