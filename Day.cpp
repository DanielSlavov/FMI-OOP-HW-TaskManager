#include "Day.h"

void Day::addTask(Task* task)
{
	tasks.push_back(task);
}
void Day::removeTask(const char * name)
{
	for (int i = 0; i < this->tasks.Size(); i++)
	{
		if (strcmp(tasks.get(i)->Name(), name) == 0)
			this->tasks.pop(i);
	}
}
int Day::taskCount()
{
	return this->tasks.Size();
}
const Task * Day::getTask(const char *name)
{
	for (int i = 0; i < this->tasks.Size(); i++)
	{
		if (strcmp(this->tasks.get(i)->Name(), name) == 0)
		{
			return this->tasks.get(i);
		}
	}
	return nullptr;
}
const Task * Day::getTask(int n)
{
	for (int i = 0; i < this->tasks.Size(); i++)
	{
		if (this->tasks.get(i)->Number()==n)
		{
			return this->tasks.get(i);
		}
	}
	return nullptr;
}
Day::Day() 
{
}
Day::Day(const Day & other)
{
	this->tasks = other.tasks;
}
Day::~Day()
{
}
Day & Day::operator=(const Day & other)
{
	this->tasks = other.tasks;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Day &d)
{
	for (int i = 0; i < d.tasks.Size(); i++)
	{
		os << *d.tasks.get(i);
	}
	return os;
}
