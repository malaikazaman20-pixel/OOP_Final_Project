#ifndef GRADE_H
#define GRADE_H

#include <string>
using namespace std;

class Student;
class Assignment;

class Grade
{
protected:
    int gradeID;
    Student* student;
    Assignment* assignment;
    float marks;

public:
    Grade();
    ~Grade();

    void setMarks();
    void updateMarks();
    void displayGrade();

    void setGradeID(int id);
    int getGradeID();

    void setStudent(Student* s);
    Student* getStudent();

    void setAssignment(Assignment* a);
    Assignment* getAssignment();
};

#endif
