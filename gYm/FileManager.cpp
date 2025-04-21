#include "FileManager.h"

// ifstream -> read
// ofstream -> write

bool FileManager::loadWaiting()
{
	
}

bool FileManager::matchingNameAndId(string name, int id)
{
	json accounts;
	// Open Accounts File
	ifstream file("Accounts.json");
	// Load To Accounts
	file >> accounts;
	file.close();

	// Check If User Exists First
	if (!accounts.contains(name))
		return false;

	// User Exists, Look For Matching ID
	auto it = accounts.begin();
	while (it != accounts.end())
	{
		if (accounts[name] == id)
			return true;
		it = next(it);
	}
	return false;
}

json FileManager::loadUserToObject(int id)
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