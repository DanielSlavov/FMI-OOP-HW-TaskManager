#pragma once
#include<iostream>
#include<string.h>
class Person
{
private:
	char* firstName;
	char* lastName;
public:

	char* FirstName();
	char* LastName();
	Person(const char* fn,const char* ln);
	Person(const Person& other);
	Person();
	~Person();
	Person& operator=(const Person& other);
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
};