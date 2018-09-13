#include"BusinessTask.h"

Time BusinessTask::Duration()
{

	return Time(this->End().Hour() - this->Start().Hour(), this->End().Min() - this->Start().Min(), this->End().Sec() - this->Start().Sec());
}

void BusinessTask::AddPerson(char * firstName, char * lastName)
{
	people.push_back( Person(firstName, lastName));
}

BusinessTask::BusinessTask() :Task::Task()
{
	this->host = nullptr;
	this->location = nullptr;
}

BusinessTask::BusinessTask(const char * name, const char * description, Time start, Time end,const char * location,const char * host) : Task::Task(name, description, start, end, Business)
{
	size_t hostSize = strlen(host) + 1;
	this->host = new char[hostSize];
	strcpy_s(this->host, hostSize, host);

	size_t locSize = strlen(location) + 1;
	this->location = new char[locSize];
	strcpy_s(this->location, locSize, location);
}

BusinessTask::BusinessTask(const char * name, const char * description, Time start, Time end, const char* location , const char* host,List<Person>* people) : Task::Task(name, description, start, end, Business)
{
	size_t hostSize = strlen(host) + 1;
	this->host = new char[hostSize];
	strcpy_s(this->host, hostSize, host);

	size_t locSize = strlen(location) + 1;
	this->location = new char[locSize];
	strcpy_s(this->location, locSize, location);

	this->people = *people;
}

BusinessTask::~BusinessTask()
{
	delete []this->host;
	delete []this->location;
}

BusinessTask::BusinessTask(const BusinessTask & other):Task::Task(other)
{
	size_t hostSize = strlen(other.host) + 1;
	this->host = new char[hostSize];
	strcpy_s(this->host, hostSize, other.host);

	size_t locSize = strlen(other.location) + 1;
	this->location = new char[locSize];
	strcpy_s(this->location, locSize, other.location);

	this->people = other.people;
}

BusinessTask & BusinessTask::operator=(const BusinessTask & other)
{
	if (this != &other)
	{
		Task::operator=(other);

		delete[]this->host;
		delete[]this->location;
		
		size_t hostSize = strlen(other.host) + 1;
		this->host = new char[hostSize];
		strcpy_s(this->host, hostSize, other.host);

		size_t locSize = strlen(other.location) + 1;
		this->location = new char[locSize];
		strcpy_s(this->location, locSize, other.location);

		this->people = other.people;
	}
	return*this;
}

void BusinessTask::PrintPeople()
{

	for (int i = 0; i < this->people.Size(); i++)
		std::cout << this->people.get(i) << "\n";
}

const List<Person> BusinessTask::People()
{
	return this->people;
}

const char * BusinessTask::Host()
{
	return this->host;
}

void BusinessTask::print(std::ostream & os) const
{
	os << this->number << ". Business Task: " << this->name << "\n";
	os << this->description << "\n";
	os << this->start << " - " << this->end << "\n";
	os << "Host: " << this->host << "\n";
	os << "People : " << this->people.Size() << "\n";
	os << "Location: " << this->location << "\n";
}
