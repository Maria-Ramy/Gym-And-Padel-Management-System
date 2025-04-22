#pragma once
#include<iostream>
#include<queue>
#include<fstream>
#include"json.hpp"
using json = nlohmann::json;
using namespace std;


class FileManager
{
public:
	FileManager();

	static map<string, queue<string>>waitingLists;
	static map<long long, string>accounts;

	static void loadAccounts();
	static void saveAccounts();

	static bool matchingNameAndId(string name, long long id);

	static json loadUserToObject(long long id);
	static bool fileExist(string fileName);
	static void loadUserToFile(string fileName, json obj);
	static void createFile(string name);
	static void addToWaiting(string className, string fName, string mName, string lName);
};