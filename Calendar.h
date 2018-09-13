#pragma once
#include"Month.h"

class Calendar
{
private:
	Month months[12];
	char* description;
	bool isLeap;
public:
	Calendar();
	Calendar(bool,const char*);
	~Calendar();
	Calendar(const Calendar&);
	Calendar& operator=(const Calendar& other);

	 Month& Months(int);//Indexing for accessing the months starts from 1
	const char* Description();
};