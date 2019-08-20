#include "Guest.h"

Guest::Guest()
{
	setIp("Default");
}

Guest::Guest(const char * ipAddress)
{
	setIp(ipAddress);
}

Guest::Guest(const Guest & g)
{
	setIp(g.getIp());
}

Guest::~Guest()
{
	delete[] this->ipAddress;
}

Guest & Guest::operator=(const Guest & g)
{
	if (this == &g) return *this;
	setIp(g.getIp());
	return *this;
}

const char * Guest::getIp() const
{
	return this->ipAddress;
}

void Guest::setIp(const char * ipAddress)
{
	delete[] this->ipAddress;
	this->ipAddress = new char[strlen(ipAddress) + 1];
	strcpy_s(this->ipAddress, strlen(ipAddress) + 1, ipAddress);
}