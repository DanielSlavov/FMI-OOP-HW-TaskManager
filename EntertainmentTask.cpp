#include "EntertainmentTask.h"

EntertainmentTask::EntertainmentTask() :Task::Task()
{
	this->entertainmentType = nullptr;
	this->location = nullptr;
}

EntertainmentTask::EntertainmentTask(const char * name, const char * description, Time start, Time end, const char * entertainmentType, const char * location):Task::Task(name, description, start, end, Entertainment)
{
	size_t entTypeSize = strlen(entertainmentType) + 1;
	this->entertainmentType = new char[entTypeSize];
	strcpy_s(this->entertainmentType, entTypeSize, entertainmentType);

	size_t locSize = strlen(location) + 1;
	this->location = new char[locSize];
	strcpy_s(this->location, locSize, location);
}

EntertainmentTask::~EntertainmentTask()
{
	delete []this->entertainmentType;
	delete []this->location;
}

EntertainmentTask::EntertainmentTask(const EntertainmentTask & other):Task::Task(other)
{
	size_t entTypeSize = strlen(other.entertainmentType) + 1;
	this->entertainmentType = new char[entTypeSize];
	strcpy_s(this->entertainmentType, entTypeSize, other.entertainmentType);

	size_t locSize = strlen(other.location) + 1;
	this->location = new char[locSize];
	strcpy_s(this->location, locSize, other.location);
}

EntertainmentTask & EntertainmentTask::operator=(const EntertainmentTask & other)
{
	if (this != &other)
	{
		this->~EntertainmentTask();

		Task::operator=(other);

		size_t entTypeSize = strlen(other.entertainmentType) + 1;
		this->entertainmentType = new char[entTypeSize];
		strcpy_s(this->entertainmentType, entTypeSize, other.entertainmentType);

		size_t locSize = strlen(other.location) + 1;
		this->location = new char[locSize];
		strcpy_s(this->location, locSize, other.location);
	}
	return*this;
}

const char * EntertainmentTask::EntertainmentType()
{
	return this->entertainmentType;
}

const char * EntertainmentTask::Location()
{
	return this->location;
}

void EntertainmentTask::print(std::ostream & os) const
{
	os << this->number << ". Entertainment Task: " << this->name << "\n";
	os << this->description << "\n";
	os << this->start << " - " << this->end << "\n";
	os << "Type: " << this->entertainmentType << "\n";
	os << "Location: " << this->location << "\n";
}

void EntertainmentTask::CheckWeather()
{
	char arg[128];
	strcpy_s(arg, "start chrome  https://www.sinoptik.bg/search?q={");
	strcat_s(arg, this->location);
	strcat_s(arg, "}");
	system(arg);
}
