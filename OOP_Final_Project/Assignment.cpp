#include "Assignment.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Assignment::Assignment()
{
    assignmentID = 0;
    description = "";
    submissionCount = 0;
}

Assignment::~Assignment() {}

void Assignment::displayAssignmentDetails()
{
    try
    {
        cout << "Assignment ID: " << assignmentID << endl;
        cout << "Description: " << description << endl;
        cout << "Due Date: ";
        dueDate.show();
        cout << endl;
    }
    catch (exception& e)
    {
        cerr << "Error displaying assignment details: " << e.what() << endl;
    }
}

void Assignment::addSubmission(Student* student)
{
    try
    {
        if (student == nullptr)
            throw invalid_argument("Student pointer is null.");

        if (submissionCount >= 100)
            throw invalid_argument("Submission limit reached.");

        submittedAssignments[submissionCount++] = student;

        cout << "Assignment submitted by student: " << student->getName() << endl;
    }
    catch (exception& e)
    {
        cerr << "Error adding submission: " << e.what() << endl;
    }
}

void Assignment::setAssignmentID(int id)
{
    try
    {
        if (id <= 0)
            throw invalid_argument("Assignment ID must be positive.");

        assignmentID = id;
    }
    catch (const exception& e)
    {
        cerr << "Error setting assignment ID: " << e.what() << endl;
    }
}

int Assignment::getAssignmentID() 
{
    return assignmentID;
}

void Assignment::setDescription(string& desc)
{
    try
    {
        if (desc.empty())
            throw invalid_argument("Description cannot be empty.");

        description = desc;
    }
    catch (exception& e)
    {
        cerr << "Error setting description: " << e.what() << endl;
    }
}

string Assignment::getDescription()
{
    return description;
}

void Assignment::setDueDate(int d, int m, int y)
{
    try
    {
        dueDate.setDate(d, m, y);
    }
    catch (exception& e)
    {
        cerr << "Error setting due date: " << e.what() << endl;
    }
}

Date Assignment::getDueDate()
{
    return dueDate;
}
