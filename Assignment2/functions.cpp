#include <iostream>
#include <fstream>
#include "course.h"
#include "university.h"
#include "functions.h"

using namespace std;

/*********************************************************************
** Function: welcome()
** Description: asks the user if theyre a student or a teacher
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: known if user is a student or a teacher
*********************************************************************/
int welcome() {
    int choice;
    bool go_again = true;

    cout << "Welcome to the school catalog!" << endl;
    cout << "If you are a teacher, you will be asked to login and verify you are a teacher." << endl;
    cout << "If you are a student, you will be immeadiately taken to the catalog." << endl;
    cout << "Are you a student or a teacher? Enter 1 for student or 2 for teacher." << endl;

    do {
        cin >> choice;
        if (choice == 1) {
            cout << "Taking you to the catalog..." << endl;
            return choice;
        }
        else if (choice == 2) {
            cout << "Taking you to the login..." << endl;
            go_again = false;
            return choice;
        }
        else {
            cout << "You did not enter 1 or 2! Please try again." << endl;
            go_again = true;
        }
    } while(go_again == true);

    return 0;
}
/*********************************************************************
** Function: teacher_options()
** Description: gives the teacher a few options
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: known what a teacher wants to do
*********************************************************************/
int teacher_options() {
    int choice;
    bool go_beavs = true;

    cout << "welcome to the teacher catalog!" << endl;
    do {
        cout << "Enter 1 to change a courses info" << endl;
        cout << "Enter 2 to add or remove a course" << endl;
        cout << "Enter 3 to add or remove a student from a course" << endl;
        cout << "Enter 4 to view enrollment in the university and see the address" << endl;
        cout << "Enter 5 to quit the program" << endl;

        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5) {
            return choice;
        }
        else {
            go_beavs = true;
            cout << "You did not enter an available option! Please try again." << endl;
        }
    } while (go_beavs == true);

    return 0;
}
/*********************************************************************
** Function: print_teacher_options()
** Description: prints what a teacher can change about a course
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: what aspect of the course a techer wants to change is known
*********************************************************************/
int print_teacher_options() {

    int option;

    cout << "Which element of the course would like to change?" << endl;
    cout << "Enter 1 for course name" << endl;
    cout << "Enter 2 for teacher name" << endl;
    cout << "Enter 3 for term" << endl;
    cout << "Enter 4 for days" << endl;
    cout << "Enter 5 for start time" << endl;
    cout << "Enter 6 for end time" << endl;
    cout << "Enter 7 for location" << endl;
    cout << "Enter 8 for current enrollment" << endl;

    cin >> option;
    return option;
}
/*********************************************************************
** Function: get_students_choice()
** Description: gets what the student wants to do
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: what the student wants to do is known
*********************************************************************/
int get_students_choice() {
    int student_choice;

    cout << "Welcome to the student catalog!" << endl;
    cout << "Enter 1 to search the catalog by term" << endl;
    cout << "Enter 2 to search the catalog by time(s)" << endl;
    cout << "Enter 3 to enroll in a class" << endl;
    cin >> student_choice;

    if (student_choice == 1 || student_choice == 2 || student_choice == 3) {
        return student_choice;
    }
    else {
        cout << "invalid choice made" << endl;
    }

    return 0;
}

/*********************************************************************
** Function: view_or_remove_students()
** Description: allows a teacher to view or remove a student from a class
** Parameters: University object reference
** Pre-Conditions: n/a 
** Post-Conditions: teacher has added or removed students
*********************************************************************/
void view_or_remove_students(University &U1) {
    int choice;

    cout << "Do you want to view or remove students from a course? Enter 1 for view or 2 for remove." << endl;
    cin >> choice;

    if (choice == 1) {
        U1.view_students();
    }
    else if (choice == 2) {
        U1.remove_student();
    }
}

/*********************************************************************
** Function: add_or_remove_course()
** Description: allows a teacher to to add or remove a course
** Parameters: University object refernce
** Pre-Conditions: n/a 
** Post-Conditions: course is added or removed
*********************************************************************/
void add_or_remove_course(University &U1) {
    int choice;
    Course newcourse;

    cout << "Do you want to add or remove a course? Enter 1 to add or 2 to remove." << endl;
    cin >> choice;

    if (choice == 1) {
        newcourse = U1.get_new_course_info();
    }
    else if (choice == 2) {
        U1.remove_from_catalog();
    }
}
/*********************************************************************
** Function: all_actions()
** Description: calls all functions that a student or teacher could access
** Parameters: university object reference
** Pre-Conditions: n/a 
** Post-Conditions: n/a
** Justification for length: This is the function that calls in all other functions and is
** the menu so i did not want to split up the menu in other areas
*********************************************************************/
void all_actions(University &U1) {
    int firstChoice;
    int secondChoice;
    int thirdChoice;
    char choice;
    bool go_again = true;

    do {
        firstChoice = welcome();

        if (firstChoice == 1) {
            U1.all_student_options(get_students_choice());
        }
        else if (firstChoice == 2) {
            U1.teacher_login();
            secondChoice = teacher_options();
            if (secondChoice == 1) {
                thirdChoice = print_teacher_options();
                U1.all_teacher_options(thirdChoice);
            }
            else if (secondChoice == 2) {
                add_or_remove_course(U1);
                
            }
            else if (secondChoice == 3) {
                view_or_remove_students(U1);
            }
            else if (secondChoice == 4) {
                U1.view_enrollment_and_address(U1);
            }
            else if (secondChoice == 5) {
                exit(0);
            }
        }
        cout << "Do you want to run through this catalog again? (y or n)" << endl;
        cin >> choice;

        if (choice == 'y'|| choice == 'Y') {
            go_again = true;
        }
        else {
            cout << "Thanks for using the catalog!" << endl;
            go_again = false;
        }

    } while (go_again == true);

}
