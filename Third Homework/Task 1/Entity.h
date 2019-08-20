#pragma once
#include "Point2D.h"
#include "Point3D.h"

enum class type
{
	Player = 0, NPC, Mob
};

class Entity
{
private:

	static int uniqueID;
	int id;
	std::string name;
	Point2D* location = nullptr;

	void setId();
	void increaseUniqueID();
	void copyId(const int id);

public:

	Entity();
	Entity(const std::string name, const Point2D* location);
	Entity(const Entity& e);
	Entity& operator=(const Entity& e);
	virtual ~Entity();

	const int getId() const;
	virtual const type getEntityType() const = 0;

	const std::string getName() const;
	void setName(const std::string name);

	Point2D* getLocation() const;
	void setLocation(const Point2D* p);

	//function to prevent the sharing of memory when entity's derived classes are copied
	virtual Entity* clone() const = 0;

	virtual bool isAlive() const;
	double getDistanceTo2D(const Entity& e);
	double getDistanceTo(const Entity& e);

	void moveTo(Point2D* location);
	void moveTo(const Entity& e);

	virtual void print() const;
};