// TreeExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"

using namespace std;

int main()
{
	srand(time(NULL));
	Tree tree;
	tree.add(10, tree.root);
	for (size_t i = 0; i < 20; ++i) {
		tree.add(rand() % 100, tree.root);
	}
	tree.show(tree.root);
	system("pause");
	return 0;
}

