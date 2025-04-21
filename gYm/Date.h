#pragma once
#include<iostream>
using namespace std;


class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(int d, int m, int y);
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int Day);
	void setMonth(int Month);
	void setYear(int Year);
};