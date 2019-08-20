#include "Guardian.h"

Guardian::Guardian() : GameCharacter("Guardian", 40, 25, 1, 3)
{
}

Guardian::~Guardian()
{
}

void Guardian::getAttacked(int enemyAP)
{
	int damage = enemyAP - 3;
	cout << "Guardian: ";
	if (damage <= 0)
	{
		cout << "No damage taken" << endl;
	}
	else
	{
		cout << damage << " damage taken" << endl;
		int hp = getHP();
		setHP(hp -= damage);
	}
}

void Guardian::print() const
{
	cout << "----Guardian----" << endl;
	cout << "HP: " << getHP() << endl;
	cout << "MP: " << getMP() << endl;
	cout << "AP: " << getAP() << endl;
	cout << "DP: " << getDP() << endl;
	cout << "----------------" << endl;
}
