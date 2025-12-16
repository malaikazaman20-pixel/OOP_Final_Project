#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "User.h"
using namespace std;

class Course;
class Teacher;
class Student;

class Admin : public User
{
protected:
    int adminID;

public:
    Admin();
    ~Admin();

    int viewProfile();
    void updateProfile();
    string getName();

    void createUser();
    void createCourse(Course& course);
    void createStudent(Student& student);
    void createTeacher(Teacher& teacher);
    void addCourse(string& courseName);
    void addStudent(Student* student);
    void assignStudentToCourse(Student* student, Course* course);
    void assignTeacherToCourse(Teacher* teacher, Course* course);
    void generateReports(Student students[], int studentCount, Course courses[], int courseCount);
};

#endif
