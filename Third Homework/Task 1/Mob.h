#pragma once
#include "Player.h"

class Mob : public Entity
{
private:

	int damage;
	int health;
	type entityType = type::Mob;

public:

	Mob();
	Mob(const std::string name, const Point2D* location, const int damage, const int health);
	Mob(const Mob& m);
	virtual ~Mob();

	const type getEntityType() const override;

	Mob* clone() const override;

	const int getDamage() const;
	const int getHealth() const;

	void setDamage(const int damage);
	void setHealth(const int health);

	bool isAlive() const;
	void attack(Entity* e);

	void print() const override;
};