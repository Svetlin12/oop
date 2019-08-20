#include "Users.h"

void Users::increaseSize()
{
	this->size++;
}

int Users::getSize() const
{
	return this->size;
}

//function to check whether the given user has been already added in the container or not
bool Users::searchUser(const User & u) const
{
	for (int i = 0; i < getSize(); i++)
	{
		if (strcmp(u.getIp(), users[i]->getIp()) == 0)
		{
			return true;
		}
	}
	return false;
}

//adds another eleemnt to the container
void Users::addUser(User * u)
{
	users[getSize()] = u;
	increaseSize();
}
