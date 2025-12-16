#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "User.h"
#include "Student.h"
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
    void uploadAssignment(string& assignmentTitle); // write data 
	void uploadMaterial(string& materialTitle); // save data
    void gradeAssignment(Student* student, string& assignmentTitle, char grade);
    void viewStudents();
    void setTeacherID(int id);
    int getTeacherID();
};

#endif
