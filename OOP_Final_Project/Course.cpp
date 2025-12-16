#include "Course.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Course::Course()
{
    courseID = 0;
    courseTitle = "";
    teacher = nullptr;
    studentCount = 0;
    assignmentCount = 0;
}

Course::~Course() {}

void Course::addStudent(Student* student)
{
    try
    {
        if (student == nullptr)
            throw invalid_argument("Student pointer is null.");

        if (studentCount >= 100)
            throw invalid_argument("Cannot add more students. Course is full.");

        studentList[studentCount++] = student;
        cout << "Student added to course: " << courseTitle << endl;
    }
    catch (exception& e)
    {
        cerr << "Error adding student: " << e.what() << endl;
    }
}

void Course::removeStudent(int studentID)
{
    try
    {
        bool found = false;
        for (int i = 0; i < studentCount; i++)
        {
            if (studentList[i]->getStudentID() == studentID)
            {
                found = true;
                for (int j = i; j < studentCount - 1; j++)
                    studentList[j] = studentList[j + 1];

                studentCount--;
                cout << "Student removed from course." << endl;
                break;
            }
        }
    }
    catch (exception& e)
    {
        cerr << "Error removing student: " << e.what() << endl;
    }
}

void Course::addAssignment(Assignment* assignment)
{
    try
    {
        if (assignment == nullptr)
            throw invalid_argument("Assignment pointer is null.");

        if (assignmentCount >= 100)
            throw invalid_argument("Cannot add more assignments.");

        assignmentList[assignmentCount++] = assignment;
        cout << "Assignment added to course: " << courseTitle << endl;
    }
    catch (exception& e)
    {
        cerr << "Error adding assignment: " << e.what() << endl;
    }
}

void Course::displayCourseDetails()
{
    try
    {
        cout << "---- Course Details ----" << endl;
        cout << "Course ID: " << courseID << endl;
        cout << "Course Title: " << courseTitle << endl;

        if (teacher != nullptr)
            cout << "Teacher Assigned: " << teacher->getName() << endl;
        else
            cout << "No teacher assigned." << endl;

        cout << "Enrolled Students: " << studentCount << endl;
        cout << "Assignments: " << assignmentCount << endl;
    }
    catch (exception& e)
    {
        cerr << "Error displaying course details: " << e.what() << endl;
    }
}

void Course::setCourseID(int id)
{
    try
    {
        if (id <= 0)
            throw invalid_argument("Course ID must be positive.");
        courseID = id;
    }
    catch (exception& e)
    {
        cerr << "Error setting course ID: " << e.what() << endl;
    }
}

int Course::getCourseID() 
{
    return courseID;
}

void Course::setCourseTitle(string& title)
{
    try
    {
        if (title.empty())
            throw invalid_argument("Course title cannot be empty.");
        courseTitle = title;
    }
    catch (exception& e)
    {
        cerr << "Error setting course title: " << e.what() << endl;
    }
}

string Course::getCourseTitle() 
{
    return courseTitle;
}

void Course::setTeacher(Teacher* t)
{
    try
    {
        if (t == nullptr)
            throw invalid_argument("Teacher pointer is null.");
        teacher = t;
    }
    catch (exception& e)
    {
        cerr << "Error assigning teacher: " << e.what() << endl;
    }
}

Teacher* Course::getTeacher() 
{
    return teacher;
}
