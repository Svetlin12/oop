#include "Admin.h"

void Admin::changeUsername(const char* newUsername, User& u)
{
		u.setUsername(newUsername);
}

Admin::Admin() : VIP(), PowerUser()
{
}

Admin::~Admin()
{
}

Admin::Admin(const char* username, const char* password, const char* title, const char* ipAddress, int reputation) :
	User(username, password, title, ipAddress), PowerUser(username, password, title, ipAddress, reputation)
{
}

Admin::Admin(const Admin & a) : PowerUser(a)
{
	setUsername(a.getUsername());
	setTitle(a.getTitle());
	setIp(a.getIp());
	changePassword(a.getPassword(), getPassword());
	toEncrypt();
}

Admin & Admin::operator=(const Admin & a)
{
	if (this != &a)
	{
		VIP::operator=(a);
		PowerUser::operator=(a);
	}
	return *this;
}

void Admin::changeAUsername(const char * username)
{
	setUsername(username);
}

void Admin::changeATitle(const char * title)
{
	setTitle(title);
}

void Admin::changeOtherUsername(User & u, const char * username)
{
	changeUsername(username, u);
}

void Admin::print() const
{
	std::cout << "---Admin---" << std::endl;
	std::cout << "Username: " << getUsername() << std::endl;
	std::cout << "Reputation: " << getReputation() << std::endl;
	std::cout << "Title: " << getTitle() << std::endl;
	std::cout << "Password: " << getPassword() << std::endl;
	std::cout << "IpAddress: " << getIp() << std::endl;
	std::cout << "-----------\n" << std::endl;
}
