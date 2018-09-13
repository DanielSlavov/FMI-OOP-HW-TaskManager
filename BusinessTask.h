#pragma once
#include"Task.h"
#include"List.h"
#include"Person.h"


class BusinessTask :public Task
{
private:
	List<Person> people;
	char* host;
	char* location;
public:
	Time Duration();
	void AddPerson(char* firstName, char* lastName);
	BusinessTask();
	BusinessTask(const char* name, const char* description, Time start, Time end, const char* location, const char* host);
	BusinessTask(const char* name, const char* description, Time start, Time end, const char* location, const char* host, List<Person>* people);
	~BusinessTask();
	BusinessTask(const BusinessTask& other);
	BusinessTask& operator=(const BusinessTask& other);

	void PrintPeople();
	const List<Person> People();
	const char* Host() ;
	virtual void print(std::ostream& os) const;
};
