#pragma once
#include <iostream>
#include "Person.h"
#include "Subscription.h"
#include"PlansData.h"
#include<vector>

class Member : public Person
{
private:
    Subscription plan;
    vector<string>pastWorkouts;
    long long ID;

public:
    Member();
    Member(string name1, string name2, string name3, int dd, int mm, int yy, long long id, string planName, int dur);
    void setID(int id);
    void addWorkout(string workout);
    long long getID() const;
    vector<string>getPastWorkouts()const;
    string getPlanName() const;
    int getPlanDuration() const;
    void renew(string planName);
    void cancel();
    void change(string newPlan);
};