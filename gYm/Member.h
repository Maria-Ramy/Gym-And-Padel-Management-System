#pragma once

#include <iostream>
#include "Person.h"
#include "Subscription.h"

class Member : public Person
{
private:
    Subscription plan;
    int ID;

public:
    // Constructors
    Member();
    Member(const Subscription& Plan, int id);

    // Setters
    void setID(int id);
    void setPlan(const Subscription& Plan);

    // Getters
    int getID() const;
    Subscription getPlan() const;

    // Membership functions
    void renew(string planName);
    void cancel();
    void change(string newPlan);
    void getMembership(string planName);
};