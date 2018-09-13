#include <iostream>

class Time
{
	int hh;
	int mm;
	int ss;

  public:
	Time();
	Time(int h, int m, int s);
	Time(const Time &other);
	static bool isValid(int h, int m, int s);
	int Hour();
	int Min();
	int Sec();
	Time &operator=(const Time &other);
	friend std::ostream &operator<<(std::ostream &os, const Time &t);
};
