#include"Person.h"

char * Person::FirstName()
{
	return this->firstName;
}

char * Person::LastName()
{
	return this->lastName;
}

Person::Person(const char * firstName,const char * lastName)
{
	size_t fnSize = strlen(firstName) + 1;
	this->firstName = new char[fnSize];
	strcpy_s(this->firstName, fnSize, firstName);

	size_t lnSize = strlen(lastName) + 1;
	this->lastName = new char[lnSize];
	strcpy_s(this->lastName, lnSize, lastName);
}
Person::Person(const Person & other)
{
	size_t fnSize = strlen(other.firstName) + 1;
	this->firstName = new char[fnSize];
	strcpy_s(this->firstName, fnSize, other.firstName);

	size_t lnSize = strlen(other.lastName) + 1;
	this->lastName = new char[lnSize];
	strcpy_s(this->lastName, lnSize, other.lastName);
}
Person::Person()
{
	this->firstName = nullptr;
	this->lastName = nullptr;
}

Person::~Person()
{
	delete[]this->firstName;
	delete[]this->lastName;
}

Person & Person::operator=(const Person & other)
{
	if (this != &other)
	{
		this->~Person();

		size_t fnSize = strlen(other.firstName) + 1;
		this->firstName = new char[fnSize];
		strcpy_s(this->firstName, fnSize, other.firstName);

		size_t lnSize = strlen(other.lastName) + 1;
		this->lastName = new char[lnSize];
		strcpy_s(this->lastName, lnSize, other.lastName);
	}
	return *this;
}


std::ostream & operator<<(std::ostream & os, const Person & p)
{
	os << p.firstName << ' ' << p.lastName;
	return os;
}
