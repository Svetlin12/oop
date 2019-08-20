#pragma once
#include <iostream>

using namespace std;

class DNSRecord
{
private:

	char* domainName = nullptr;
	char* ipAddress = nullptr;

public:

	//setters
	void setDomainName(const char*);
	void setIpAddress(const char*);

	//getters
	char* getDomainName() const;
	char* getIpAddress() const;

	//constructos
	DNSRecord(const DNSRecord&);
	DNSRecord(const char*, const char*);
	DNSRecord();

	//destructor
	~DNSRecord();

	//operator=
	DNSRecord operator=(const DNSRecord&);

	//prints a DNSRecord with its domainName and ipAddress
	void print() const;
};
