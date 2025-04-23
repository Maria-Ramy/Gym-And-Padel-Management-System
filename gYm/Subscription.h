#pragma once
#include<iostream>
using namespace std;

// Basic, Standard, Premium, Ultimate 
class Subscription
{
private:
	string name;
	int price, duration;
public:
	Subscription();
	Subscription(string Name, int Price, int Duration);
	void setName(string Name);
	void setPrice(int Price);
	void setDurtion(int Duration);
	string getName();
	int getPrice();
	int getDuration();
};