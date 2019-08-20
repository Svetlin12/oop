#include "GameCharacter.h"
#include "Guardian.h"
#include "Warrior.h"
#include "Wizzard.h"

int main()
{
	Guardian g;
	Warrior w;
	Wizzard wi;

	cout << "The initial characters: " << endl;
	g.print();
	cout << endl;
	w.print();
	cout << endl;
	wi.print();
	cout << endl;

	g.getAttacked(w.getAP());
	g.print();
	cout << endl;

	w.getAttacked(wi.getAP());
	w.print();
	cout << endl;

	wi.getAttacked(g.getAP());
	wi.print();
	cout << endl;

	g.getAttacked(wi.getAP());
	g.print();
	cout << endl;

	GameCharacter* gc = new Warrior;
	gc->print();
	cout << endl;

	delete gc;

	cin.get();
	return 0;
}