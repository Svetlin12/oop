#pragma once
#include "Mob.h"
#include "Player.h"
#include "NPC.h"
#include <vector>

using namespace std;

class Environment
{
private:

	vector<Entity*> entities;

	//vector that contains 0s and 1s 
	//for each entity that is in entities corrresponds a bool in entitiesChecker that is initially set to 1(true)
	//this vector is used when the player attacks the entities with the function attackAllOfType()
	vector<bool> entitiesChecker;

public:

	Environment();
	Environment(const Environment& e);
	Environment& operator=(const Environment& e);
	~Environment();

	//function that allows an object of type Player to attack all entities of the type given from the vector entities
	void attackAllOfType(Player& p, type type);

	void add(Entity* e);
	Entity* getAt(int index);
	void removeAt(int index);
	void generateEntities();
	void destroyEntities();

	Entity* getClosestAliveEntity(Player& p, type type);

	void print() const;
};