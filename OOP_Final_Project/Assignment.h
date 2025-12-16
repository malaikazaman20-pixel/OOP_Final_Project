#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include "Date.h"
#include "Student.h"
using namespace std;

class Assignment
{
private:
    int assignmentID;
    string description;
    Date dueDate;
    Student* submittedAssignments[100];
    int submissionCount;

public:
    Assignment();
    ~Assignment();

    void displayAssignmentDetails();// read data
    void addSubmission(Student* student);

    void setAssignmentID(int id);
    int getAssignmentID();

    void setDescription(string& desc);
    std::string getDescription();

    void setDueDate(int d, int m, int y);
    Date getDueDate();
};

#endif
