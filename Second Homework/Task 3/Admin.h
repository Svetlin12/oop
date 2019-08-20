#pragma once
#include "PowerUser.h"
#include "VIP.h"

class Admin : public PowerUser, public VIP
{
private:

	void changeUsername(const char* newUsername, User& u);

public:

	//the big 4 + constructor with parameters
	Admin();
	~Admin();
	Admin(const char* username, const char* password, const char* title, const char* ipAddress, int reputation);
	Admin(const Admin& a);
	Admin& operator=(const Admin& a);

	//Admin can change their username and title
	void changeAUsername(const char* username);
	void changeATitle(const char* title);

	//function to change other users usernames
	void changeOtherUsername(User& u, const char* username);

	virtual void print() const override;
};