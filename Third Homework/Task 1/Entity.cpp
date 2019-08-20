#include "Entity.h"

int Entity::uniqueID = 0;

void Entity::setId()
{
	this->id = uniqueID;
	increaseUniqueID();
}

void Entity::increaseUniqueID()
{
	this->uniqueID++;
}

void Entity::copyId(int id)
{
	this->id = id;
}

Entity::Entity()
{
	setId();
	setName("Default");
	this->location = new Point2D;
}

Entity::Entity(const std::string name, const Point2D * location)
{
	setId();
	setName(name);
	setLocation(location);
}

Entity::Entity(const Entity & e)
{
	copyId(e.getId());
	setName(e.getName());
	setLocation(e.getLocation());
}

Entity & Entity::operator=(const Entity & e)
{
	if (this != &e)
	{
		copyId(e.getId());
		setName(e.getName());
		setLocation(e.getLocation());
	}
	return *this;
}

Entity::~Entity()
{
	delete this->location;
}

const int Entity::getId() const
{
	return this->id;
}

const std::string Entity::getName() const
{
	return this->name;
}

void Entity::setName(const std::string name)
{
	this->name = name;
}

Point2D * Entity::getLocation() const
{
	return this->location;
}

void Entity::setLocation(const Point2D * p)
{
	if (p->getType() == "Point2D")
	{
		delete this->location;
		this->location = new Point2D;
		this->location = p->clone();
	}
	else
	{
		delete this->location;
		this->location = new Point3D;
		this->location = p->clone();
	}
}

bool Entity::isAlive() const
{
	return true;
}

double Entity::getDistanceTo2D(const Entity & e)
{
	return location->getDistanceTo(e.getLocation());
}

double Entity::getDistanceTo(const Entity & e)
{
	if (e.getLocation()->getType() == "Point3D" && getLocation()->getType() == "Point3D")
	{
		return location->getDistanceTo(e.getLocation());
	}
	else if (e.getLocation()->getType() == "Point2D")
	{
		return e.getLocation()->getDistanceTo(getLocation());
	}
	else if (e.getLocation()->getType() == "Point3D")
	{
		return getLocation()->getDistanceTo(e.getLocation());
	}
}

void Entity::moveTo(Point2D * location)
{
	if (this->location->getType() == "Point3D" && location->getType() == "Point3D")
	{
		this->location->setX(location->getX());
		this->location->setY(location->getY());
		dynamic_cast<Point3D*>(this->location)->setZ(dynamic_cast<Point3D*>(location)->getZ());
	}
	else if (this->location->getType() == "Point3D" && location->getType() == "Point2D")
	{
		this->location->setX(location->getX());
		this->location->setY(location->getY());
	}
	else if (this->location->getType() == "Point2D" && location->getType() == "Point3D")
	{
		this->location->setX(location->getX());
		this->location->setY(location->getY());
	}
	else
	{
		this->location->setX(location->getX());
		this->location->setY(location->getY());
	}
}

void Entity::moveTo(const Entity & e)
{
	if (e.getLocation()->getType() == "Point3D" && getLocation()->getType() == "Point3D")
	{
		this->location->setX(e.getLocation()->getX());
		this->location->setY(e.getLocation()->getY());
		dynamic_cast<Point3D*>(this->location)->setZ(dynamic_cast<Point3D*>(e.getLocation())->getZ());
	}
	else if (e.getLocation()->getType() == "Point2D" && getLocation()->getType() == "Point2D")
	{
		this->location->setX(e.getLocation()->getX());
		this->location->setY(e.getLocation()->getY());
	}
	else if (e.getLocation()->getType() == "Point2D")
	{
		delete[] this->location;
		this->location = new Point2D;
		this->location->setX(e.getLocation()->getX());
		this->location->setY(e.getLocation()->getY());
	}
	else
	{
		delete[] this->location;
		this->location = new Point3D;
		this->location->setX(e.getLocation()->getX());
		this->location->setY(e.getLocation()->getY());
		dynamic_cast<Point3D*>(this->location)->setZ(dynamic_cast<Point3D*>(e.getLocation())->getZ());
	}
}

void Entity::print() const
{
	std::cout << "ID: " << getId() << std::endl;
	std::cout << "Name: " << getName() << std::endl;
	getLocation()->print();
}
