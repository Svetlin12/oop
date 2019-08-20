#include "Player.h"
#include "Mob.h"

Player::Player() : Entity()
{
	setDamage(0);
	setHealth(0);
}

Player::Player(const std::string name, const Point2D * location, const int damage, const int health) :
	Entity(name, location)
{
	setDamage(damage);
	setHealth(health);
}

Player::Player(const Player & p)
{
	setName(p.getName());
	setDamage(p.getDamage());
	setHealth(p.getHealth());
	setLocation(p.getLocation());
	this->entityType = p.getEntityType();
}

Player& Player::operator=(const Player & p)
{
	if (this != &p)
	{
		setDamage(p.getDamage());
		setHealth(p.getHealth());
	}
	return *this;
}

Player::~Player()
{
}

Player * Player::clone() const
{
	return new Player(*this);
}

const type Player::getEntityType() const
{
	return this->entityType;
}

const int Player::getDamage() const
{
	return this->damage;
}

const int Player::getHealth() const
{
	return this->health;
}

void Player::setDamage(const int damage)
{
	this->damage = damage;
}

void Player::setHealth(const int health)
{
	this->health = health;
}

bool Player::isAlive() const
{
	return getHealth() > 0;
}

void Player::attack(Entity * e)
{
	if (e->getEntityType() == type::Player)
	{
		if (getDistanceTo(*e) < 5)
		{
			std::cout << getName() << " attacked " << e->getName() << "! " << getDamage() 
				<< " damage taken." << std::endl;
			dynamic_cast<Player*>(e)->setHealth(dynamic_cast<Player*>(e)->getHealth() - getDamage());
		}
		else
		{
			std::cout << "Enemy player " << e->getName() << " is too far away from you to attack him!" << std::endl;
		}
	}
	else if (e->getEntityType() == type::Mob)
	{
		if (getDistanceTo(*e) < 5)
		{
			std::cout << getName() << " attacked " << e->getName() << "! " << getDamage() 
				<< " damage taken." << std::endl;
			dynamic_cast<Mob*>(e)->setHealth(dynamic_cast<Mob*>(e)->getHealth() - getDamage());
		}
		else
		{
			std::cout << "Enemy mob " << e->getName() << " is too far away from you to attack him!" << std::endl;
		}
	}
}

void Player::print() const
{
	std::cout << "---Player---" << std::endl;
	Entity::print();
	std::cout << "Damage: " << getDamage() << std::endl;
	std::cout << "Health: " << getHealth() << std::endl;
	std::cout << "------------" << std::endl;
}
