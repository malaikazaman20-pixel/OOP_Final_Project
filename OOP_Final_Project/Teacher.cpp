#include "Teacher.h"
#include "Assignment.h"
#include "FileHandling.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Teacher::Teacher() : teacherID(0), courseCount(0), studentCount(0) {}
Teacher::~Teacher() {}

int Teacher::viewProfile()
{
    try
    {
        cout << "Teacher Profile: " << endl;
        cout << "Teacher ID: " << teacherID << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Courses: " << endl;

        if (courseCount == 0)
            cout << "No courses assigned." << endl;
        else
            for (int i = 0; i < courseCount; i++)
                cout << "- " << listOfCourses[i] << endl;
        return 1;
    }
    catch (exception& e)
    {
        cerr << "Error viewing profile: " << e.what() << endl;
        return -1;
    }
}


void Teacher::createAssignment(Assignment* assign)
{
    int id, day, mon, year;
    FileHandling fh;
    try
	{
        if (assign != nullptr)
        {
            cout << "Enter Assignment ID: ";
            cin >> id;
            assign->setAssignmentID(id);
            cout << "Enter Due Date (day month year): ";
            cin >> day >> mon >> year;
            assign->setDueDate(day, mon, year);
            cout << "Upload your assigment for description";

            cout << "Here is your uploaded Assignment" << endl;
            cout << "Assignment ID: " << assign->getAssignmentID() << endl;
            cout << "Due Date: " << day << " : " << mon << " : " << year << endl;
			cout << "Assignment Description: " << assign->getDescription() << endl;
			fh.readData();
        }
      
    }
    catch (exception& e)
    {
        cerr << "Error uploading assignment: " << e.what() << endl;
    }
}

void Teacher::gradeAssignment(Student* student, int& assignmentId, char grade)
{
    try
    {
        if (student == nullptr)
            throw invalid_argument("Student pointer is null.");
        if (assignmentId == 0)
            throw invalid_argument("Assignment title cannot be empty.");

        std::cout << "Grading assignment '" << assignmentId
            << "' for student " << student->getName()
            << ". Grade: " << grade << std::endl;

        student->addGrade(assignmentId, grade);
    }
    catch (exception& e)
    {
        std::cerr << "Error grading assignment: " << e.what() << std::endl;
    }
}


void Teacher::setTeacherID(int id)  
{
    teacherID = id;
}


int Teacher::getTeacherID()
{
	return teacherID;
}