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
	//FileManager::loadWaitLists();


	//FileManager::saveWaitLists();
	FileManager::saveAccounts();
	FileManager::saveClasses();

	return 0;
}