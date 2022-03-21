#include "course.h"
#include "TeachersAndSchedule.h"
#include "university.h"

using namespace std;
/*********************************************************************
** Function: course()
** Description: course class default constructor
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: class object is created and set values
*********************************************************************/ 
//1
Course::Course() {
    this->name = " ";
    this->teacher = " ";
    this->current_enrollment = 0;
    this->roster = nullptr;
    this->course_time = nullptr;
}
/*********************************************************************
** Function: course(w/parameters)
** Description: course class constructor
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: class object is created and set actual values
*********************************************************************/ 
//2
Course::Course(string name, string teacher, int current_enrollment, string* roster, schedule* course_time) {
    this->name = name;
    this->teacher = teacher;
    this->current_enrollment = current_enrollment;
    this->roster = roster;
    this->course_time = course_time;
}
/*********************************************************************
** Function: ~course()
** Description: course class destructor
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: class object is destroyed
*********************************************************************/ 
//3
Course::~Course() {
    //cout << "Course Destructor called" << endl;
    delete [] roster;
    //cout << "deletes roster" << endl;
    delete course_time;
}
/*********************************************************************
** Function: course()
** Description: course class copy constructor
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: class object is copied over
*********************************************************************/ 
//4
Course::Course(const Course& that) {
    this->name = that.name;
    this->teacher = that.teacher;
    this->current_enrollment = that.current_enrollment;
    this->roster = that.roster;
    this->course_time = that.course_time;

    for (int i = 0; i < this->current_enrollment; i++) {
        this->roster[i] = that.roster[i];
    }

    for (int i = 0; i < this->num_courses; i++) {
        this->course_time[i] = that.course_time[i];
    }
}
/*********************************************************************
** Function: course()
** Description: course class assignment operator overload
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: = is overloaded for the course class
*********************************************************************/ 
//5
Course& Course::operator=(const Course& that) {
    this->name = that.name;
    this->teacher = that.teacher;
    this->current_enrollment = that.current_enrollment;
    this->roster = that.roster;
    this->course_time = that.course_time;

    for (int i = 0; i < this->current_enrollment; i++) {
        this->roster[i] = that.roster[i];
    }

    for (int i = 0; i < this->num_courses; i++) {
        this->course_time[i] = that.course_time[i];
    }
}
/*********************************************************************
** Function: Course::set_name()
** Description: course class name setter
** Parameters: string
** Pre-Conditions: n/a 
** Post-Conditions: course's name is set
*********************************************************************/ 
//6
void Course::set_name(string name) {
    this->name = name;
}
/*********************************************************************
** Function: Course::get_name()
** Description: course class name getter
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course's name has been gotten
*********************************************************************/ 
//7
string Course::get_name() {
    return this->name;
}
/*********************************************************************
** Function: Course::set_teacher()
** Description: course class teacher setter
** Parameters: string
** Pre-Conditions: n/a 
** Post-Conditions: course's teacher is set
*********************************************************************/ 
//8
void Course::set_teacher(string instructor) {
    this->teacher = instructor;
}
/*********************************************************************
** Function: Course::get_teacher()
** Description: course class teacher getter
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course's teacher has been gotten
*********************************************************************/
//9
string Course::get_teacher() {
    return this->teacher;
}
/*********************************************************************
** Function: Course::set_current_enrollment()
** Description: course class enrollment setter
** Parameters: string
** Pre-Conditions: n/a 
** Post-Conditions: course's current enrollment is set
*********************************************************************/ 
//10
void Course::set_current_enrollment(int current_enrollment) {
    this->current_enrollment = current_enrollment;
}
/*********************************************************************
** Function: Course::get_current_enrollment()
** Description: course class current enrollment getter
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course's current enrollment has been gotten
*********************************************************************/
//11
int Course::get_current_enrollment() {
    return this->current_enrollment;
}
/*********************************************************************
** Function: Course::set_roster()
** Description: course class roster setter
** Parameters: string array
** Pre-Conditions: n/a 
** Post-Conditions: course's roster is set
*********************************************************************/ 
//12
void Course::set_roster(string* roster) {
    this->roster = roster;
}
/*********************************************************************
** Function: Course::get_roster()
** Description: course class roster getter
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course's roster has been gotten
*********************************************************************/
//13
string Course::get_roster(int x) {
    return this->roster[x];
}
/*********************************************************************
** Function: Course::set_num_courses()
** Description: course class number of courses setter
** Parameters: int
** Pre-Conditions: n/a 
** Post-Conditions: number of courses in university is set
*********************************************************************/ 
//14
void Course::set_num_courses(int num_courses) {
    this->num_courses = num_courses;
}
/*********************************************************************
** Function: Course::get_num_courses()
** Description: course class number of courses getter
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: number of courses has been gotten
*********************************************************************/
//15
int Course::get_num_courses() {
    return this->num_courses;
}
/*********************************************************************
** Function: Course::set_course_time()
** Description: course class schedule array setter
** Parameters: string
** Pre-Conditions: n/a 
** Post-Conditions: array of schedules is set
*********************************************************************/ 
//16
void Course::set_course_time(schedule* course_time) {
    this->course_time = course_time;
}
/*********************************************************************
** Function: Course::get_course_time()
** Description: course class course time getter
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course's course times have been gotten
*********************************************************************/
//17
schedule* Course::get_course_time() {
    return this->course_time;
}
//18
void Course::change_course_time(schedule* course_time) {

}
/*********************************************************************
** Function: Course::enroll_student()
** Description: allows a student to enroll in a class
** Parameters: string
** Pre-Conditions: n/a 
** Post-Conditions: student will be added to the enrollment.txt file
*********************************************************************/
//19
void Course::enroll_student(string new_student) {
    string course_to_enroll_in;
    string student_name;
    ofstream open_enrollment("enrollment.txt", ios::app);

    int studentID;

    cout << "What course would like to enroll in?" << endl;
    cin >> course_to_enroll_in;

    cout << "Enter your name (first_last): " << endl;
    cin >> student_name;

    cout << "Enter your ID: " << endl;
    cin >> studentID;

    open_enrollment << "\n" << student_name << " " << studentID << " " << course_to_enroll_in;

    open_enrollment.close();

}
/*********************************************************************
** Function: Course::info_into_courses()
** Description: fills course array with the courses info
** Parameters: fstream reference
** Pre-Conditions: n/a 
** Post-Conditions: array of courses is full of info
*********************************************************************/
void Course::info_into_courses(fstream& read_from_courses) {
    read_from_courses >> name;
    read_from_courses >> teacher;
    
    course_time = new schedule;

    read_from_courses >> course_time->term;
    read_from_courses >> course_time->days;
    read_from_courses >> course_time->start_time;
    read_from_courses >> course_time->end_time;
    read_from_courses >> course_time->location;

    read_from_courses >> current_enrollment;

    this->roster = new string[current_enrollment];

    for (int i = 0; i < current_enrollment; i++) {
        read_from_courses >> roster[i];
    }
}