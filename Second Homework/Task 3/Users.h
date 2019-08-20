#pragma once
#include "User.h"

//defining max size for the array below
#define MAX_SIZE 255

//this class is basically used as a container
class Users
{
private:

	User* users[MAX_SIZE];
	int size = 0;

	void increaseSize();

public:

	int getSize() const;

	//function to see if the instance u has been already added to the array or not
	bool searchUser(const User& u) const;

	void addUser(User* u);
};