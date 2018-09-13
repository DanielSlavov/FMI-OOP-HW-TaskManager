#include "Calendar.h"

Calendar::Calendar()
{
	this->months[0] = Month(31);
	this->months[1] = Month(28);
	this->months[2] = Month(31);
	this->months[3] = Month(30);
	this->months[4] = Month(31);
	this->months[5] = Month(30);
	this->months[6] = Month(31);
	this->months[7] = Month(31);
	this->months[8] = Month(30);
	this->months[9] = Month(31);
	this->months[10] = Month(30);
	this->months[11] = Month(31);

	this->description = nullptr;
}

Calendar::Calendar(bool isLeap,const char* desc)
{
	Calendar::Calendar();
	if (isLeap) this->months[1] = Month(29);

	size_t descSize = strlen(desc) + 1;
	this->description = new char[descSize];
	strcpy_s(this->description, descSize,desc);
}

Calendar::~Calendar()
{
	delete[] this->description;
}

Calendar::Calendar(const Calendar &other)
{
	for (int i = 0; i < 12; i++)
	{
		this->months[i] = other.months[i];
	}

	size_t descSize = strlen(other.description) + 1;
	this->description = new char[descSize];
	strcpy_s(this->description, descSize, other.description);
}

Calendar& Calendar::operator=(const Calendar & other)
{
	if (this != &other)
	{
		for (int i = 0; i < 12; i++)
		{
			this->months[i] = other.months[i];
		}
		delete[] this->description;

		size_t descSize = strlen(other.description) + 1;
		this->description = new char[descSize];
		strcpy_s(this->description, descSize, other.description);
	}
	return *this;
}


 Month & Calendar::Months(int n)
{
	 if (n < 1 || n>12) throw std::invalid_argument("invalid month");
	return this->months[n-1];
}

const char * Calendar::Description()
{
	return this->description;
}
