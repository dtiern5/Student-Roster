#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "degree.h"
using namespace std;

class Student
{
public:
	const static int daysArraySize = 3;


private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[daysArraySize];
	DegreeProgram degreeProgram;

public:
	Student(); // Default constructor
	Student(string StudentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);

	// Getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

	// Setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print();
	~Student();

};

#endif
