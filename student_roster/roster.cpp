#include "roster.h"


void Roster::parse(string studentData)
{
	/* Setting left and right indexes of strings between each comma
	Then assigning to temp variables in order
	Convert necessary strings ton integers */
	int right = studentData.find(",");
	string tempID = studentData.substr(0, right);

	int left = right + 1;
	right = studentData.find(",", left);
	string tempFirst = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	string tempLast = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	string tempEmail = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	int tempAge = std::stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	int tempDays1 = std::stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	int tempDays2 = std::stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	int tempDays3 = std::stoi(studentData.substr(left, right - left));

	// Initialize to UNKNOWN, check against the other options
	DegreeProgram tempDegree = UNKNOWN;
	if (studentData.back() == 'Y')
	{
		tempDegree = SECURITY;
	}
	else if (studentData.back() == 'K')
	{
		tempDegree = NETWORK;
	}
	else if (studentData.back() == 'E')
	{
		tempDegree = SOFTWARE;
	}

	// Add days individually, will create array for constructor next
	add(tempID, tempFirst, tempLast, tempEmail, tempAge, tempDays1, tempDays2, tempDays3, tempDegree);
}


void Roster::add(string studentID, string firstName, string lastName, string email, int age, int tempDays1, int tempDays2, int tempDays3, DegreeProgram degreeProgram)
{
	// Days need to be in array format for constructor
	int dayArray[3] = { tempDays1, tempDays2, tempDays3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, dayArray, degreeProgram);
};


void Roster::remove(string studentID)
{
	cout << "REMOVING STUDENT: " << studentID << endl;
	bool studRemoved = false; // Need to know if the student was found
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			classRosterArray[i]->setStudentID("0");
			studRemoved = true;
			cout << studentID << " REMOVED" << endl;
		}
	}
	if (studRemoved == false)
	{
		cout << "ERROR: " << studentID << " NOT FOUND";
	}
	cout << endl;
}

// Iterate through classRosterArray[] and call print() function
void Roster::printAll()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() != "0")  // Using "0" for studentID when they are removed
		{
			this->classRosterArray[i]->print();
		}
	}
	cout << endl;
}

// Average the three numbers in days[] for the called studentID
void Roster::printAverageDaysInCourse(string studentID)
{
	bool studExists = false; // This is not needed for C867 project, but I want this to display an error if the student is removed
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			studExists = true;
			double avgDays;
			avgDays = ((this->classRosterArray[i]->getDays()[0])
				+ (this->classRosterArray[i]->getDays()[1])
				+ (this->classRosterArray[i]->getDays()[2]))
				/ 3.0;
			cout << studentID << ": " << avgDays;
		}
	}
	if (studExists == false)
	{
		cout << "ERROR: " << studentID << " NOT FOUND" << endl;
	}
	cout << endl;
}


/*  This section could be improved, BUT
	Using given specifications:
	Contains no spaces
	Contains both '.' and '@'  */
void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string tempEmail = (classRosterArray[i]->getEmail());
		if (tempEmail.find(' ') != std::string::npos)
		{
			cout << "HAS SPACE: " << classRosterArray[i]->getEmail() << endl;
		}
		else if (tempEmail.find('.') == std::string::npos)
		{
			cout << "NO PERIOD: " << classRosterArray[i]->getEmail() << endl;
		}
		else if (tempEmail.find('@') == std::string::npos)
		{
			cout << "NO @ SIGN: " << classRosterArray[i]->getEmail() << endl;
		}
	}
	cout << endl;
}


// Print all students under specified degree
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}


// Destructor, delete elements of classRosterArray
Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
} 
