#pragma once
#include"Date.h"

class Person
{
protected:
	string fName, mName, lName;
	Date dateOfBirth;
public:
	Person();
	string getFname() const;
	string getMname() const;
	string getLname() const;
	void setFname(string Fname);
	void setMname(string Mname);
	void setLname(string Lname);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int Day);
	void setMonth(int Month);
	void setYear(int Year);
};