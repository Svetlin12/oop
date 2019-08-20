#include "NPC.h"

NPC::NPC() : Entity()
{
}

NPC::NPC(const std::string name, const Point2D * location) : Entity(name, location)
{
}

NPC::NPC(const NPC & n)
{
	setName(n.getName());
	setLocation(n.getLocation());
	this->entityType = n.getEntityType();
}

NPC::~NPC()
{
}

NPC * NPC::clone() const
{
	return new NPC(*this);
}

bool NPC::isAlive() const
{
	return true;
}

const type NPC::getEntityType() const
{
	return this->entityType;
}

void NPC::print() const
{
	std::cout << "---NPC---" << std::endl;
	Entity::print();
	std::cout << "---------" << std::endl;
}
