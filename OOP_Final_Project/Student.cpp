#include "Student.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Student::Student() : studentID(0), courseCount(0), gradeCount(0) {}

Student::~Student() {}

int Student::viewProfile()
{
    try
    {
        cout << "Student Profile: " << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;

        cout << "Courses: " << endl;
        if (courseCount == 0)
            cout << "No courses enrolled." << endl;
        else
            for (int i = 0; i < courseCount; i++)
                cout << "- " << enrolledCourses[i] << endl;

        cout << "Grades: " << endl;
        if (gradeCount == 0)
            cout << "No grades available." << endl;
        else
            for (int i = 0; i < gradeCount; i++)
                cout << "Grade " << i + 1 << ": " << gradesList[i] << endl;

        return 1;
    }
    catch (exception& e)
    {
        cerr << "Error viewing profile: " << e.what() << endl;
        return -1;
    }
}

void Student::updateProfile()
{
    try
    {
        User::updateProfile();
    }
    catch (exception& e)
    {
        cerr << "Error updating profile: " << e.what() << endl;
    }
}


void Student::submitAssignment(string& courseName)
{
    try
    {
        if (courseName.empty())
            throw invalid_argument("Course name cannot be empty.");

        cout << "Submitting assignment for course: " << courseName << endl;
    }
    catch (exception& e)
    {
        cerr << "Error submitting assignment: " << e.what() << endl;
    }
}

void Student::viewGrades()
{
    try
    {
        cout << "Viewing grades..." << endl;
        if (gradeCount == 0)
            cout << "No grades available yet." << endl;
        else
            for (int i = 0; i < gradeCount; i++)
                cout << "Grade " << i + 1 << ": " << gradesList[i] << endl;
    }
    catch (exception& e)
    {
        cerr << "Error viewing grades: " << e.what() << endl;
    }
}

void Student::enrollCourse(string& courseName)
{
    try
    {
        if (courseName.empty())
            throw invalid_argument("Course name cannot be empty.");

        if (courseCount >= 100)
            throw invalid_argument("Course limit reached!");

        enrolledCourses[courseCount++] = courseName;
        cout << "Enrolled in course: " << courseName << endl;
    }
    catch (exception& e)
    {
        cerr << "Error enrolling course: " << e.what() << endl;
    }
}

void Student::addGrade(int& assignmentId, char grade)
{
    try
    {
        if (gradeCount >= 100)
            throw invalid_argument("Grade limit reached!");

        gradesList[gradeCount++] = grade;
        cout << "Grade for assignment '" << assignmentId << "': " << grade << endl;
    }
    catch (exception& e)
    {
        cerr << "Error adding grade: " << e.what() << endl;
    }
}

void Student::setStudentID(int id)
{
    try
    {
        if (id <= 0)
            throw invalid_argument("Student ID must be positive.");
        studentID = id;
    }
    catch (exception& e)
    {
        cerr << "Error setting student ID: " << e.what() << endl;
    }
}

int Student::getStudentID() 
{
    return studentID;
}

string Student::getName() 
{
    return name;
}
