#pragma once
#include "Day.h"

class Month
{
	Day* days;
	int daysInMonth;
public:
	
	Month(int dim);
	Month();
	Month(const Month& other);
	~Month();
	Month& operator=(const Month & other);
	Day & Days(int);//Indexing for accessing the days starts from 1

};
