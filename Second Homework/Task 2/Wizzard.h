#pragma once
#include "GameCharacter.h"

class Wizzard : public GameCharacter
{
public:

	Wizzard();
	~Wizzard();

	void getAttacked(int enemyAP);

	void print() const;

};