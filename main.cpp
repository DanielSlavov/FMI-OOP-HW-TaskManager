#include <iostream>
#include "Calendar.h"
#include "BusinessTask.h" 
#include "EducationalTask.h" 
#include "EntertainmentTask.h"

int main()
{

	Calendar c = Calendar();

	List<Person> listOfPeople;
	listOfPeople.push_back(Person("Pesho", "Petkov"));
	listOfPeople.push_back(Person("Anton", "Markov"));

	BusinessTask* bt=new BusinessTask("bt","Strategy negotiation", Time(10, 0, 0), Time(12, 0, 0),"Sofia","Ivan Ivanov",&listOfPeople);
	EducationalTask* et = new EducationalTask("et", "Desc", Time(10, 0, 0), Time(12, 0, 0), "OOP", "C++ 17 Book");
	EntertainmentTask* etnt = new EntertainmentTask("etnt3", "Desc", Time(10, 0, 0), Time(12, 0, 0), "going for a walk", "Sofia,Bulgaria");
	
	c.Months(1).Days(1).addTask(bt);
	c.Months(1).Days(1).addTask(et);
	c.Months(1).Days(1).addTask(etnt);
	

	BusinessTask bts = BusinessTask("bt", "Strategy negotiation", Time(10, 0, 0), Time(12, 0, 0), "Sofia", "Ivan Ivanov", &listOfPeople);
	BusinessTask aasd = bts;

	std::cout<< c.Months(1).Days(1);

	((EntertainmentTask*)c.Months(1).Days(1).getTask(3))->CheckWeather();
	cin.get();
	return 0;
}