#pragma once
#include "User.h"
#include "Users.h"
#include <string.h>

class PowerUser : virtual public User
{
private:

	int reputation = 0;

	//we make the setter for reputation private because PowerUser is not allowed to change theirs unless someone else
	//gives them +1
	void setReputation(int reputation);

	//declaring a container instance where we can store all the users that added +1 reputation to the current instance
	//of PowerUser
	Users container;

public:

	//the big 4 + constructor with parameters
	PowerUser();
	PowerUser(const char* username, const char* password, const char* title, const char* ipAddress, int reputation);
	PowerUser(const PowerUser& p);
	PowerUser& operator=(const PowerUser& p);
	~PowerUser();

	//PowerUser can change their name
	void changePUsername(const char* username);

	//getter for reputation
	int getReputation() const;

	//adds +1 reputation if the user u hasn't added one before that
	void increaseReputation(User& u);

	//provides a function that uses the member function searchUser in Users class
	bool containerSearch(const User& u) const;

	virtual void print() const override;
};
