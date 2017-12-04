#pragma once
#include "stdafx.h"
#include "Item.h"
//template <typename T>
class Tree
{
public:
	Item *root;
	Tree() {
		root = NULL;
	}
	~Tree() {

	}
	void add(const int &value, Item *temp)
	{
		if (temp == NULL) {
			temp = new Item(value);
		}
		else {
			if (temp->value < value) {
				if (temp->right == NULL) {
					temp->right = new Item(value);
				}
				else {
					add(value, temp->right);
				}
			}
			else if (temp->value >= value) {
				if (temp->left == NULL) {
					temp->left = new Item(value);
				}
				else {
					add(value, temp->left);
				}
			}
		}
	}
	void show(Item *temp)
	{
		{
			if (temp != NULL) {
				std::cout << temp->value << std::endl;
				show(temp->left);
				show(temp->right);
			}
		}
	}
};
