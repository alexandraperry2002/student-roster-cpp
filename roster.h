#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <string>
#include "student.h"

class Roster
{

	public:

		void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void remove(std::string studentID);
		void printAll();
		void printAverageDaysInCourse(std::string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);
		void parse(std::string row);

		~Roster();


	private:
		std::vector<Student*> classRosterArray;

};

#endif
