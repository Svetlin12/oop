#include <iostream>
#include "IntStack.h"

using namespace std;

int main()
{
	cout << "First stack:" << endl;
	IntStack stack;
	stack.push(3);
	stack.push(4);
	stack.push(10);
	stack.push(1);
	stack.push(-1);
	stack.print();

	cout << endl << "The top element of the first stack:" << endl;
	cout << stack.peek() << endl << endl;

	IntStack stack1 = stack;
	cout << "Second stack:" << endl;
	stack1.print();
	
	cout << endl << "Sorted first stack: " << endl;
	sortStack(stack);
	stack.print();

	cout << endl << "No change made to the second stack whatsoever:" << endl;
	stack1.print();

	cout << endl;
	stack1.pop();

	cout << "Second stack after its first element has been removed: " << endl;
	stack1.print();

	cout << endl << "The top element of second stack:" << endl;
	cout << stack1.peek() << endl;

	int x;
	cin >> x;

	return 0;
}