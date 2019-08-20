#include <iostream>
#include "User.h"
#include "PowerUser.h"
#include "VIP.h"
#include "Admin.h"

using namespace std;

int main()
{
	User u("User1", "fgtr40596", "random topic", "10.101.22.34");
	PowerUser p("PowerUser1", "342fRf3", "another topic", "11.101.78.0", 5);
	PowerUser p1;
	p1.changePUsername("PowerUser2");

	//testing the default contructor
	p1.print();

	//testing the print functions of the respective classes
	u.print();
	p.print();

	VIP v;
	v.print();
	v.changeVUsername("VIP1");
	v.changeVTitle("title?");
	v.changePassword("random P1SSwor5634", v.getPassword());
	v.setIp("76.98.00.100");
	v.print();

	Admin a("Admin1", "3253465", "title", "27.98.87.20", 7);
	a.print();
	a.changePassword("test1", "egregw");
	a.print();

	//change other username test
	a.changeOtherUsername(v, "changedUsername");
	v.print();

	//copy constructor test
	Admin a1 = a;
	a1.print();

	//reputation tests
	p1.increaseReputation(a);
	p1.increaseReputation(u);
	p1.increaseReputation(p);
	p1.increaseReputation(v);
	p1.increaseReputation(p1);
	cout << endl;
	p1.print();

	a1.increaseReputation(a);
	a1.increaseReputation(u);
	a1.increaseReputation(a1);
	cout << endl;
	a1.print();
	a.print();

	cin.get();
	return 0;
}