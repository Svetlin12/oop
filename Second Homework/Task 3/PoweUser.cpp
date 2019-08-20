#include "PowerUser.h"

void PowerUser::increaseReputation(User & u)
{
	if (container.getSize() == 0)
	{
		container.addUser(&*this); //always add the current PowerUser to compare his ID to potential copies 
		//of the same PowerUser
	}

	//checks if the given user has already been added
	bool doesUseralreadyExist = containerSearch(u);

	if (!doesUseralreadyExist)
	{
		this->reputation++;
		container.addUser(&u);
	}
	else
	{
		std::cout << "User already exists! You can't give another reputation!" << std::endl;
	}
}

//the function to search inside the container using the Users function searchUser
bool PowerUser::containerSearch(const User& u) const
{
	return container.searchUser(u);
}

PowerUser::PowerUser() : User()
{
}

PowerUser::PowerUser(const char * username, const char * password, const char * title, const char* ipAddress, int reputation) :
	User(username, password, title, ipAddress)
{
	setReputation(reputation);
}

PowerUser::PowerUser(const PowerUser & p) : User(p)
{
	setUsername(p.getUsername());
	setReputation(p.getReputation());
}

PowerUser & PowerUser::operator=(const PowerUser & p)
{
	if (this != &p)
	{
		User::operator=(p);
		setReputation(p.getReputation());
	}
	return *this;
}

PowerUser::~PowerUser()
{
}

void PowerUser::changePUsername(const char * username)
{
	setUsername(username);
}

void PowerUser::setReputation(int reputation)
{
	this->reputation = reputation;
}

int PowerUser::getReputation() const
{
	return this->reputation;
}

void PowerUser::print() const
{
	std::cout << "---PowerUser---" << std::endl;
	std::cout << "Username: " << getUsername() << std::endl;
	std::cout << "Reputation: " << getReputation() << std::endl;
	std::cout << "Title: " << getTitle() << std::endl;
	std::cout << "Password: " << getPassword() << std::endl;
	std::cout << "IpAddress: " << getIp() << std::endl;
	std::cout << "---------------\n" << std::endl;
}
