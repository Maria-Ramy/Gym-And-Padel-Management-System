#include "FileManager.h"

// ifstream -> read
// ofstream -> write

map<string, queue<string>> FileManager::waitingLists;
map<string, long long> FileManager::accounts;

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
		accounts[it.key()] = it.value();
		it = next(it);
	}
}

bool FileManager::matchingNameAndId(string name, long long id)
{
	// Check If User Exists First
	if (accounts.find(name) == accounts.end())
		return false;
	return accounts[name] == id ? true : false;
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