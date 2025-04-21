#pragma once
#include"Person.h"
#include"Subscription.h"

class Member : public Person
{
private:
	Subscription plan;
	int ID;
public:

};