#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "User.h"
#include "Student.h"
#include "Assignment.h"
using namespace std;

class Teacher : public User
{
protected:
    int teacherID;
    string listOfCourses[100];
    int courseCount;
    Student* students[100];
    int studentCount;

public:
    Teacher();
    ~Teacher();

    int viewProfile();
    void createAssignment(Assignment* assign); // write data 
    void gradeAssignment(Student* student, int& assignmentId, char grade);
    void setTeacherID(int id);
    int getTeacherID();
};

#endif
