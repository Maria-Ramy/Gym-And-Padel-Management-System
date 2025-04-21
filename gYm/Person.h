#pragma once
#include"Date.h"

class Person
{
private:
	string fName, mName, lName;
	Date dateOfBirth;
public:
	Person();
	string getFname();
	string getMname();
	string getLname();
	void setFname(string Fname);
	void setMname(string Mname);
	void setLname(string Lname);
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int Day);
	void setMonth(int Month);
	void setYear(int Year);
};