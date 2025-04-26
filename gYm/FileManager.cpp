#include "FileManager.h"

// ifstream -> read
// ofstream -> write

unordered_map<string, queue<string>> FileManager::waitingLists;
map<long long, string> FileManager::accounts;
unordered_map<string, ClassInfo> FileManager::classes;

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
		it++;
	}
}

void FileManager::saveAccounts()
{
	json Accounts;
	auto it = accounts.begin();
	while (it != accounts.end())
	{
		Accounts[it->second] = it->first;
		it++;
	}
	ofstream file("Accounts.json");
	file << Accounts;
	file.close();
}


void to_json(json& j, const ClassInfo& u)
{
	j = json
	{
		{"Name", u.getClassName()},
		{"Day", u.getClassDay()},
		{"Time", u.getClassTime()},
		{"Capacity", u.getClassCapacity()}
	};
}

void from_json(const json& j, ClassInfo& u) {
	u = ClassInfo{
		j.at("Name").get<string>(),
		j.at("Day").get<string>(),
		j.at("Time").get<string>(),
		j.at("Capacity").get<int>()
	};
}


void FileManager::loadClasses()
{
	ifstream file("Classes.json");
	json Classes;
	file >> Classes;
	auto it = Classes.begin();
	while (it != Classes.end())
	{
		classes[it.key()] = it.value();
		it++;
	}
}

void FileManager::saveClasses()
{
	ofstream file("Classes.json");
	json Classes;
	auto it = classes.begin();
	while (it != classes.end())
	{
		string className = it->first;
		Classes[className] = it->second;
		it++;
	}
	file << Classes.dump(4);
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
		string className = it.key();
		for (string name : it.value())
			waitingLists[className].push(name);
		it++;
	}
}

void FileManager::saveWaitLists()
{
	json waitingListsJson;
	
	auto it = waitingLists.begin();
	while (it != waitingLists.end())
	{
		queue<string>currentClass = it->second;
		string className = it->first;
		while (currentClass.size())
		{
			waitingListsJson[className].push_back(currentClass.front());
			currentClass.pop();	
		}
		it++;
	}
	// Write In File
	ofstream file("WaitLists.json");
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