#include "PlansData.h"

int PlansData::getDuration(string planName)
{
	if (planName == "Basic")
		return 1;
	if (planName == "Standard")
		return 3;
	if (planName == "Premium")
		return 6;
	if (planName == "Ultimte")
		return 12;
}

int PlansData::getPrice(string planName)
{
	if (planName == "Basic")
		return 100;
	if (planName == "Standard")
		return 300;
	if (planName == "Premium")
		return 600;
	if (planName == "Ultimte")
		return 1000;
}
