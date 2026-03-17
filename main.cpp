#include <iostream>
#include "roster.h"

int main()
{

    const std::string studentData[] = 
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Alex,Perry,Aperry71@wgu.edu,23,15,15,52,SOFTWARE"
    };


    Roster classRoster;


    //  Loop through students to parse.
    for (int x = 0; x < 5; ++x)
    {

        classRoster.parse(studentData[x]);
     
    }


    //  Programmor info.
    std::cout << "C867: Scripting and Programming, C++" << std::endl;
    std::cout << "Alexander Perry" << std::endl;
    std::cout << "Student ID: 012751751" << std::endl << std::endl;

    //  Print all students info
    classRoster.printAll();
    std::cout << "\n";

    classRoster.printInvalidEmails();
    std::cout << "\n";


    //  loop through classRosterArray and for each element:
    std::cout << "Average Days in Course" << std::endl;
    classRoster.printAverageDaysInCourse("A1");
    classRoster.printAverageDaysInCourse("A2");
    classRoster.printAverageDaysInCourse("A3");
    classRoster.printAverageDaysInCourse("A4");
    classRoster.printAverageDaysInCourse("A5");
    std::cout << "\n";

    //  Print specific degree program.
    std::cout << "Degree Program" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << "\n";

 
    std::cout << "Removing A3";
    classRoster.remove("A3");
    std::cout << "\n";

    classRoster.printAll();
    std::cout << "\n";

    std::cout << "Removing A3" << std::endl;
    classRoster.remove("A3");
    std::cout << "\n";


    return 0;

}

