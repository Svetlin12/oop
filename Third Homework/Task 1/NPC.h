#pragma once
#include "Mob.h"

class NPC : public Entity
{
private:

	type entityType = type::NPC;

public:

	NPC();
	NPC(const std::string name, const Point2D* location);
	NPC(const NPC& n);
	virtual ~NPC();

	NPC* clone() const override;

	bool isAlive() const override;
	const type getEntityType() const override;

	void print() const override;
};