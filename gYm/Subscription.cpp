#include "Subscription.h"

Subscription::Subscription()
{
}

Subscription::Subscription(string Name, int Price, int Duration) : name(Name), price(Price), duration(Duration)
{
}

void Subscription::setName(string Name)
{
	name = Name;
}

void Subscription::setPrice(int Price)
{
	price = Price;
}

void Subscription::setDurtion(int Duration)
{
	duration = Duration;
}

string Subscription::getName()
{
	return name;
}

int Subscription::getPrice()
{
	return price;
}

int Subscription::getDuration()
{
	return duration;
}

void Subscription::extendPlan(string planName)
{
	duration += PlansData::getDuration(planName);
}

void Subscription::cancelPlan()
{
	duration = 0;
}

void Subscription::changePlan(string newPlan)
{
	// If Sub Ends Only
	duration = PlansData::getDuration(newPlan);
	name = newPlan;
}

void Subscription::newPlan(string planName, string userName)
{
	changePlan(planName);
	auto lastUser = FileManager::accounts.rbegin();
	long long newId = lastUser->first + 1;
	// userName to map
	FileManager::accounts[newId] = userName;
}
