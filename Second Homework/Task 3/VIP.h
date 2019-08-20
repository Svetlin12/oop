#pragma once
#include "User.h"

class VIP : virtual public User
{
public:

	//the big 4 + a constructor with parameters
	VIP();
	~VIP();
	VIP(const char* username, const char* password, const char* title, const char* ipAddress);
	VIP(const VIP& v);
	VIP& operator=(const VIP& v);

	//VIP can change their usernames and titles
	void changeVUsername(const char* username);
	void changeVTitle(const char* title);

	virtual void print() const override;
};