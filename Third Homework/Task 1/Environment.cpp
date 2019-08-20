#include "Environment.h"

Environment::Environment()
{
}

Environment::Environment(const Environment & e) : entities(e.entities.size()), entitiesChecker(e.entitiesChecker.size())
{
	for (unsigned int i = 0; i < e.entities.size(); i++)
	{
		this->entities[i] = e.entities[i]->clone();
	}
	for (unsigned int i = 0; i < e.entitiesChecker.size(); i++)
	{
		this->entitiesChecker[i] = e.entitiesChecker[i];
	}
}

Environment & Environment::operator=(const Environment & e)
{
	if (this != &e)
	{
		for (unsigned int i = 0; i < entities.size(); i++)
		{
			delete (entities[i]);
		}
		entities.clear();
		entitiesChecker.clear();

		entities.resize(e.entities.size());

		for (unsigned int i = 0; i < e.entities.size(); i++)
		{
			this->entities[i] = e.entities[i]->clone();
		}
		entitiesChecker = e.entitiesChecker;
	}
	return *this;
}

//destructor for Environment
Environment::~Environment()
{
	destroyEntities();
}

//first we set all of the bools that correspond to the entities of the type given to 1 because we are not sure
//if the user has used the function getClosestAliveEntity() before the call of attackAllOfType
//then we go through the vector and whenever it finds an entity of the type given it calls the function 
//getClosestAliveEntity() and attacks him...this way every time it will attack a different mob but also it will
//attack all mobs
//order of attack - from the closest to the furthest
void Environment::attackAllOfType(Player & p, type type)
{
	if (type == type::NPC) 
	{
		cout << "You can't attack an NPC!" << endl;
		return;
	}

	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getEntityType() == type)
		{
			entitiesChecker[i] = 1;
		}
	}

	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getEntityType() == type)
		{
			p.attack(getClosestAliveEntity(p, type));
		}
	}

	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getEntityType() == type)
		{				
			entitiesChecker[i] = 1;
		}
	}
}

void Environment::add(Entity * e)
{
	entities.push_back(e);
	entitiesChecker.push_back(1);
}

Entity * Environment::getAt(int index)
{
	if (index >= entities.size()) return NULL;
	if (index < 0) return NULL;

	return entities[index];
}

void Environment::removeAt(int index)
{
	if (index >= entities.size()) return;
	if (index < 0) return;

	delete entities[index];
	entities.erase(entities.begin() + index);
}

void Environment::generateEntities()
{
	Point2D* location1 = new Point2D(10, 20);
	Point2D* location2 = new Point2D(4, 16);
	Point2D* location3 = new Point2D(8, 3);
	Point2D* location4 = new Point3D(1, 5, 10);
	Point2D* location5 = new Point3D(5, 0, 12);
	Point2D* location6 = new Point3D(10, 5, 1);

	Entity* e1 = new Player("swordsman", location1, 3, 20);
	Entity* e2 = new Player("archer", location2, 4, 25);
	Entity* e3 = new Mob("giant", location3, 10, 50);
	Entity* e4 = new Mob("goblin", location4, 6, 40);
	Entity* e5 = new NPC("Sam", location5);
	Entity* e6 = new NPC("John", location6);
	entities.push_back(e1);
	entities.push_back(e2);
	entities.push_back(e3);
	entities.push_back(e4);
	entities.push_back(e5);
	entities.push_back(e6);

	entitiesChecker.push_back(1);
	entitiesChecker.push_back(1);
	entitiesChecker.push_back(1);
	entitiesChecker.push_back(1);
	entitiesChecker.push_back(1);
	entitiesChecker.push_back(1);
}

//we go through the vector and delete each pointer (Entity*) inside and then clear the vector
//then we clear the other vector of bools
void Environment::destroyEntities()
{
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		delete (entities[i]);
	}
	entities.clear();

	entitiesChecker.clear();
}

//the logic is simple - we create a double to store the min distance between the player and an entity of the given type
//then we go through the vector entities to compare the distances between the entities of the same type that is given and
//the player and each time there is a lower distance than the one we have stored in minDistance we assign it to 
//minDistance (note that we do that only if the bool in entitiesChecker corresponding to that entity is 1)
//and then it is simple - go through the vector again and return the entity that has the same distance between
//the player and itself and is of the same type as the given one (note that before we do that we assign the bool
//inside entityChecker corresponding to that entity to 0 because we don't want to get the same entity over and over
//again)
Entity * Environment::getClosestAliveEntity(Player& p, type type)
{
	if (type == type::NPC) return NULL;

	double minDistance = -1;
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getEntityType() == type && entitiesChecker[i] == 1)
		{
			minDistance = entities[i]->getDistanceTo(p);
			break;
		}
	}

	if (minDistance == -1)
	{
		return NULL;
	}

	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->getEntityType() == type && entitiesChecker[i] == 1)
		{
			if (minDistance < entities[i]->getDistanceTo(p) && entities[i]->isAlive())
			{
				minDistance = entities[i]->getDistanceTo(p);
			}
		}
	}

	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (minDistance == entities[i]->getDistanceTo(p) && entities[i]->getEntityType() == type && entitiesChecker[i] == 1)
		{
			entitiesChecker[i] = 0;
			return entities[i];
		}
	}
}

void Environment::print() const
{
	if (entities.empty())
	{
		cout << "The vector is empty!" << endl;
	}
	else
	{
		for (unsigned int i = 0; i < entities.size(); i++)
		{
			entities[i]->print();
			cout << endl;
		}
	}
}
