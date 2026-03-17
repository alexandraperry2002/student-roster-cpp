#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student
{
	public:

		//	Constructor 
		Student(std::string studentID, std::string firstName, std::string lastName, 
			std::string email, int age, int days[3], DegreeProgram degreeProgram);

		//	Mutator (setter) functions
		void setStudentID(std::string studentID);
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setEmail(std::string email);
		void setAge(int age);
		void setDaysTillComplete(int days[3]);
		void setDegreeProgram(DegreeProgram program);

		//  Accessor (getter) functions
		std::string getStudentID() const;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getEmail() const;
		int getAge() const;
		int* getDaysTillComplete();
		DegreeProgram getDegreeProgram() const;

		//	Print function
		void print() const;


	private:
		std::string studentID;
		std::string firstName;
		std::string lastName;
		std::string email;
		int age;
		int daysTillComplete[3];
		DegreeProgram degreeProgram;

};

#endif