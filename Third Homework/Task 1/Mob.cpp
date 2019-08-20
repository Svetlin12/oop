#include "Mob.h"
#include "Player.h"

Mob::Mob() : Entity()
{
	setHealth(0);
	setDamage(0);
}

Mob::Mob(const std::string name, const Point2D * location, const int damage, const int health) :
	Entity(name, location)
{
	setDamage(damage);
	setHealth(health);
}

Mob::Mob(const Mob & m)
{
	setName(m.getName());
	setDamage(m.getDamage());
	setHealth(m.getHealth());
	setLocation(m.getLocation());
	this->entityType = m.getEntityType();
}

Mob::~Mob()
{
}

const type Mob::getEntityType() const
{
	return this->entityType;
}

Mob * Mob::clone() const
{
	return new Mob(*this);
}

const int Mob::getDamage() const
{
	return this->damage;
}

const int Mob::getHealth() const
{
	return this->health;
}

void Mob::setDamage(const int damage)
{
	this->damage = damage;
}

void Mob::setHealth(const int health)
{
	this->health = health;
}

bool Mob::isAlive() const
{
	return getHealth() > 0;
}

void Mob::attack(Entity* e)
{
	if (getDistanceTo(*e) < 5)
	{
		dynamic_cast<Player*>(e)->setHealth(dynamic_cast<Player*>(e)->getHealth() - getDamage());
	}
}

void Mob::print() const
{
	std::cout << "---Mob---" << std::endl;
	Entity::print();
	std::cout << "Damage: " << getDamage() << std::endl;
	std::cout << "Health: " << getHealth() << std::endl;
	std::cout << "---------" << std::endl;
}
