#include "EducationalTask.h"

EducationalTask::EducationalTask():Task::Task()
{
	this->subject = nullptr;
	this->toRead = nullptr;
}

EducationalTask::EducationalTask(const char * name, const char * description, Time start, Time end, const char * subject, const char * toRead) : Task::Task(name,description,start,end, Educational)
{
	size_t subjSize = strlen(subject) + 1;
	this->subject = new char[subjSize];
	strcpy_s(this->subject, subjSize, subject);

	size_t toReadSize = strlen(toRead) + 1;
	this->toRead = new char[toReadSize];
	strcpy_s(this->toRead, toReadSize, toRead);
}

EducationalTask::~EducationalTask()
{
	delete []this->subject;
	delete []this->toRead;
}

EducationalTask::EducationalTask(const EducationalTask & other):Task::Task(other)
{
	size_t subjSize = strlen(other.subject) + 1;
	this->subject = new char[subjSize];
	strcpy_s(this->subject, subjSize, other.subject);

	size_t toReadSize = strlen(other.toRead) + 1;
	this->toRead = new char[toReadSize];
	strcpy_s(this->toRead, toReadSize, other.toRead);
}

EducationalTask & EducationalTask::operator=(const EducationalTask & other)
{
	if (this != &other)
	{
		this->~EducationalTask();

		Task::operator=(other);

		size_t subjSize = strlen(other.subject) + 1;
		this->subject = new char[subjSize];
		strcpy_s(this->subject, subjSize, other.subject);

		size_t toReadSize = strlen(other.toRead) + 1;
		this->toRead = new char[toReadSize];
		strcpy_s(this->toRead, toReadSize, other.toRead);
	}
	return* this;
}

void EducationalTask::print(std::ostream & os) const
{
	os << this->number<< ". Educational Task: " << this->name << "\n";
	os << this->description <<std::endl;
	os << this->start << " - " << this->end << std::endl;
	os << "Sbuject: " << this->subject << "\n";
	os << "Read: " << this->toRead << "\n";
}

const char * EducationalTask::Subject()
{
	return this->subject;
}

const char * EducationalTask::ToRead()
{
	return this->toRead;
}
