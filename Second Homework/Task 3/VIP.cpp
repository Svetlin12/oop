#include "VIP.h"

VIP::VIP() : User()
{
}

VIP::~VIP()
{
}

VIP::VIP(const char* username, const char* password, const char* title, const char* ipAddress) :
	User(username, password, title, ipAddress)
{
}

VIP::VIP(const VIP & v) : User(v)
{
}

VIP & VIP::operator=(const VIP & v)
{
	if (this != &v)
	{
		User::operator=(v);
	}
	return *this;
}

void VIP::changeVUsername(const char * username)
{
	setUsername(username);
}

void VIP::changeVTitle(const char * title)
{
	setTitle(title);
}

void VIP::print() const
{
	std::cout << "---VIP---" << std::endl;
	std::cout << "Username: " << getUsername() << std::endl;
	std::cout << "Title: " << getTitle() << std::endl;
	std::cout << "Password: " << getPassword() << std::endl;
	std::cout << "IpAddress: " << getIp() << std::endl;
	std::cout << "---------\n" << std::endl;
}
