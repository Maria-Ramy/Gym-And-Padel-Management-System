#include "FileManager.h"

// ifstream -> read
// ofstream -> write

// From Json Uses Class Constructor

unordered_map<string, queue<Member>> FileManager::waitingLists;
unordered_map<string, ClassInfo> FileManager::classes;
unordered_map<string, Member> FileManager::accounts;

FileManager::FileManager()
{
}

void from_json(const json& j, Member& u) {
	u = Member
	{
		j.at("First Name").get<string>(),
		j.at("Middle Name").get<string>(),
		j.at("Last Name").get<string>(),
		j.at("Day").get<int>(),
		j.at("Month").get<int>(),
		j.at("Year").get<int>(),
		j.at("ID").get<long long>(),
		j.at("Plan Name").get<string>(),
		j.at("Duration").get<int>(),
	};
}



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
		it++;
	}
}

void to_json(json& j, const Member& u)
{
	j = json
	{
		{"First Name", u.getFname()},
		{"Middle Name", u.getMname()},
		{"Last Name", u.getLname()},
		{"Day", u.getDay()},
		{"Month", u.getMonth()},
		{"Year", u.getYear()},
		{"ID", u.getID()},
		{"Plan Name", u.getPlanName()},
		{"Duration", u.getPlanDuration()},
	};
}


void FileManager::saveAccounts()
{
	json Accounts;
	auto it = accounts.begin();
	while (it != accounts.end())
	{
		Accounts[it->first] = it->second;
		it++;

	}
	ofstream file("Accounts.json");
	file << Accounts.dump(4);
	file.close();
}


void to_json(json& j, const ClassInfo& u)
{
	j = json
	{
		{"Day", u.getClassDay()},
		{"Time", u.getClassTime()},
		{"Coach", u.getCoachName()},
		{"Capacity", u.getClassCapacity()}
	};
}


void from_json(const json& j, ClassInfo& u) {
	u = ClassInfo
	{
		j.at("Day").get<string>(),
		j.at("Time").get<string>(),
		j.at("Coach").get<string>(),
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
		for (Member member : it.value())
			waitingLists[className].push(member);
		it++;
	}
}

void FileManager::saveWaitLists()
{
	json waitingListsJson;

	auto it = waitingLists.begin();
	while (it != waitingLists.end())
	{
		queue<Member>currentClass = it->second;
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
	file << waitingListsJson.dump(4);
	file.close();
}

long long FileManager::getLastId()
{
	auto it = accounts.begin();
	long long mx = -1;
	while (it != accounts.end())
	{
		mx = max(mx, stoll(it->first));
		it++;
	}
	return mx;
}


bool FileManager::matchingNameAndId(string name, string id)
{
	// Check If User Exists First
	if (accounts.find(id) == accounts.end())
		return false;
	string fullName = accounts[id].getFname() + " " + accounts[id].getMname() + " " + accounts[id].getLname();
	return fullName == name ? true : false;
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

void FileManager::addMember(const Member& member, string className)
{
	if (classes[className].getClassCapacity() >= 10)
	{
		waitingLists[className].push(member);
		cout << "Class is full. Member added to waiting list for " << className << endl;
	}
	else
	{
		classes[className].setClassCapacity(classes[className].getClassCapacity() + 1);
		cout << "Member successfully added to class " << className << endl;
	}
}

void FileManager::removeMemberFromClass(string className)
{
	if (classes[className].getClassCapacity() > 0)
	{
		classes[className].setClassCapacity(classes[className].getClassCapacity() - 1);

		if (!waitingLists[className].empty())
		{
			Member firstInQueue = waitingLists[className].front();
			waitingLists[className].pop();

			classes[className].setClassCapacity(classes[className].getClassCapacity() + 1);

			cout << "A member from the waiting list has been added to the class: " << className << endl;
		}
		else
		{
			cout << "No members in waiting list for class: " << className << endl;
		}
	}
	else
	{
		cout << "No members currently enrolled in class: " << className << endl;
	}
}

