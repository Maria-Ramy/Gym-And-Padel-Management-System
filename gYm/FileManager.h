#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include<fstream>
#include"ClassInfo.h"
#include"json.hpp"
using json = nlohmann::json;
using namespace std;


class FileManager
{
public:
	FileManager();
	static unordered_map<string, queue<string>>waitingLists;
	static map<long long, string>accounts;
	static unordered_map<string, ClassInfo>classes;

	// Working
	static void loadAccounts();
	static void saveAccounts();

	// Working
	static void loadClasses();
	static void saveClasses();

	// Needs Debugging
	static void loadWaitLists();
	static void saveWaitLists();



	static bool matchingNameAndId(string name, long long id);

	static json loadUserToObject(long long id);
	static bool fileExist(string fileName);
	static void loadUserToFile(string fileName, json obj);
	static void createFile(string name);
	static void addToWaiting(string className, string fName, string mName, string lName);
};