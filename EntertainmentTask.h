#pragma once
#include"Task.h"
class EntertainmentTask:public Task
{
	char* entertainmentType;
	char* location;
public:
	EntertainmentTask();
	EntertainmentTask(const char* name, const char* description, Time start, Time end, const char* entertainmentType, const char* location);
	~EntertainmentTask();
	EntertainmentTask(const EntertainmentTask& other);
	EntertainmentTask& operator=(const EntertainmentTask& other);

	const char* EntertainmentType();
	const char*	Location();
	virtual void print(std::ostream& os) const;

	void CheckWeather();
};