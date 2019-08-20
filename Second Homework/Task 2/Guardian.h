#pragma once
#include "GameCharacter.h"

class Guardian : public GameCharacter
{
public:

	Guardian();
	~Guardian();

	void getAttacked(int enemyAP);

	void print() const;
};