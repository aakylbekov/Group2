// DoubleList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
	DoubleLinkedList<int> *a = new DoubleLinkedList<int>();
	a->addToLast(5);
	a->addToLast(6);
	a->addToFirst(4);
	//a->show();
	delete a;
    return 0;
}

