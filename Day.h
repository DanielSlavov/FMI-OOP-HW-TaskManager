#pragma once


#include"BusinessTask.h"
#include <stdexcept>

class Day
{
	List<Task*> tasks;
public:
	void addTask(Task* task);
	void removeTask(const char* name);
	int taskCount();
	const Task* getTask(const char*);
	const Task* getTask(int);
	Day();
	Day(const Day&);
	~Day();
	Day& operator=(const Day& other);
	friend std::ostream& operator<<(std::ostream&, const Day&);


};