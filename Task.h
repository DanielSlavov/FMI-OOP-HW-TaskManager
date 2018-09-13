#pragma once
#include<iostream>
#include"Time.h"
enum taskType
{
	Default,
	Business,
	Entertainment,
	Educational
};

class Task
{
private:
	
protected:
	char *name;
	char* description;
	int number;
	taskType type;
	static int tasksCount;
	Time start;
	Time end;
public:
	Task(const char* name, const char* description, Time start, Time end, taskType type);
	Task(const Task& other);
	Task();
	~Task();
	Task& operator=(const Task& other);

	friend std::ostream& operator<<(std::ostream& ,const Task&);
	virtual  void print(std::ostream& os) const = 0;
	const char* Name()  ;
	const char* Description() ;
	int Number() ;
	taskType Type() ;
	int TasksCount() ;
	Time Start() ;
	Time End() ;
	

};
