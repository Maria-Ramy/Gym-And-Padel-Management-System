#include "ClassInfo.h"

ClassInfo::ClassInfo()
{
}

ClassInfo::ClassInfo(string ClassName, string ClassDay, string ClassTime, int ClassCapacity)
{
	className = ClassName;
	day = ClassDay;
	time = ClassTime;
	capacity = ClassCapacity;
}

void ClassInfo::setClassName(string ClassName)
{
	className = ClassName;
}

void ClassInfo::setClassTime(string ClassTime)
{
	time = ClassTime;
}

void ClassInfo::setClassDay(string ClassDay)
{
	day = ClassDay;
}

void ClassInfo::setClassCapacity(int Capacity)
{
	capacity = Capacity;
}

string ClassInfo::getClassName() const
{
	return className;
}

string ClassInfo::getClassTime() const
{
	return time;
}

string ClassInfo::getClassDay() const
{
	return day;
}

int ClassInfo::getClassCapacity() const
{
	return capacity;
}

void ClassInfo::display()
{
	cout << className << "\n";
	cout << time << "\n";
	cout << day << "\n";
	cout << capacity << "\n";
}
