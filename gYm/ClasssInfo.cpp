#include "ClassInfo.h"

ClassInfo::ClassInfo()
{
}

ClassInfo::ClassInfo(string ClassDay, string ClassTime, string CoachName, int ClassCapacity)
{
	classDay = ClassDay;
	classTime = ClassTime;
	coachName = CoachName;
	capacity = ClassCapacity;
}


void ClassInfo::setClassTime(string ClassTime)
{
	classTime = ClassTime;
}

void ClassInfo::setClassDay(string ClassDay)
{
	classDay = ClassDay;
}

void ClassInfo::setClassCoach(string CoachName)
{
	coachName = CoachName;
}

void ClassInfo::setClassCapacity(int Capacity)
{
	capacity = Capacity;
}

string ClassInfo::getClassTime() const
{
	return classTime;
}

string ClassInfo::getClassDay() const
{
	return classDay;
}

string ClassInfo::getCoachName() const
{
	return coachName;
}

int ClassInfo::getClassCapacity() const
{
	return capacity;
}

void ClassInfo::display()
{
	cout << classTime << "\n";
	cout << classDay << "\n";
	cout << capacity << "\n";
	cout << coachName << "\n";
}
