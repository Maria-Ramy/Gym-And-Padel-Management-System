#pragma once
#include<iostream>
using namespace std;

class ClassInfo
{
private:
	string className, day, time;
	int capacity;
public:
	ClassInfo();
	ClassInfo(string ClassName, string ClassDay, string ClassTime, int ClassCapacity);
	void setClassName(string ClassName);
	void setClassTime(string ClassTime);
	void setClassDay(string ClassDay);
	void setClassCapacity(int Capacity);
	string getClassName() const;
	string getClassTime() const;
	string getClassDay() const;
	int getClassCapacity() const;
	// for debug
	void display();
};