#include "Teacher.h"
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

void Teacher::uploadAssignment(string& assignmentTitle)
{
    try
    {
        if (assignmentTitle.empty())
            throw invalid_argument("Assignment title cannot be empty.");
        cout << "Uploading assignment: " << assignmentTitle << endl;
    }
    catch (exception& e)
    {
        cerr << "Error uploading assignment: " << e.what() << endl;
    }
}

void Teacher::gradeAssignment(Student* student, string& assignmentTitle, char grade)
{
    try
    {
        if (student == nullptr)
            throw invalid_argument("Student pointer is null.");
        if (assignmentTitle.empty())
            throw invalid_argument("Assignment title cannot be empty.");

        std::cout << "Grading assignment '" << assignmentTitle
            << "' for student " << student->getName()
            << ". Grade: " << grade << std::endl;

        student->addGrade(assignmentTitle, grade);
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


