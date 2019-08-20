#include <iostream>
#include "DNSRecord.h"

void DNSRecord::setDomainName(const char * domainName)
{
	delete[] this->domainName;
	this->domainName = new char[strlen(domainName) + 1];
	strcpy_s(this->domainName, strlen(domainName) + 1, domainName);
}

char * DNSRecord::getDomainName() const
{
	return this->domainName;
}

void DNSRecord::setIpAddress(const char * ipAddress)
{
	delete[] this->ipAddress;
	this->ipAddress = new char[strlen(ipAddress) + 1];
	strcpy_s(this->ipAddress, strlen(ipAddress) + 1, ipAddress);
}

char * DNSRecord::getIpAddress() const
{
	return this->ipAddress;
}

DNSRecord::DNSRecord(const DNSRecord& d)
{
	setDomainName(d.getDomainName());
	setIpAddress(d.getIpAddress());
}

DNSRecord::DNSRecord(const char* domainName, const char* ipAddress)
{
	setDomainName(domainName);
	setIpAddress(ipAddress);
}

DNSRecord DNSRecord::operator=(const DNSRecord& d)
{
	if (this != &d)
	{
		setDomainName(d.getDomainName());
		setIpAddress(d.getIpAddress());
	}
	return *this;
}

DNSRecord::DNSRecord()
{
	setDomainName("default");
	setIpAddress("default");
}

DNSRecord::~DNSRecord()
{
	delete[] this->domainName;
	delete[] this->ipAddress;
}

void DNSRecord::print() const
{
	cout << getDomainName() << endl << getIpAddress() << endl << endl;
}