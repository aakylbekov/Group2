#include "stdafx.h"
#include "Stack.h"
using namespace std;
void stack() {
	Stack<int> stack;
	stack.push(20);
	stack.push(30);
	stack.push(50);
	stack.push(20);
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
}

int main() {

	return 0;
}