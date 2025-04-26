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

string Subscription::getName() const
{
	return name;
}

int Subscription::getPrice() const
{
	return price;
}

int Subscription::getDuration() const
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