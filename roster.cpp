#include "roster.h"
#include <iostream>

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{

	int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

	Student* temp = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);

	//	Store student pointer to the class roster.
	classRosterArray.push_back(temp);

}


void Roster::remove(std::string studentID)
{
	
	//	If Student ID is found, remove student from roster.
	for (int i = 0; i < classRosterArray.size(); i++)
	{

		if (classRosterArray[i]->getStudentID() == studentID)
		{

			delete classRosterArray[i];
			classRosterArray.erase(classRosterArray.begin() + i);
			return;

		}

	}
	//	If Student ID was not found, print error message.
	std::cout << "Student with ID " << studentID << " not found!" << std::endl;
}


void Roster::printAll()
{

	//	Print student info.
	for (int i = 0; i < classRosterArray.size(); i++)
	{

		classRosterArray[i]->print();

	}

}


void Roster::printAverageDaysInCourse(std::string studentID)
{

	for (int i = 0; i < classRosterArray.size(); i++)
	{
		
		//	If student ID matches then it will compute average of the 3 days and print.
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			
			int* days = classRosterArray[i]->getDaysTillComplete();
			double avg = (days[0] + days[1] + days[2]) / 3.0;
			std::cout << studentID << ": " << avg << std::endl;
			return;

		}
	}
	std::cout << std::endl;

}


void Roster::printInvalidEmails()
{

	for (int i = 0; i < classRosterArray.size(); i++)
	{


		std::string email = classRosterArray[i]->getEmail();

		//	Check student email to see if it is invalid then prints invalid email.
		if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos)
		{

			std::cout << "Invalid email: " << email << std::endl;

		}

	}

}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{

	for (int i = 0; i < classRosterArray.size(); i++)
	{

		if (classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{

			classRosterArray[i]->print();

		}

	}

}


void Roster::parse(std::string row)
{

	size_t pos = 0;
	size_t comma = row.find(',');


	//  Student ID
	std::string studentID = row.substr(0, comma);
	pos = comma + 1;
	comma = row.find(',', pos);


	//  First name
	std::string firstName = row.substr(pos, comma - pos);
	pos = comma + 1;
	comma = row.find(',', pos);


	//  Last name
	std::string lastName = row.substr(pos, comma - pos);
	pos = comma + 1;
	comma = row.find(',', pos);


	//  Email
	std::string email = row.substr(pos, comma - pos);
	pos = comma + 1;
	comma = row.find(',', pos);


	//  Age
	int age = std::stoi(row.substr(pos, comma - pos));
	pos = comma + 1;
	comma = row.find(',', pos);


	//  Days in course
	int day1 = std::stoi(row.substr(pos, comma - pos));
	pos = comma + 1;
	comma = row.find(',', pos);

	int day2 = std::stoi(row.substr(pos, comma - pos));
	pos = comma + 1;
	comma = row.find(',', pos);

	int day3 = std::stoi(row.substr(pos, comma - pos));
	pos = comma + 1;


	//  Degree program
	std::string degreeString = row.substr(pos);

	DegreeProgram degreeProgram = SOFTWARE;

	if (degreeString == "SECURITY")
	{

		degreeProgram = SECURITY;

	}
	else if (degreeString == "NETWORK")
	{

		degreeProgram = NETWORK;

	}
	else if (degreeString == "SOFTWARE")
	{

		degreeProgram = SOFTWARE;

	}


	//  Add each student to class roster.
	add(studentID, firstName, lastName, email, age, day1, day2, day3, degreeProgram);

}


Roster::~Roster()
{

	for (int i = 0; i < classRosterArray.size(); i++)
	{

		delete classRosterArray[i];

	}

}



