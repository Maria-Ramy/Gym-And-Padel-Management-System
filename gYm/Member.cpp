#include "Member.h"
using namespace std;
Member::Member() : plan(), ID(0) {}

Member::Member(string name1, string name2, string name3, int dd, int mm, int yy, long long id, string planName, int dur)
{
    fName = name1;
    mName = name2;
    lName = name3;
    dateOfBirth.setDay(dd);
    dateOfBirth.setMonth(mm);
    dateOfBirth.setYear(yy);
    ID = id;
    plan.setName(planName);
    plan.setDurtion(dur);
}

// Setters
void Member::setID(int id) {
    ID = id;
}


// Getters
long long Member::getID() const {
    return ID;
}
string Member::getPlanName() const
{
    return plan.getName();
}

int Member::getPlanDuration() const
{
    return plan.getDuration();
}


// Membership functions

void Member::renew(string planName)
{
    plan.extendPlan(plan.getName());
}

void Member::cancel() {
     plan.cancelPlan(); 
}

void Member::change(string newPlan) {
     plan.changePlan(newPlan);
}