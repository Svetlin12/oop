#pragma once
#include <string.h>

class Guest
{
private:

	char* ipAddress = nullptr;

public:

	//the big 4 + a constructor with parameters
	Guest();
	Guest(const char* ipAddress);
	Guest(const Guest& g);
	~Guest();
	Guest& operator=(const Guest& g);

	//getter and setter for ipAddress
	const char* getIp() const;
	void setIp(const char* ipAddress);

};