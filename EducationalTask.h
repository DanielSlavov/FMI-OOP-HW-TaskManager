#pragma once
#include"Task.h"
class EducationalTask:public Task
{
	char* subject;
	char* toRead;
public:
	EducationalTask();
	EducationalTask(const char* name, const char* description, Time start, Time end, const char* subject, const char* toRead);
	~EducationalTask();
	EducationalTask(const EducationalTask& other);
	EducationalTask& operator=(const EducationalTask& other);

	virtual void print(std::ostream& os) const;
	const char* Subject() ;
	const char* ToRead() ;
};