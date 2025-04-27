#pragma once
#include<iostream>
using namespace std;

class ClassInfo
{
private:
	string classDay, classTime, coachName;
	int capacity;
public:
	ClassInfo();
	ClassInfo(string ClassDay, string ClassTime, string CoachName, int ClassCapacity);
	void setClassTime(string ClassTime);
	void setClassDay(string ClassDay);
	void setClassCoach(string CoachName);
	void setClassCapacity(int Capacity);
	string getClassTime() const;
	string getClassDay() const;
	string getCoachName() const;
	int getClassCapacity() const;
	// for debug
	void display();
};