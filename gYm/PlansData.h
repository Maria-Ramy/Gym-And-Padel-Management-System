#pragma once
#include<iostream>
using namespace std;

class PlansData
{
public:
	static int getDuration(string planName);
	static int getPrice(string planName);
};