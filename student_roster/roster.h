#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;


public:
	Student* classRosterArray[numStudents];
	// Parse the data in "studentData Table" and add each student to classRosterArray
	void parse(string inputStudent);
	void add(string studentID, string firstName, string lastName, string email, int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);

	// Remove student from roster using studentID
	void remove(string studentID);

	// Print statements
	void printAll(); // Prints tab separated list of all student data
	void printAverageDaysInCourse(string studentID); // Print average number of days in 3 courses using Student ID paramater
	void printInvalidEmails(); // Verifies emails and displays any invalid emails to user
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};

#endif