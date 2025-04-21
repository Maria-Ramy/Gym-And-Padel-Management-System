#include "Person.h"

Person::Person()
{
}

string Person::getFname()
{
	return fName;
}

string Person::getMname()
{
	return mName;
}

string Person::getLname()
{
	return lName;
}

void Person::setFname(string Fname)
{
	fName = Fname;
}

void Person::setMname(string Mname)
{
	mName = Mname;
}

void Person::setLname(string Lname)
{
	lName = Lname;
}

int Person::getDay()
{
	return dateOfBirth.getDay();
}

int Person::getMonth()
{
	return dateOfBirth.getMonth();
}

int Person::getYear()
{
	return dateOfBirth.getYear();
}

void Person::setDay(int Day)
{
	dateOfBirth.setDay(Day);
}

void Person::setMonth(int Month)
{
	dateOfBirth.setDay(Month);
}

void Person::setYear(int Year)
{
	dateOfBirth.setDay(Year);
}
