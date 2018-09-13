#pragma once

#include "Month.h"

Month::Month(int dim)
{
	if (dim < 1 || dim>31) throw std::invalid_argument("invalid days in month");
	this->daysInMonth = dim;
	this->days = new Day[this->daysInMonth];
}

Month::Month() 
{
	this->daysInMonth = 31;
	this->days = new Day[this->daysInMonth];
}

Month::Month(const Month & other)
{
	this->daysInMonth = other.daysInMonth;
	this->days = new Day[this->daysInMonth];
	for (int i = 0; i < this->daysInMonth; i++)
	{
		this->days[i] = other.days[i];
	}
}

Month::~Month()
{
	delete []this->days;
}

Month & Month::operator=(const Month & other)
{
	if (this != &other)
	{
		delete []this->days;
		this->daysInMonth = other.daysInMonth;
		this->days = new Day[this->daysInMonth];
		for (int i = 0; i < this->daysInMonth; i++)
		{
			this->days[i] = other.days[i];
		}
	}
	return *this;
}

 Day& Month::Days(int i) 
{
	if (i < 1 || i>this->daysInMonth) throw std::invalid_argument("invalid day");
	return this->days[i-1];
}
