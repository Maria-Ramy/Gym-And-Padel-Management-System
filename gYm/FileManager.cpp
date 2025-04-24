#include "FileManager.h"

// ifstream -> read
// ofstream -> write

map<string, queue<string>> FileManager::waitingLists;
map<long long, string> FileManager::accounts;

FileManager::FileManager()
{
}

// Call To Load All Accounts In Map Of Accounts
void FileManager::loadAccounts()
{
	json Accounts;
	// Open Accounts File
	ifstream file("Accounts.json");
	// Load To Accounts
	file >> Accounts;
	file.close();

	// User Exists, Look For Matching ID
	auto it = Accounts.begin();
	while (it != Accounts.end())
	{
		accounts[it.value()] = it.key();
		it = next(it);
	}
}

void FileManager::saveAccounts()
{
	json Accounts;
	ofstream file("Accounts.json");
	auto it = accounts.begin();
	while (it != accounts.end())
	{
		Accounts[it->second] = it->first;
		it = next(it);
	}
	file << Accounts;
	file.close();
}

void FileManager::loadWaitLists()
{
	json waitingListsJson;
	// Open WaitLists File
	ifstream file("WaitLists.json");
	// Load To WaitListsJson
	file >> waitingListsJson;
	file.close();

	auto it = waitingListsJson.begin();
	while (it != waitingListsJson.end())
	{
		string className = *it;
		for (string name : waitingListsJson[className])
			waitingLists[className].push(name);
		it++;
	}
}

void FileManager::saveWaitLists()
{
	json waitingListsJson;
	ofstream file("WaitLists.json");
	auto it = waitingLists.begin();
	while (it != waitingLists.end())
	{
		queue<string>currentClass = it->second;
		while (currentClass.size())
		{
			waitingListsJson[it->first].push_back(currentClass.front());
			currentClass.pop();	
		}
		it++;
	}
	file << waitingListsJson;
	file.close();
}

bool FileManager::matchingNameAndId(string name, long long id)
{
	// Check If User Exists First
	if (accounts.find(id) == accounts.end())
		return false;
	return accounts[id] == name ? true : false;
}

json FileManager::loadUserToObject(long long id)
{
	// If Matching Then File Must Exist
	json myFile;
	ifstream file(to_string(id) + ".json");
	file >> myFile;
	file.close();
	return myFile;
}

bool FileManager::fileExist(string fileName)
{
	ifstream file(fileName + ".json");
	return file.good();
}

void FileManager::loadUserToFile(string fileName, json obj)
{
	// Create If Dosen't Exist
	if (!fileExist(fileName))
		createFile(fileName);
	
	// Load Object To File
	ofstream file(fileName + ".json");
	file << obj;
	file.close();
}

// Takes Id As Parameter, Then Loads 
void FileManager::createFile(string name)
{
	// Check If File Already Exists
	if (fileExist(name))
		return;

	// Create A New One
	ofstream file(name + ".json");
	file.close();
}

void FileManager::addToWaiting(string className, string fName, string mName, string lName)
{
	// Must Have This
	ifstream readWaiting("WaitLists.json");

	json waitingList;
	if (readWaiting.peek() != std::ifstream::traits_type::eof())
		readWaiting >> waitingList;
	readWaiting.close();

	waitingList[className].push_back(fName + ' ' + mName + ' ' + lName);
	ofstream writeWaiting("WaitLists.json");
	writeWaiting << waitingList;
	writeWaiting.close();
}