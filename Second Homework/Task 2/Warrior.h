#pragma once
#include "GameCharacter.h"

class Warrior : public GameCharacter
{
public:

	Warrior();
	~Warrior();

	void getAttacked(int enemyAP);

	void print() const;
};