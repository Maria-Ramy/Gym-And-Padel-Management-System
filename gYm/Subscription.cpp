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