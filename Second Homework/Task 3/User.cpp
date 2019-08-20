#include "User.h"

void User::setAll(const char * password, const char * title, const char * username)
{
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strcpy_s(this->password, strlen(password) + 1, password);
	toEncrypt();

	delete[] this->title;
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);

	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strcpy_s(this->username, strlen(username) + 1, username);
}

//the function for the encryption
char * User::encrypt(const char * password)
{
	char* encryptedPass = new char[strlen(password) + 1];
	strcpy_s(encryptedPass, strlen(password) + 1, password);

	char characters[3] = { 'K', 'S', 'M' };

	for (int i = 0; i < strlen(password); i++)
	{
		encryptedPass[i] = password[i] ^ characters[i % (sizeof(characters) / sizeof(char))];
	}

	return encryptedPass;
}

//encrypt the data member password
void User::toEncrypt()
{
	this->password = encrypt(this->password);
}

User::User() : Guest()
{
	setAll("Default", "Default", "Default");
}

User::User(const char* username, const char* password, const char* title, const char* ipAddress) : Guest(ipAddress)
{
	setAll(password, title, username);
}

User::~User()
{
	delete[] this->password;
	delete[] this->title;
	delete[] this->username;
}

User::User(const User & u) : Guest(u.getIp())
{
	setAll(u.getPassword(), u.getTitle(), u.getUsername());
}

User & User::operator=(const User & u)
{
	if (this != &u)
	{
		Guest::operator=(u);
		setAll(u.getPassword(), u.getTitle(), u.getUsername());
	}
	return *this;
}

const char * User::getPassword() const
{
	return this->password;
}

void User::changePassword(const char * newPassword, const char* oldPassword)
{
	if (getPassword() == oldPassword)
	{
		delete[] this->password;
		this->password = new char[strlen(newPassword) + 1];
		strcpy_s(this->password, strlen(newPassword) + 1, newPassword);
		toEncrypt();
	}
}

void User::setTitle(const char * title)
{
	delete[] this->title;
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
}

const char * User::getTitle() const
{
	return this->title;
}

const char * User::getUsername() const
{
	return this->username;
}

void User::setUsername(const char * username)
{
	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strcpy_s(this->username, strlen(username) + 1, username);
}

void User::print() const
{
	std::cout << "---User---" << std::endl;
	std::cout << "Username: " << getUsername() << std::endl;
	std::cout << "Title: " << getTitle() << std::endl;
	std::cout << "Password: " << getPassword() << std::endl;
	std::cout << "IpAddress: " << getIp() << std::endl;
	std::cout << "----------\n" << std::endl;
}