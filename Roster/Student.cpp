// Degree header for WGU - C867 - PA (3/11) - Ver. 0.5a - Last Edit 2020.03.31
/*
Man-Lung, Chau (Ricky)
001314629
C++
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

//Empty Constructor
Student::Student()
{
	this->studentID			=	"";
	this->firstName			=	"";
	this->lastName			=	"";
	this->emailAddress		=	"";
	this->studentAge		=	0;
	this->daysToComplete	=	new int[daysToCompleteSize];

	for (int i = 0; i < daysToCompleteSize; i++)
		this->daysToComplete[i] = 0;
}

//Full Constructor
Student::Student(string sID, string fName, string lName, string eAddress, int sAge, int daysToComplete[], Degree degree)
{
	this->studentID			= sID;
	this->firstName			= fName;
	this->lastName			= lName;
	this->emailAddress		= eAddress;
	this->studentAge		= sAge;
	this->daysToComplete	= new int[daysToCompleteSize];

	for (int i = 0; i < 3; i++)
		this->daysToComplete[i] = daysToComplete[i];
}

//Destructor
Student::~Student()
{
}

#pragma region Getters
//Getters
string	Student::getStudentID()
{
	return studentID;
}
string	Student::getFirstName()
{
	return firstName;
}
string	Student::getLastName()
{
	return lastName;
}
string	Student::getEmailAddress()
{
	return emailAddress;
}
int		Student::getStudentAge()
{
	return studentAge;
}
int* Student::getDaysToComplete()
{
	return daysToComplete;
}
#pragma endregion

#pragma region Setters
//Setters
void   Student::setStudentID(string sID)
{
	this->studentID = sID;
}
void   Student::setFirstName(string fName)
{
	this->firstName = fName;
}
void   Student::setLastName(string lName)
{
	this->lastName = lName;
}
void   Student::setEmailAddress(string eAddress)
{
	this->emailAddress = eAddress;
}
void   Student::setStudentAge(int sAge)
{
	this->studentAge = sAge;
}
void   Student::setDaysToComplete(int daysToComplete[])
{
	if (this->daysToComplete != nullptr)
	{
		delete[] 
		this->daysToComplete;
		this->daysToComplete = nullptr;
		this->daysToComplete = new int[daysToCompleteSize];
	}
	for (int i = 0; i < 3; ++i) 
	{
		this->daysToComplete[i] = daysToComplete[i];
	}
}
#pragma endregion

#pragma region Print
//Print

void Student::print() //Adjust what data to be shown
{
	int* courseday = getDaysToComplete();

	cout << "First name: " << getFirstName() << "\t";
	cout << "Last name: " << getLastName() << "\t";
	cout << "Age: " << getStudentAge() << "\t";
	cout << "Days In Course: {" << *courseday << ", " << *(courseday + 1) << ", " << *(courseday + 2) << "}" << "\t";
	cout << "Degree Program: " << degreeTypeString[getDegreeProgram()];
}

void Student::printEmailAddress()
{
	cout <<  "E-Mail: " << getEmailAddress() << "	";
}
#pragma endregion
