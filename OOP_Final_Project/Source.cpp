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
    void adminMenu(Admin & admin, Teacher & teacher, Student & student, Course & course, Semester & semester, FileHandling & file);
    void teacherMenu(Teacher & teacher, Student & student, Assignment & assignment, Communication & comm);
    void studentMenu(Student & student, Communication & comm, FileHandling & file);
    int roleChoice;

    Admin admin;
    Teacher teacher;
    Student student;
    Course course;
    Assignment assignment;
    Grade grade;
    Semester semester;
    Communication comm;
    FileHandling file;

    do
    {
        cout << "\nWelcome to Bahria University LMS!\n";
        cout << "Select Role:\n";
        cout << "0. Exit\n1. Admin\n2. Teacher\n3. Student\n";
        cin >> roleChoice;

        switch (roleChoice)
        {
        case 1:
            adminMenu(admin, teacher, student, course, semester, file);
            break;

        case 2:
            teacherMenu(teacher, student, assignment, comm);
            break;

        case 3:
            studentMenu(student, comm, file);
            break;

        case 0:
            cout << "Exiting LMS. Goodbye!\n";
            break;

        default:
            cout << "Invalid Role!\n";
        }

    } while (roleChoice != 0);

    return 0;
}
void adminMenu(Admin& admin, Teacher& teacher, Student& student, Course& course, Semester& semester, FileHandling& file)
{
    int choice;
    do 
    {
        cout << "\n--- ADMIN MENU ---\n";
        cout << "1. Create Course\n";
        cout << "2. Create Student\n";
        cout << "3. Create Teacher\n";
        cout << "4. Create Semester\n";
        cout << "5. Assign Student to Course\n";
        cout << "6. Assign Teacher to Course\n";
        cout << "7. View Semester Courses\n";
		cout << "8. Update Profile\n";
        cout << "9. View Profile\n";
        cout << "10. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 9:
            admin.viewProfile();
            break;
        case 1:
            admin.createCourse(course);
            break;
        case 2:
            admin.createStudent(student);
            break;
        case 3:
            admin.createTeacher(teacher);
            break;
        case 4:
            admin.createSemester(semester);
            break;
        case 5:
            admin.assignStudentToCourse(&student, &course);
            break;
        case 6:
            admin.assignTeacherToCourse(&teacher, &course);
            break;
        case 7:
            semester.viewSemesterCourses();
            break;
        case 8:
			admin.updateProfile();
            break;
        case 10:
            cout << "Admin logged out.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 10);
}

void teacherMenu(Teacher& teacher, Student& student, Assignment& assignment, Communication& comm)
{
    int choice;
    do 
    {
        cout << "\n--- TEACHER MENU ---\n";
        cout << "1. View Profile\n";
        cout << "2. Upload Assignment\n";
        cout << "3. Grade Assignment\n";
        cout << "4. View Messages\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            teacher.viewProfile();
            break;
        case 2:
        {
            teacher.createAssignment(&assignment);
            break;
        }
        case 3:
        {
            int id;
            char grade;
            cout << "Assignment id: ";
            cin >> id;
            cout << "Grade: ";
            cin >> grade;
            teacher.gradeAssignment(&student, id, grade);
            break;
        }
        case 4:
            comm.receiveMessage();
            break;
        case 5:
            cout << "Teacher logged out.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);
}
void studentMenu(Student& student, Communication& comm, FileHandling& file)
{
    int choice;
    do {
        cout << "\n--- STUDENT MENU ---\n";
        cout << "1. View Profile\n";
        cout << "2. View Course Content\n";
        cout << "3. Submit Assignment\n";
        cout << "4. View Grades\n";
        cout << "5. Messages\n";
        cout << "6. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            student.viewProfile();
            break;
        case 2:
            //student.viewCourseContent(course);
            break;
        case 3:
        {
            string courseName;
            cout << "Course name: ";
            cin >> courseName;
            student.submitAssignment(courseName);
            break;
        }
        case 4:
            student.viewGrades();
            break;
        case 5:
            comm.viewConversation();
            break;
        case 6:
            cout << "Student logged out.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);
}

