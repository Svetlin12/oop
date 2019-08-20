#pragma once
#include "Guest.h"
#include <iostream>

class User : public Guest
{
private:

	char* password = nullptr;
	char* title = nullptr;
	char* username = nullptr;
	
	//private function to set all the above data members - the reason why we are doing it is because the 
	//changePassword member function won't work when the old password was nulltpr
	void setAll(const char* password, const char* title, const char* username);

	//function to encrypt the password and also to decrypt it
	char* encrypt(const char* password);

	//inside this function we encrypt the password - this is basically the process of storing the password as 
	//an encrypted one
	void toEncrypt();

protected:

	//we make them protected because Users must not change their username and title
	void setUsername(const char* username);
	void setTitle(const char* title);

public:

	//the big 4 + constructor with parameters
	User();
	User(const char* username, const char* password, const char* title, const char* ipAddress);
	virtual ~User();
	User(const User& u);
	User& operator=(const User& u);

	//getters and setters
	const char* getPassword() const;
	void changePassword(const char* newPassword, const char* oldPassword);

	const char* getTitle() const;
	const char* getUsername() const;

	//if we want Admin to change other users' usernames then Admin needs to have access to the protected 
	//functions setUsarname and setTitle...and that's why we declare Admin as a friend class to User
	friend class Admin;

	virtual void print() const;
};