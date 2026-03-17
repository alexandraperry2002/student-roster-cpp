#include "student.h"
#include <iostream>
#include <iomanip>


//  Constructor 
Student::Student(std::string studentID, std::string firstName, std::string lastName,
	std::string email, int age, int days[3], DegreeProgram degreeProgram)
{

	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setDaysTillComplete(days);
	setDegreeProgram(degreeProgram);

}



//	Mutator (setter) functions
void Student::setStudentID(std::string studentID)
{
	this->studentID = studentID;
}
void Student::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}
void Student::setLastName(std::string lastName)
{
	this->lastName = lastName;
}
void Student::setEmail(std::string email)
{
	this->email = email;
}
void Student::setAge(int age)
{
	this->age = age;
}
void Student::setDaysTillComplete(int days[3])
{

	//	Copy 3 course completion days into the array.
	for (int x = 0; x < 3; x++)
	{
		daysTillComplete[x] = days[x];
	}

}
void Student::setDegreeProgram(DegreeProgram program)
{
	degreeProgram = program;
}



//  Accessor (getter) functions
std::string Student::getStudentID() const
{
	return studentID;
}
std::string Student::getFirstName() const
{ 
	return firstName;
}
std::string Student::getLastName() const
{ 
	return lastName;
}
std::string Student::getEmail() const
{ 
	return email;
}
int Student::getAge() const
{
	return age;
}
int* Student::getDaysTillComplete() 
{
	return daysTillComplete;
}
DegreeProgram Student::getDegreeProgram() const 
{
	return degreeProgram;
}



//	Print student info. 
void Student::print() const
{
		
	std::cout << std::left
		<< std::setw(8) << getStudentID()
		<< "First Name: " << std::setw(12) << getFirstName()
		<< "Last Name: " << std::setw(12) << getLastName()
		<< "Email: " << std::setw(30) << getEmail()
		<< "Age: " << std::setw(4) << getAge()
		<< "daysInCourse: {" << daysTillComplete[0] << ", " << daysTillComplete[1] << ", " << daysTillComplete[2] << "} "
		<< "Degree Program: ";

	//	Make sure students correct degree program appear on output.
	if (getDegreeProgram() == SECURITY)
		std::cout << "SECURITY";
	else if (degreeProgram == NETWORK)
		std::cout << "NETWORK";
	else
		std::cout << "SOFTWARE";
	
	std::cout << std::endl;

}





