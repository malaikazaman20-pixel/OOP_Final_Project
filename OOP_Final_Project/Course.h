#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Teacher.h"
#include "Student.h"
#include "Assignment.h"
using namespace std;

class Course
{
private:
    int courseID;
    string courseTitle;
    Teacher* teacher;
    Student* studentList[100];
    Assignment* assignmentList[100];
    int studentCount;
    int assignmentCount;

public:
    Course();
    ~Course();

    void addStudent(Student* student);
    void removeStudent(int studentID);

    void addAssignment(Assignment* assignment);
    void displayCourseDetails();

    void setCourseID(int id);
    int getCourseID();

    void setCourseTitle(string& title);
    string getCourseTitle();

    void setTeacher(Teacher* t);
    Teacher* getTeacher();
};

#endif
