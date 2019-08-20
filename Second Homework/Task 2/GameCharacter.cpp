#include "GameCharacter.h"

GameCharacter::GameCharacter(const char * name, int HP, int MP, int AP, int DP)
{
	setName(name);
	setHP(HP);
	setMP(MP);
	setAP(AP);
	setDP(DP);
}

GameCharacter::~GameCharacter()
{
	delete[] this->name;
}

void GameCharacter::setName(const char * name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

const char * GameCharacter::getName() const
{
	return this->name;
}

void GameCharacter::setHP(int HP)
{
	this->HP = HP;
}

int GameCharacter::getHP() const
{
	return this->HP;
}

void GameCharacter::setMP(int MP)
{
	this->MP = MP;
}

int GameCharacter::getMP() const
{
	return this->MP;
}

void GameCharacter::setAP(int AP)
{
	this->AP = AP;
}

int GameCharacter::getAP() const
{
	return this->AP;
}

void GameCharacter::setDP(int DP)
{
	this->DP = DP;
}

int GameCharacter::getDP() const
{
	return this->DP;
}
