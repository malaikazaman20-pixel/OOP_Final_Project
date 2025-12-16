#include <iostream>
#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"
#include "Course.h"
#include "Assignment.h"
#include "Communication.h"
#include "Semester.h"
#include "Grade.h"
#include "FileHandling.h"
using namespace std;

int main()
{
	int choice;
	cout << "Welcome to Bahria University LMS!\n";
	cout << "Enter your choice:  " << endl;
	cout << "1. Admin \n 2. Teacher \n 3. Student" << endl;;
	cin >> choice;

	Admin admin;
	Student student;
	Teacher	teacher;
	Course course;  
	Semester semester;
	Assignment assignment;
	Grade grade;
	Communication comm;
	FileHandling file;

	if (choice == 1)
		admin.updateProfile();
	else if (choice == 2)
		teacher.updateProfile();
	else if (choice == 3)
		student.updateProfile();

	int choice1;
	do {
		cout << "\n--- LMS Main Menu ---\n";
		cout << "1. View Profile\n";
		cout << "2. Courses\n";
		cout << "3. Assignments\n";
		cout << "4. Grades\n";
		cout << "5. Communication\n";
		cout << "6. Semester\n";
		cout << "7. File Handling\n";
		cout << "8. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice1;

		switch (choice1)
		{
		case 1:
			if (choice == 1)
				admin.viewProfile();
			else if (choice == 2)
				teacher.viewProfile();
			else if (choice == 3)
				student.viewProfile();
			break;
		case 2:
			if (choice == 1)
			{
				admin.createCourse(course);  // Create course and pass course object
				course.displayCourseDetails();
			}
			else if (choice == 2)
			{
				cout << "Your Courses:\n";
				teacher.viewProfile();  // Viewing teacher's profile to display assigned courses
			}
			else if (choice == 3)
			{
				cout << "Your Enrolled Courses:\n";
				student.viewProfile();  // Viewing student's profile to display enrolled courses
			}
			break;
		case 3:
			if (choice == 1)
			{
				cout << "Admin can view assignments\n";
			}
			else if (choice == 2)
			{
				string assignmentTitle;
				cout << "Enter Assignment Title: ";
				cin >> assignmentTitle;
				teacher.uploadAssignment(assignmentTitle);

				// Grading assignment
				string studentName;
				cout << "Enter student name to grade: ";
				cin >> studentName;
				char grade;
				cout << "Enter grade (A, B, C, etc.): ";
				cin >> grade;
				teacher.gradeAssignment(&student, assignmentTitle, grade);  // Pass actual student and assignment
			}
			else if (choice == 3)
			{
				student.viewCourseContent();
				string courseName;
				cout << "Enter course name for assignment submission: ";
				cin >> courseName;
				student.submitAssignment(courseName);
			}
			break;
		case 4:
			if (choice == 1)
			{
				cout << "Admin can generate grade reports\n";
			}
			else if (choice == 2)
			{
				string studentName, assignmentTitle;
				char grade;
				cout << "Enter student name: ";
				cin >> studentName;
				cout << "Enter assignment title: ";
				cin >> assignmentTitle;
				cout << "Enter grade: ";
				cin >> grade;
				teacher.gradeAssignment(&student, assignmentTitle, grade);
			}
			else if (choice == 3)
			{
				student.viewGrades();
			}
			break;
		case 5:
			if (choice == 1)
			{
				cout << "Admin messaging\n";
			}
			else if (choice == 2)
			{
				string receiver, message;
				cout << "Enter receiver: ";
				cin >> receiver;
				cout << "Enter message: ";
				cin.ignore();  // To ignore the newline after `cin >> receiver`
				getline(cin, message);  // To allow multi-word input for the message
				comm.sendMessage(admin.getName(), receiver, message);  // Pass the sender, receiver, and message
			}
			else if (choice == 3)
			{
				comm.receiveMessage();
			}
			break;
		case 6:
			if (choice == 1)
			{
				cout << "Admin can manage semesters\n";
			}
			else if (choice == 2)
			{
				semester.viewSemesterCourses();
			}
			else if (choice == 3)
			{
				semester.viewSemesterCourses();
			}
			break;
		case 7:
			if (choice == 1 || choice == 2)
			{
				string data;
				cout << "Enter data to save: ";
				cin.ignore();
				getline(cin, data);
				file.saveData(data);
			}
			else if (choice == 3)
			{
				file.readData();
			}
			break;
		case 8:
			cout << "Exiting LMS. Goodbye!\n";
			break;

		default:
			cout << "Invalid choice! Try again.\n";
		}
	} while (choice1 != 8);
	return 0;
}