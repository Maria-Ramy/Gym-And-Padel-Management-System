#include<iostream>
#include<map>
#include<vector>
#include"FileManager.h"
using namespace std;


int main()
{
	FileManager::loadAccounts();
	
	auto it = FileManager::accounts.begin();
	while (it != FileManager::accounts.end())
	{
		cout << it->second << " " << it->first << "\n";
		it = next(it);
	}
	FileManager::saveAccounts();
	return 0;
}