#include "Admin.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include "Course.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;

Admin::Admin() 
{ 
    adminID = 0; 
}

Admin::~Admin() {}

int Admin::viewProfile()
{
    try
    {
        cout << "Admin Profile\n";
        cout << "Admin ID: " << adminID << "\n";
        cout << "Name: " << name << "\n";
        cout << "Email: " << email << "\n";
    }
    catch (exception& e)
    {
        cerr << "Error viewing profile: " << e.what() << endl;
        return 0;
    }
    return 1;
}

void Admin::updateProfile()
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

string Admin::getName()
{
    try
    {
        return User::getName();
    }
    catch (exception& e)
    {
        cerr << "Error getting admin name: " << e.what() << endl;
        return "";
    }
}

void Admin::createUser()
{
    try
    {
        cout << "Creating new user...\n";
        string uname, uemail;

        cout << "Enter name: ";
        cin.ignore();
        getline(cin, uname);
        if (uname.empty()) 
            throw invalid_argument("Name cannot be empty.");

        cout << "Enter email: ";
        cin >> uemail;
        if (uemail.empty()) 
            throw invalid_argument("Email cannot be empty.");

        cout << "User created successfully!\n";
    }
    catch (exception& e)
    {
        cerr << "Error creating user: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void Admin::createCourse(Course& course)
{
    try
    {
        cout << "Creating new course...\n";
        string title;
        int id;

        cout << "Enter course ID: ";
        cin >> id;
            
        cout << "Enter course title: ";
        getline(cin, title);
        if (title.empty()) 
            throw invalid_argument("Course title cannot be empty.");

        course.setCourseID(id);
        course.setCourseTitle(title);

        cout << "Course '" << title << "' created successfully!\n";
    }
    catch (exception& e)
    {
        cerr << "Error creating course: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}
void Admin::createStudent(Student& student)
{
    try
    {
        cout << "Creating new student...\n";
        string sname;
        int sid;

        cout << "Enter student ID: ";
        cin >> sid;

        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, sname);

        if (sname.empty())
            throw invalid_argument("Student name cannot be empty.");

        student.setStudentID(sid);
        student.setName(sname);

        cout << "Student '" << sname << "' created successfully!\n";
    }
    catch (exception& e)
    {
        cerr << "Error creating student: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void Admin::createTeacher(Teacher& teacher)
{
    try
    {
        cout << "Creating new teacher...\n";
        string tname;
        int tid;

        cout << "Enter teacher ID: ";
        cin >> tid;

        cin.ignore();
        cout << "Enter teacher name: ";
        getline(cin, tname);

        if (tname.empty())
            throw invalid_argument("Teacher name cannot be empty.");

        teacher.setTeacherID(tid);
        teacher.setName(tname);

        cout << "Teacher '" << tname << "' created successfully!\n";
    }
    catch (exception& e)
    {
        cerr << "Error creating teacher: " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void Admin::assignStudentToCourse(Student* student, Course* course)
{
    try
    {
        course->addStudent(student);

        cout << "Student " << student->getName()
            << " assigned to course: " << course->getCourseTitle() << endl;
    }
    catch (exception& e)
    {
        cerr << "Error assigning student to course: " << e.what() << endl;
    }
}


void Admin::assignTeacherToCourse(Teacher* teacher, Course* course)
{
    try
    {
        course->setTeacher(teacher);

        cout << "Teacher " << teacher->getName()
            << " assigned to course: " << course->getCourseTitle() << endl;
    }
    catch (exception& e)
    {
        cerr << "Error assigning teacher: " << e.what() << endl;
    }
}

void Admin::generateReports(Student students[], int studentCount, Course courses[], int courseCount)
{
    try
    {
        cout << "---- Report ----\n";

        cout << "Courses:\n";
        for (int i = 0; i < courseCount; i++)
        {
            cout << "- " << courses[i].getCourseTitle()<< " (ID: " << courses[i].getCourseID() << ")\n";
        }

        cout << "\nStudents:\n";
        for (int i = 0; i < studentCount; i++)
        {
            cout << "- " << students[i].getName()<< " (ID: " << students[i].getStudentID() << ")\n";
        }
    }
    catch (exception& e)
    {
        cerr << "Error generating report: " << e.what() << endl;
    }
}
