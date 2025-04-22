#include<iostream>
#include<map>
#include"FileManager.h"
using namespace std;


int main()
{
	FileManager::loadAccounts();
	auto it = FileManager::accounts.begin();
	while (it != FileManager::accounts.end())
	{
		cout << it->first << " " << it->second << "\n";
	}
	return 0;
}