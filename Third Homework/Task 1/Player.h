#pragma once
#include "Entity.h"

class Player : public Entity
{
private:

	int damage;
	int health;
	type entityType = type::Player;

public:

	Player();
	Player(const std::string name, const Point2D* location, const int damage, const int health);
	Player(const Player& p);
	Player& operator=(const Player& p);
	virtual ~Player();

	Player* clone() const override;

	virtual const type getEntityType() const override;

	const int getDamage() const;
	const int getHealth() const;

	void setDamage(const int damage);
	void setHealth(const int health);

	virtual bool isAlive() const override;
	void attack(Entity* e);

	void print() const override;
};