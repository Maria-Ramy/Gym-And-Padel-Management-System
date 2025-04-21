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
	// List Of Waiting Lists
	static map<string, queue<string>>waitingLists;
	static bool loadWaiting();
	static bool matchingNameAndId(string name, int id);
	static json loadUserToObject(int id);
	static bool fileExist(string fileName);
	static void loadUserToFile(string fileName, json obj);
	static void createFile(string name);
	static void addToWaiting(string className, string fName, string mName, string lName);
};