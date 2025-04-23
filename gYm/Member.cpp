#include "Member.h"
using namespace std;
Member::Member() : plan(), ID(0) {}

Member::Member(const Subscription& Plan, int id) : plan(Plan), ID(id) {}

// Setters
void Member::setID(int id) {
    ID = id;
}
void Member::setPlan(const Subscription& Plan) {
    plan = Plan;
}

// Getters
int Member::getID() const {
    return ID;
}
Subscription Member::getPlan() const {
    return plan;
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

void Member::getMembership(string planName) {
    plan.newPlan(planName, fName + " " + mName + " " + lName);
}