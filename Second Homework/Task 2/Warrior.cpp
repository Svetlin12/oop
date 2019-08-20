#include "Warrior.h"

Warrior::Warrior() : GameCharacter("Warrior", 20, 5, 4, 1)
{
}

Warrior::~Warrior()
{
}

void Warrior::getAttacked(int enemyAP)
{
	int damage = enemyAP - 1;
	cout << "Warrior: ";
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

void Warrior::print() const
{
	cout << "----Warrior----" << endl;
	cout << "HP: " << getHP() << endl;
	cout << "MP: " << getMP() << endl;
	cout << "AP: " << getAP() << endl;
	cout << "DP: " << getDP() << endl;
	cout << "---------------" << endl;
}
