#include "Semester.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Semester::Semester() : semesterID(0), semesterName(""), courseCount(0) {}
Semester::~Semester() {}

void Semester::addCourse(Course& course)
{
    try
    {
        if (courseCount >= 100)
            throw invalid_argument("Cannot add more courses. Semester limit reached.");

        courseList[courseCount++] = course;
        cout << "Course added to semester: " << semesterName << endl;
    }
    catch (exception& e)
    {
        cerr << "Error adding course: " << e.what() << endl;
    }
}

void Semester::removeCourse(int courseID)
{
    try
    {
        if (courseCount == 0)
            throw invalid_argument("No courses in this semester.");

        bool found = false;
        for (int i = 0; i < courseCount; i++)
        {
            if (courseList[i].getCourseID() == courseID)
            {
                found = true;
                for (int j = i; j < courseCount - 1; j++)
                    courseList[j] = courseList[j + 1];
                courseCount--;
                cout << "Course removed from semester." << endl;
                break;
            }
        }

        if (!found)
            throw invalid_argument("Course not found in semester.");
    }
    catch (exception& e)
    {
        cerr << "Error removing course: " << e.what() << endl;
    }
}

void Semester::viewSemesterCourses()
{
    try
    {
        cout << "---- Semester Courses ----" << endl;
        if (courseCount == 0)
            cout << "No courses available in this semester." << endl;
        else
            for (int i = 0; i < courseCount; i++)
                courseList[i].displayCourseDetails();
    }
    catch (exception& e)
    {
        cerr << "Error viewing courses: " << e.what() << endl;
    }
}

void Semester::setSemesterID(int id)
{
    try
    {
        if (id <= 0)
            throw invalid_argument("Semester ID must be positive.");
        semesterID = id;
    }
    catch (exception& e)
    {
        cerr << "Error setting semester ID: " << e.what() << endl;
    }
}

int Semester::getSemesterID()
{
    return semesterID;
}

void Semester::setSemesterName(string& name)
{
    try
    {
        if (name.empty())
            throw invalid_argument("Semester name cannot be empty.");
        semesterName = name;
    }
    catch (const exception& e)
    {
        cerr << "Error setting semester name: " << e.what() << endl;
    }
}

string Semester::getSemesterName()
{
    return semesterName;
}
