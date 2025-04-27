#include<iostream>
#include<map>
#include<vector>
#include"Subscription.h"
#include"FileManager.h"
#include"Member.h"
#include"ClassInfo.h"
#define ll long long
using namespace std;



int main()
{
	FileManager::loadAccounts();
    FileManager::loadClasses();
	FileManager::loadWaitLists();


	ClassInfo c1("Friday", "8 PM", "Youssef", 0);
	ClassInfo c2("Monday", "7 PM", "Ahmed", 0);
	ClassInfo c3("Friday", "6 PM", "Khaled", 0);
	ClassInfo c4("Wednesday", "10 AM", "Hassan", 0);

	FileManager::classes["Cardio"] = c1;
	FileManager::classes["Yoga"] = c2;
	FileManager::classes["Dance"] = c3;
	FileManager::classes["Pilates"] = c4;



	FileManager::saveWaitLists();
	FileManager::saveAccounts();
	FileManager::saveClasses();

	return 0;
}