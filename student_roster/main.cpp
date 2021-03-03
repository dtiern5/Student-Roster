#include <iostream>
#include "roster.h"

using namespace std;


// Should be a better way to do this, but it makes things look nicer in the console when listing studentData
void tableFormat() {
	cout << "ID" << '\t' <<
		"First / Last names" << '\t' <<
		"Email" << '\t' << '\t' << '\t' <<
		"Age" << '\t' <<
		"Days Left" << '\t' <<
		"Degree Program" << endl;
}

int main()
{
	// studentData Table
	const string studentData[] =
	{
		"A1,John,Prichard,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Steph,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Ronald,McArnold,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Mary,Black,mary.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jerry,Poppins,jpopp1@bigschool.edu,31,80,60,90,SOFTWARE",
	};

	// Create and populate classRoster
	const int numStudents = 5;
	Roster classRoster;
	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);

	// Print my own information at the top
	cout << "Script/Programming Applications Course" << endl;
	cout << "Written in C++ by Daniel Tierney" << endl;
	cout << endl << endl;


	// Print all students
	cout << "ALL CURRENT STUDENTS:" << endl;
	tableFormat();
	classRoster.printAll();
	cout << endl;


	// Print only invalid emails
	cout << "INVALID EMAIL ADDRESSES" << endl;
	classRoster.printInvalidEmails();
	cout << endl;


	// Print the average of the three days by studentID
	cout << "AVERAGE DAYS IN COURSES BY STUDENT ID" << endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl << endl;

	/*cout << "Average of days in the three courses" << endl;
	classRoster.printAverageDaysInCourse("A3");
	cout << endl;
	*/
	// Print by Degree Program
	cout << "STUDENTS BY DEGREE PROGRAM" << endl << endl;
	cout << "SOFTWARE" << endl;
	tableFormat();
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << "NETWORK" << endl;
	tableFormat();
	classRoster.printByDegreeProgram(NETWORK);

	cout << "SECURITY" << endl;
	tableFormat();
	classRoster.printByDegreeProgram(SECURITY);
	cout << endl;


	// Removing A3
	classRoster.remove("A3");
	cout << endl;

	// Print updated roster
	cout << "ALL CURRENT STUDENTS:" << endl;
	tableFormat();
	classRoster.printAll();
	cout << endl;

	// Removing A3 again should provide an error
	classRoster.remove("A3");
	cout << endl;


	return 0;
}
