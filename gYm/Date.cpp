#include "Date.h"

Date::Date() : day(0), month(0), year(0)
{
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::setDay(int Day)
{
	day = Day;
}

void Date::setMonth(int Month)
{
	month = Month;
}

void Date::setYear(int Year)
{
	year = Year;
}