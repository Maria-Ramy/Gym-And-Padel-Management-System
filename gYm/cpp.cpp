#include<iostream>
#include<map>
#include<vector>
#include"Subscription.h"
#include"FileManager.h"
#include"Member.h"
#define ll long long
using namespace std;



int main()
{
	FileManager::loadAccounts();
	FileManager::loadWaitLists();

	
	FileManager::saveWaitLists();
	FileManager::saveAccounts();
	return 0;
}