#include "Time.h"
#include <stdexcept>

bool Time::isValid(int h, int m, int s)
{
	return !(h < 0 || h>23 || m < 0 || m>59 || s < 0 || s>59);
}

int Time::Hour()
{
	return hh;
}

int Time::Min()
{
	return mm;
}

int Time::Sec()
{
	return ss;
}

Time& Time::operator=(const Time& other)
{
	this->hh = other.hh;
	this->mm = other.mm;
	this->ss = other.ss;
	return *this;
}

Time::Time()
{
	hh = 0;
	mm = 0;
	ss = 0;
}

Time::Time(int h, int m, int s)
{
	if (isValid(h, m, s))
	{
		hh = h;
		mm = m;
		ss = s;
	}
	else
	{
		throw std::invalid_argument("invalid time");
	}
}

Time::Time(const Time & other)
{
	this->hh = other.hh;
	this->mm = other.mm;
	this->ss = other.ss;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.hh << ':' << t.mm << ':' << t.ss;
	return os;
}
