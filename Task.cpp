#include "Task.h"
#include<string.h>

int Task::tasksCount = 0;

Task::Task()
{
	this->name = nullptr;
	this->description = nullptr;
	this->tasksCount++;
	this->number = this->tasksCount;
	this->type = Default;
}

Task::~Task()
{
	delete []this->name;
	delete []this->description;
}

Task & Task::operator=(const Task& other)
{
	if (this != &other)
	{
		delete[] this->name;
		delete[] this->description;

		size_t nameSize = strlen(other.name) + 1;
		this->name = new char[nameSize];
		strcpy_s(this->name, nameSize, other.name);

		size_t descSize = strlen(other.description) + 1;
		this->description = new char[descSize];
		strcpy_s(this->description, descSize, other.description);

		this->type = other.type;
		this->start = other.start;
		this->end = other.end;
	}
	return *this;
	
}

Task::Task(const char * name, const char * description, Time start, Time end, taskType type)
{
	this->tasksCount++;
	this->number = this->tasksCount;

	size_t nameSize= strlen(name) + 1;
	this->name = new char[nameSize];
	strcpy_s(this->name,nameSize, name);

	size_t descSize = strlen(description) + 1;
	this->description = new char[descSize];
	strcpy_s(this->description, descSize, description);

	this->type = type;
	this->start = start;
	this->end = end;
}

Task::Task(const Task& other)
{
	this->tasksCount++;
	this->number = this->tasksCount;

	size_t nameSize = strlen(other.name) + 1;
	this->name = new char[nameSize];
	strcpy_s(this->name, nameSize, other.name);

	size_t descSize = strlen(other.description) + 1;
	this->description = new char[descSize];
	strcpy_s(this->description, descSize, other.description);

	this->type = other.type;
	this->start = other.start;
	this->end = other.end;
}



const char *Task::Name() 
{
	return this->name;
}

const char * Task::Description() 
{
	return this->description;
}

int Task::Number() 
{
	return this->number;
}

taskType Task::Type()
{
	return this->type;
}

int Task::TasksCount()
{
	return this->tasksCount;
}

Time Task::Start() 
{
	return this->start;
}

Time Task::End() 
{
	return this->end;
}


std::ostream & operator<<(std::ostream & os,const Task& t)
{
	t.print(os);
	return os;
}


