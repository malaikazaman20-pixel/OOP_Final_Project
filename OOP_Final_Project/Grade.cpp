#include "Grade.h"
#include <iostream>
#include <stdexcept>
#include "Student.h"
#include "Assignment.h"
using namespace std;

Grade::Grade() : gradeID(0), student(nullptr), assignment(nullptr), marks(0.0f) {}
Grade::~Grade() {}

void Grade::setMarks()
{
    try
    {
        cout << "Enter marks: ";
        if (!(cin >> marks))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Invalid input. Marks must be a number.");
        }
        if (marks < 0.0f || marks > 100.0f)
            throw invalid_argument("Marks must be between 0 and 100.");
    }
    catch (exception& e)
    {
        cerr << "Error setting marks: " << e.what() << endl;
    }
}

void Grade::updateMarks()
{
    try
    {
        cout << "Update marks: ";
        if (!(cin >> marks))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Invalid input. Marks must be a number.");
        }
        if (marks < 0.0f || marks > 100.0f)
            throw invalid_argument("Marks must be between 0 and 100.");
    }
    catch (exception& e)
    {
        cerr << "Error updating marks: " << e.what() << endl;
    }
}

void Grade::displayGrade()
{
    try
    {
        cout << "---- Grade Details ----" << endl;
        cout << "Grade ID: " << gradeID << endl;

        if (student != nullptr)
            cout << "Student: " << student->getName() << endl;
        else
            cout << "Student: Not assigned" << endl;

        if (assignment != nullptr)
            cout << "Assignment ID: " << assignment->getAssignmentID() << endl;
        else
            cout << "Assignment: Not assigned" << endl;

        cout << "Marks: " << marks << endl;
    }
    catch (exception& e)
    {
        cerr << "Error displaying grade: " << e.what() << endl;
    }
}

void Grade::setGradeID(int id)
{
    try
    {
        if (id <= 0)
            throw invalid_argument("Grade ID must be positive.");
        gradeID = id;
    }
    catch (exception& e)
    {
        cerr << "Error setting Grade ID: " << e.what() << endl;
    }
}

int Grade::getGradeID()
{
    return gradeID;
}

void Grade::setStudent(Student* s)
{
    try
    {
        if (s == nullptr)
            throw invalid_argument("Student pointer is null.");
        student = s;
    }
    catch (exception& e)
    {
        cerr << "Error assigning student: " << e.what() << endl;
    }
}

Student* Grade::getStudent()
{
    return student;
}

void Grade::setAssignment(Assignment* a)
{
    try
    {
        if (a == nullptr)
            throw invalid_argument("Assignment pointer is null.");
        assignment = a;
    }
    catch (exception& e)
    {
        cerr << "Error assigning assignment: " << e.what() << endl;
    }
}

Assignment* Grade::getAssignment()
{
    return assignment;
}
