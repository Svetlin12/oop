#include "Wizzard.h"

Wizzard::Wizzard() : GameCharacter("Wizard", 30, 30, 2, 2)
{
}

Wizzard::~Wizzard()
{
}

void Wizzard::getAttacked(int enemyAP)
{
	int damage = enemyAP - 2;
	cout << "Wizzard: ";
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

void Wizzard::print() const
{
	cout << "----Wizzard----" << endl;
	cout << "HP: " << getHP() << endl;
	cout << "MP: " << getMP() << endl;
	cout << "AP: " << getAP() << endl;
	cout << "DP: " << getDP() << endl;
	cout << "---------------" << endl;
}
