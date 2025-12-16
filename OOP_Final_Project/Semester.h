#ifndef SEMESTER_H
#define SEMESTER_H

#include <string>
#include "Course.h"
using namespace std;

class Semester
{
protected:
    int semesterID;
    string semesterName;
    Course courseList[100];
    int courseCount;

public:
    Semester();
    ~Semester();

    void addCourse(Course& course);
    void removeCourse(int courseID);
    void viewSemesterCourses();

    void setSemesterID(int id);
    int getSemesterID();

    void setSemesterName(string& name);
    string getSemesterName();
};

#endif
