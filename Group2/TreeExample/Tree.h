#pragma once
#include "Item.h"
template <typename T>
class Tree
{
public:
	Item<T> *root;
	Tree() {
		root = NULL;
	}
	~Tree() {

	}
	void add(const T &value, Item<T> &temp)
	{
		if (temp == NULL) {
			temp = new Item<T>(value);
		}
		else {
			if (temp.value < value) {
				if (temp.right == NULL) {
					temp.right = new Item<T>(value);
				}
				else {
					add(value, temp.right);
				}
			}
			else if (temp.value >= value) {
				if (temp.left == NULL) {
					temp.left = new Item<T>(value);
				}
				else {
					add(value, temp.left);
				}
			}
		}
	}
	void show(Item<T> temp)
	{
		{
			if (temp != NULL) {
				cout << temp.value << endl;
				show(*temp.left);
				show(*temp.right);
			}
		}
	}
};
