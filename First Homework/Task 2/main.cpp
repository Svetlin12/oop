#include <iostream>
#include "DNSCache.h"

using namespace std;

int main()
{
	DNSRecord d1, d2("dir.bg", "89.85.43.21.100"), d3;
	d3 = d2;
	d1.setDomainName("abv.bg");
	d1.setIpAddress("77.00.85.43.111");
	
	DNSCache d;
	d.add(d1);
	d.add(d2);
	d.add(d3);

	cout << "Inside cache d: " << endl;
	d.print();

	char* find1 = d.lookup("abv.bg");
	char* find2 = d.lookup("something.com");
	char* find3 = d.lookup("dir.bg");

	if (find1 == nullptr)
	{
		cout << "Result of find1: find1 is nullptr" << endl;
		delete[] find1;
	}
	else
	{
		cout << "Result of find1: " << find1 << endl;
	}

	if (find2 == nullptr)
	{
		cout << "Result of find2: find2 is nullptr" << endl;
		delete[] find2;
	}
	else
	{
		cout << "Result of find2: " << find2 << endl;
	}

	if (find3 == nullptr)
	{
		cout << "Result of find3: find3 is nullptr" << endl;
		delete[] find3;
	}
	else
	{
		cout << "Result of find3: " << find3 << endl << endl;
	}

	DNSCache p;
	p = d;

	cout << "Inside cache p: " << endl;
	p.print();
	p.flush();

	cout << "After flushing p: " << endl;
	p.print();

	cout << "d remains the same: " << endl;
	d.print();
	
	int x;
	cin >> x;
}