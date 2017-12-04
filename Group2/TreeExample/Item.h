#pragma once
//template <typename T>
class Item
{
public:
	int value;
	Item *left, *right;
	Item();
	~Item();
	Item(const int &);
};

