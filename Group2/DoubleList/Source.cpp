// DoubleList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
	DoubleLinkedList<int> *a = new DoubleLinkedList<int>();
	delete a;
	system("pause");
    return 0;
}
