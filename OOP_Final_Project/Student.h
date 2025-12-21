
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "User.h"
using namespace std;

class Student : public User
{
protected:
    int studentID;
    string enrolledCourses[100];
    char gradesList[100];
    int courseCount;
    int gradeCount;


public:
    Student();
    ~Student();

    int viewProfile();
	void updateProfile();
    void submitAssignment(string& courseName);
    void viewGrades();
    void enrollCourse(string& courseName);
    void addGrade(int& assignmentId, char grade);
    void setStudentID(int id);
    int getStudentID();
    string getName();
};

#endif
