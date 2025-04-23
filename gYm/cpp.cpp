#include<iostream>
#include<map>
#include<vector>
#include"FileManager.h"
using namespace std;



int main()
{
	FileManager::loadAccounts();


	FileManager::saveAccounts();
	return 0;
}