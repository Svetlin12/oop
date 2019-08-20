#pragma once
#include <string.h>
#include <iostream>

using namespace std;

class GameCharacter
{
private:

	char* name = nullptr;
	int HP;
	int MP;
	int AP;
	int DP;

public:

	GameCharacter(const char* name, int HP, int MP, int AP, int DP);
	virtual ~GameCharacter();

	void setName(const char* name);
	const char* getName() const;

	void setHP(int HP);
	int getHP() const;

	void setMP(int MP);
	int getMP() const;

	void setAP(int AP);
	int getAP() const;

	void setDP(int DP);
	int getDP() const;

	//these two functions below make the class an abstract one meaning that there can't be any instances of it
	//that are created
	virtual void getAttacked(int enemyAP) = 0;

	virtual void print() const = 0;
};