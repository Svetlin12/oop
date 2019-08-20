#include "MagicBox.h"

int main()
{
	MagicBox<char> m1;
	MagicBox<int> m2;
	MagicBox<double> m3;

	//filling m1 with the first 10 capital letters from the English alphabet
	for (int i = 65; i < 75; i++)
	{
		m1.insert(i);
	}

	//filling m2 with numbers 0 to 4
	for (int i = 0; i < 5; i++)
	{
		m2.insert(i);
	}

	//filling m3 just with the number 4
	m3.insert(4);

	//displaying each magic box
	m1.list();
	cout << endl;
	m2.list();
	cout << endl;
	m3.list();
	cout << endl;

	//popping m3's elements until there are no such
	//expected result: the console will output that there aren't any elements to remove after the first pop
	m3.pop(rand() % (m3.getSize() + 1) + 0);
	m3.pop(rand() % (m3.getSize() + 1) + 0);
	cout << endl;

	//popping one element from m2
	m2.pop(rand() % (m2.getSize() + 1) + 0);
	m2.list();
	cout << endl;

	//popping two elements from m1
	m1.pop(rand() % (m1.getSize() + 1) + 0);
	m1.pop(rand() % (m1.getSize() + 1) + 0);
	m1.list();
	cout << endl;

	//using the copy constructor and the = operator in order to test them
	MagicBox<char> m4 = m1;
	MagicBox<int> m5;
	m5 = m2;

	m4.list();
	cout << endl;

	m5.list();
	cout << endl;

	cin.get();
	return 0;
}