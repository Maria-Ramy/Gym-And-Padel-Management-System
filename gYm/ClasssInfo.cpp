#include "ClassInfo.h"

ClassInfo::ClassInfo()
{
}

ClassInfo::ClassInfo(string ClassName, string ClassDay, string ClassTime, int ClassCapacity)
{
	className = ClassName;
	classDay = ClassDay;
	classTime = ClassTime;
	capacity = ClassCapacity;
}

void ClassInfo::setClassName(string ClassName)
{
	className = ClassName;
}

void ClassInfo::setClassTime(string ClassTime)
{
	classTime = ClassTime;
}

void ClassInfo::setClassDay(string ClassDay)
{
	classDay = ClassDay;
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
	return classTime;
}

string ClassInfo::getClassDay() const
{
	return classDay;
}

int ClassInfo::getClassCapacity() const
{
	return capacity;
}

void ClassInfo::display()
{
	cout << className << "\n";
	cout << classTime << "\n";
	cout << classDay << "\n";
	cout << capacity << "\n";
}
