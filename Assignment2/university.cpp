#include <fstream>
#include "university.h"
#include "functions.h"

/*********************************************************************
** Function: University::University()
** Description: University default constructor
** Parameters: n/a
** Pre-Conditions: University object created
** Post-Conditions: University oibject with base values
*********************************************************************/ 
//1
University::University() {
    
    name = " ";
    address = " ";
    current_term = " ";
    teachers = nullptr;
    num_courses = 0;
    courses = nullptr;
    
}
/*********************************************************************
** Function: University::University(w/parameters)
** Description: Constructor for University object
** Parameters: string, string, string, teacher*, int, Course*
** Pre-Conditions: University created
** Post-Conditions: University object with actual values
*********************************************************************/ 
//2
University::University(string name, string address, string current_term, teacher* teachers, int num_courses, Course* courses) {
    

}
//3
/*********************************************************************
** Function: University::~University()
** Description: University destructor
** Parameters: n/a
** Pre-Conditions: University object made
** Post-Conditions: Univeristy object destroyed
*********************************************************************/ 
University::~University() {
    //cout << "University Destructor called" << endl;
    delete [] teachers;
    delete [] courses;
}
//4
/*********************************************************************
** Function: University::University(const University& that)
** Description: University copy constructor
** Parameters: University object reference
** Pre-Conditions: University object made
** Post-Conditions: copied university object
*********************************************************************/ 
University::University(const University& that) {
    this->name = that.name;
    this->address = that.address;
    this->current_term = that.current_term;
    this->teachers = that.teachers;
    this->num_teachers = that.num_teachers;
    this->num_courses = that.num_courses;
    this->courses = that.courses;

    for (int i = 0; i < that.num_teachers; i++) {
        this->teachers[i] = that.teachers[i];
    }

    for (int i = 0; i < that.num_courses; i++) {
        this->courses[i] = that.courses[i];
    }
}
/*********************************************************************
** Function: University& University::operator=(const University& that)
** Description: University clas operator overload
** Parameters: University reference
** Pre-Conditions: University object made
** Post-Conditions: University copied
*********************************************************************/ 
//5
University& University::operator=(const University& that) {
    this->name = that.name;
    this->address = that.address;
    this->current_term = that.current_term;
    this->teachers = that.teachers;
    this->num_teachers = that.num_teachers;
    this->num_courses = that.num_courses;
    this->courses = that.courses;

    for (int i = 0; i < that.num_teachers; i++) {
        this->teachers[i] = that.teachers[i];
    }

    for (int i = 0; i < that.num_courses; i++) {
        this->courses[i] = that.courses[i];
    }
}
/*********************************************************************
** Function: University::set_uni_name()
** Description: University name setter
** Parameters: string
** Pre-Conditions: n/a
** Post-Conditions: name set
*********************************************************************/ 
//6
void University::set_Uni_name(const string name) {
    this->name = name;
}
/*********************************************************************
** Function: University::get_uni_name
** Description: University name getter
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: university name gotten
*********************************************************************/ 
//7
string University::get_uni_name() {
    return this->name;
}
/*********************************************************************
** Function: University::set_address()
** Description: University address setter
** Parameters: string
** Pre-Conditions: n/a
** Post-Conditions: address set
*********************************************************************/ 
//8
void University::set_address(string address) {
    this->address = address;
}
/*********************************************************************
** Function: University::get_address()
** Description: University address getter
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: university address gotten
*********************************************************************/ 
//9
string University::get_address() {
    return this->address;
}
/*********************************************************************
** Function: University::set_current_term()
** Description: University current term setter
** Parameters: string
** Pre-Conditions: n/a
** Post-Conditions: current term set
*********************************************************************/ 
//10
void University::set_current_term(string current_term) {
    this->current_term = current_term;
}

/*********************************************************************
** Function: University::get_current_term
** Description: gets universities current term
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: university term gotten
*********************************************************************/ 
//11
string University::get_current_term() {
    return this->current_term;
}
/*********************************************************************
** Function: University::set_teachers()
** Description: University teacher array setter
** Parameters: teacher*
** Pre-Conditions: n/a
** Post-Conditions: teacher array set
*********************************************************************/ 
//12
void University::set_teachers(teacher* teachers) {
    this->teachers = teachers;
}
/*********************************************************************
** Function: University::get_teachers
** Description: University teacher getter
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: university teachers gotten
*********************************************************************/ 
//13
teacher* University::get_teachers() {
    return this->teachers;
}
/*********************************************************************
** Function: University::set_num_teachers()
** Description: University number of techers setter
** Parameters: int
** Pre-Conditions: n/a
** Post-Conditions: number of teachers set
*********************************************************************/ 
//14
/*
void University::set_num_teachers(int num_teachers) {
    string test;
    fstream fin;
    int num_teachers = 0;

    fin.open("teachers.txt");

    while (getline(fin, test)) {
        num_teachers++;
    }

    fin.close();
}
*/
/*********************************************************************
** Function: University::get_num_teachers()
** Description: Gets number of teachers in the university
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: number of teachers gotten
*********************************************************************/ 
//15
int University::get_num_teachers() {
    string test;
    fstream fin;
    int num_teachers = 0;

    fin.open("teachers.txt");

    while (getline(fin, test)) {
        num_teachers++;
    }

    fin.close();
    return num_teachers;
}
//16
/*
void University::set_num_courses(int num_courses) {
    this->num_courses = num_courses;
}
*/
/*********************************************************************
** Function: University::get_num_courses()
** Description: Gets the number of courses for the university
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: number of courses gotten
*********************************************************************/ 
//17
void University::get_num_courses() {
    string line;
    fstream fin2;
    fin2.open("courses.txt");

    while (getline(fin2, line)) {
        num_courses++;
    }
    fin2.close();
}
/*********************************************************************
** Function: University::set_courses()
** Description: setter for course array
** Parameters: Course*
** Pre-Conditions: n/a
** Post-Conditions: Course array set
*********************************************************************/ 
//18
void University::set_courses(Course* courses) {
    this->courses = courses;
}
/*********************************************************************
** Function: University::get_courses()
** Description: gets a course array for the university
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: array of courses gotten
*********************************************************************/ 
//19
Course* University::get_courses() {
    return this->courses;
}

/*********************************************************************
** Function: University::add_to_catalog()
** Description: adds course to catalog
** Parameters: Course object
** Pre-Conditions: n/a
** Post-Conditions: new course made
*********************************************************************/ 
//22
void University::add_to_catalog(Course course_to_add) {
    
}

/*********************************************************************
** Function: University::get_uni_info()
** Description: gets the info for the university
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: all member variables of the university are retrieved
*********************************************************************/ 
//24
void University::get_uni_info() {
    fstream fin_from_uni;
    string var;

    fin_from_uni.open("university.txt");

    getline(fin_from_uni, var);
    set_Uni_name(var);
    getline(fin_from_uni, var);
    set_address(var);
    getline(fin_from_uni, var);
    set_current_term(var);

    this->num_teachers = get_num_teachers();
    get_num_courses();

    fin_from_uni.close();
    return;
}

/*********************************************************************
** Function: University::create_teacher_arr()
** Description: dynamically creates teacher array
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
//25
teacher* University::create_teacher_arr() {
    teacher* teacher_arr = new teacher [num_teachers];
    return teacher_arr;
}
/*********************************************************************
** Function: create_course_arr()
** Description: creates a dynamic array of courses
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: n/a
*********************************************************************/ 
void University::create_course_arr() {
    courses = new Course [num_courses];
}
/*********************************************************************
** Function: get_teacher_info()
** Description: loops through the array of teachers and fills in all of the info
** Parameters: teacher*
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void University::get_teacher_info(teacher* teacher_arr) {
    fstream fin_from_teacher;
    fin_from_teacher.open("teachers.txt");

    for (int i = 0; i < num_teachers; i++) {
        fin_from_teacher >> teacher_arr[i].id;
        fin_from_teacher >> teacher_arr[i].password;
        fin_from_teacher >> teacher_arr[i].first_name;
        fin_from_teacher >> teacher_arr[i].last_name;
    }
    fin_from_teacher.close();
}
/*********************************************************************
** Function: populate_courses()
** Description: loops through the array of courses and fills in info
** Parameters: fstream reference
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/ 
void University::populate_courses(fstream &read_from_courses) {
    create_course_arr();
    read_from_courses.open("courses.txt");
    for (int i = 0; i < num_courses; i++) {
        courses[i].info_into_courses(read_from_courses);
    }
    //cout << "In the populate course array function," << courses[4].get_name() << endl;
}
/*********************************************************************
** Function: get_all_info()
** Description: gets all info for the university object
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: all info is taken
*********************************************************************/ 
void University::get_all_info() {
    fstream read_from_courses;
    get_uni_info();
    create_teacher_arr();
    create_course_arr();
    get_teacher_info(create_teacher_arr());
    populate_courses(read_from_courses);
}
/*********************************************************************
** Function: teacher_login()
** Description: teacher login system
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: teacher either logs in or quits the program
*********************************************************************/ 
void University::teacher_login() {
    fstream read_for_login("teachers.txt");
    string attemptID;
    string attemptPassword;
    bool do_again = true;
    teacher* teacher_arr = new teacher [num_teachers];

    for (int i = 0; i < num_teachers; i++) {
        read_for_login >> teacher_arr[i].id;
        read_for_login >> teacher_arr[i].password;
        read_for_login >> teacher_arr[i].first_name;
        read_for_login >> teacher_arr[i].last_name;

    }
    
    do {
        cout << "Please enter your ID:\n";
        cin >> attemptID;
        cout << "Please enter your password:\n";
        cin >> attemptPassword;

        for (int i = 0; i < 3; i++) {
            if (stoi(attemptID) == teacher_arr[i].id) {
                if (attemptPassword == teacher_arr[i].password) {
                    do_again = false;
                    cout << "Correct! Taking you to the catalog..." << endl;
                }
            }
        }
        if (do_again == true) {    
            cout << "You did not enter the correct ID and password. Please try again." << endl;
            do_again = true;
        }
        
        
    } while (do_again == true);
}
/*********************************************************************
** Function: search_courses_by_term()
** Description: allows a student to search the catalog by term
** Parameters: string
** Pre-Conditions: n/a
** Post-Conditions: courses are sorted by term
*********************************************************************/ 
void University::search_courses_by_term(string term) {
    cout << "Courses that are offered in " << term << ":" << endl;
    
    for (int i = 0; i < num_courses; i++) {
        if (courses[i].get_course_time()->term == term) {
            cout << courses[i].get_name() << endl;
        }
    }
}
/*********************************************************************
** Function: search_courses_by_times()
** Description: allows a student to search the catalog by time(s)
** Parameters: array of times and a number of times
** Pre-Conditions: n/a
** Post-Conditions: classes are sorted by times the user entered
*********************************************************************/ 
void University::search_courses_by_times(string* time_arr, int num_times) {
    cout << "How many different times do you want to filter by?" << endl;
    cin >> num_times;

    time_arr = new string [num_times];

    for (int i = 0; i < num_times; i++) {
        cout << "Enter time " << i+1 << ":" << endl;
        cin >> time_arr[i];
    }

    for (int i = 0; i < num_courses; i++) {
        for (int j = 0; j < num_times; j++) {
            if (courses[i].get_course_time()->start_time == time_arr[j]) {
                cout << courses[i].get_name() << " is offered at " << courses[i].get_course_time()->start_time << " with " << courses[i].get_teacher() << endl;
            }
        }
    }
}
/*********************************************************************
** Function: all_student_options()
** Description: calls all functions that a student could access
** Parameters: int
** Pre-Conditions: n/a 
** Post-Conditions: what the student wants to do
*********************************************************************/ 
void University::all_student_options(int choice) {
    string term;
    string* times;
    int num_times = 0;
    string new_student;

    if (choice == 1) {
        cout << "Which term would like to filter by?" << endl;
        cin >> term;

        University::search_courses_by_term(term);
    }
    else if (choice ==2 ) {
        University::search_courses_by_times(times, num_times);
    }
    else if (choice == 3) {
        courses->enroll_student(new_student);
    }
}
/*********************************************************************
** Function: change_course_name()
** Description: allows a teacher to change a course name
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course name is changed
*********************************************************************/ 
void University::change_course_name() {
    string course_to_change;
    string newname;

    cout << "Which course would you like to change?" << endl;
    cin >> course_to_change;
    cout << "What do you want to change the name to?" << endl;
    cin >> newname;

    for (int i = 0; i < num_courses; i++) {
        if (course_to_change == courses[i].get_name()) {
            courses[i].set_name(newname);
        }
    }
}
/*********************************************************************
** Function: change_teacher_name()
** Description: allows a teacher to change a teacher name
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: teacher name is changed for a certain course
*********************************************************************/ 
void University::change_teacher_name() {
    string course_to_change;
    string newteacher;

    cout << "Which course would you like to change?" << endl;
    cin >> course_to_change;
    cout << "What do you want to change the name of the teacher to?" << endl;
    cin >> newteacher;

    for (int i = 0; i < num_courses; i++) {
        if (course_to_change == courses[i].get_name()) {
            courses[i].set_teacher(newteacher);
        }
    }
}
/*********************************************************************
** Function: change_course_term()
** Description: allows a teacher to change a course term
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course term is changed
*********************************************************************/ 
void University::change_course_term() {
    string course_to_change;
    string newterm;

    cout << "Which course would you like to change?" << endl;
    cin >> course_to_change;
    cout << "What do you want to change the term to?" << endl;
    cin >> newterm;

    for (int i = 0; i < num_courses; i++) {
        if (course_to_change == courses[i].get_name()) {
            courses[i].get_course_time()->term = newterm;
        }
    }
}
/*********************************************************************
** Function: change_course_days()
** Description: allows a teacher to change the days a course is offered
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course days are changed
*********************************************************************/ 
void University::change_course_days() {
    string course_to_change;
    string newdays;

    cout << "Which course would you like to change?" << endl;
    cin >> course_to_change;
    cout << "What do you want to change the days to?" << endl;
    cin >> newdays;

    for (int i = 0; i < num_courses; i++) {
        if (course_to_change == courses[i].get_name()) {
            courses[i].get_course_time()->days = newdays;
        }
    }
}
/*********************************************************************
** Function: change_course_start_time()
** Description: allows a teacher to change a course start time
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course start time is changed
*********************************************************************/ 
void University::change_course_start_time() {
    string course_to_change;
    string newstarttime;

    cout << "Which course would you like to change?" << endl;
    cin >> course_to_change;
    cout << "What do you want to change the start time to?" << endl;
    cin >> newstarttime;

    for (int i = 0; i < num_courses; i++) {
        if (course_to_change == courses[i].get_name()) {
            courses[i].get_course_time()->start_time = newstarttime;
        }
    }
}
/*********************************************************************
** Function: change_course_end_time()
** Description: allows a teacher to change the courses end time
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course end time is changed
*********************************************************************/ 
void University::change_course_end_time() {
    string course_to_change;
    string newendtime;

    cout << "Which course would you like to change?" << endl;
    cin >> course_to_change;
    cout << "What do you want to change the end time to?" << endl;
    cin >> newendtime;

    for (int i = 0; i < num_courses; i++) {
        if (course_to_change == courses[i].get_name()) {
            courses[i].get_course_time()->end_time = newendtime;
        }
    }
}
/*********************************************************************
** Function: change_course_location()
** Description: allows a teacher to change the location of the course
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course location is changed
*********************************************************************/ 
void University::change_course_location() {
    string course_to_change;
    string newlocation;

    cout << "Which course would you like to change?" << endl;
    cin >> course_to_change;
    cout << "What do you want to change the location to?" << endl;
    cin >> newlocation;

    for (int i = 0; i < num_courses; i++) {
        if (course_to_change == courses[i].get_name()) {
            courses[i].get_course_time()->end_time = newlocation;
        }
    }
}
/*********************************************************************
** Function: change_course_enrollment()
** Description: allows a teacher to change the enrollment in a course
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: course enrollment is changed
*********************************************************************/ 
void University::change_course_enrollment() {
    string course_to_change;
    int newenrollment;

    cout << "Which course would you like to change?" << endl;
    cin >> course_to_change;
    cout << "What do you want to change the enrollment to?" << endl;
    cin >> newenrollment;

    for (int i = 0; i < num_courses; i++) {
        if (course_to_change == courses[i].get_name()) {
            newenrollment = courses[i].get_current_enrollment();
        }
    }
}

/*********************************************************************
** Function: University::remove_from_catalog()
** Description: removes course from catalog
** Parameters: int
** Pre-Conditions: n/a
** Post-Conditions: course removed from catalog
*********************************************************************/ 
void University::remove_from_catalog() {
    int index_of_course;

    cout << "What index of course do you want to remove?" << endl;
    cin >> index_of_course;
    
    courses[index_of_course].get_name() = " ";
    courses[index_of_course].get_teacher() = " ";
    courses[index_of_course].get_course_time()->term = " ";
    courses[index_of_course].get_course_time()->days = " ";
    courses[index_of_course].get_course_time()->start_time = " ";
    courses[index_of_course].get_course_time()->end_time = " ";
    courses[index_of_course].get_course_time()->location = " ";
    
    for (int i = 0; i < courses[index_of_course].get_current_enrollment(); i++) {
        
    }

}
/*********************************************************************
** Function: all_teacher_options()
** Description: calls all teacher options depending on what the enter
** Parameters: int
** Pre-Conditions: n/a 
** Post-Conditions: n/a
*********************************************************************/ 
void University::all_teacher_options(int option) {
    if (option == 1) {
        change_course_name();
    }
    else if (option == 2) {
        change_teacher_name();
    }
     else if (option == 3) {
        change_course_term();
    }
     else if (option == 4) {
        change_course_days();
    }
     else if (option == 5) {
        change_course_start_time();
    }
     else if (option == 6) {
        change_course_end_time();
    }
     else if (option == 7) {
        change_course_location();
    }
     else if (option == 8) {
        change_course_enrollment();
    }
    
}

/*********************************************************************
** Function: print_new_courses()
** Description: prints the new courses after the user is done making changes
** Parameters: n/a
** Pre-Conditions: n/a 
** Post-Conditions: courses.txt file will be overwritten with the new info
*********************************************************************/ 
void University::print_new_courses() {
    //remove("courses.txt"); 
    ofstream newfile("courses.txt");
    

    if (newfile.is_open() == true) {
        cout << "New file under same name is open!" << endl;
    }

    for (int i = 0; i < num_courses; i++) {
        newfile << courses[i].get_name() << " " << courses[i].get_teacher() << " " << courses[i].get_course_time()->term << " " << courses[i].get_course_time()->days << " " << courses[i].get_course_time()->start_time << " " << courses[i].get_course_time()->end_time << " " << courses[i].get_course_time()->location << " " << courses[i].get_current_enrollment();

        for (int j = 0; j < courses[i].get_current_enrollment(); j++) {
            newfile << " " << courses[i].get_roster(j);
        }

        newfile << "\n";
    }
    

}

/*********************************************************************
** Function: view_students()
** Description: allows a teacher to view the IDs of students in the specified class
** Parameters: int
** Pre-Conditions: n/a 
** Post-Conditions: the IDs of the students in the class are displayed
*********************************************************************/ 
void University::view_students() {
    string course_to_view;

    cout << "What course do you want to see the students in?" << endl;
    cin >> course_to_view;

    for (int i = 0; i < num_courses; i++) {
        if (courses[i].get_name() == course_to_view) {
            for (int j = 0; j < courses[i].get_current_enrollment(); j++) {
                cout << "The ID of the student " << j+1 << " in " << course_to_view << " is " << courses[i].get_roster(j) << endl;
            }
        }
    }
}

/*********************************************************************
** Function: get_new_course_info()
** Description: gets info about a course the teacher wants to create
** Parameters: int
** Pre-Conditions: n/a 
** Post-Conditions: returns a new course that can be printed out
*********************************************************************/ 
Course University::get_new_course_info() {
    Course new_c;
    string name;
    string teacher;
    int current_enrollment;
    schedule* course_time;

    cout << " Enter course deatils in this order: name, teacher, current enrollment, roster, days, start time, end time, term, location:\n";
    cin >> name;
    new_c.set_name(name);
    cin >> teacher;
    new_c.set_teacher(teacher);
    cin >> current_enrollment;
    new_c.set_current_enrollment(current_enrollment);
    
    string roster[current_enrollment];
    new_c.set_roster(roster);

    for (int i = 0; i < current_enrollment; i++) {
        cin >> roster[i];
    }

    course_time = new schedule;

    cin >> new_c.get_course_time()->days;
    cin >> new_c.get_course_time()->start_time;
    cin >> new_c.get_course_time()->end_time;
    cin >> new_c.get_course_time()->term;
    cin >> new_c.get_course_time()->location;

    return new_c;

}

/*********************************************************************
** Function: remove_student()
** Description: allows a teacher to remove a student
** Parameters: int
** Pre-Conditions: n/a 
** Post-Conditions: takes a students ID off of the courses text file
*********************************************************************/ 
void University::remove_student() {
    string course_to_remove_student;
    int ID_to_remove;
    int IDcounter = 0;

    cout << "What course do you want to remove a student from?" << endl;
    cin >> course_to_remove_student;

    for (int i = 0; i < num_courses; i++) {
        if (courses[i].get_name() == course_to_remove_student) {
            for (int j = 0; j < courses[i].get_current_enrollment(); j++) {
                cout << "Student " << j+1 << "'s ID is " << courses[i].get_roster(j) << endl;
                IDcounter++;
            }
        }
    }
    cout << "Which student do you want to remove? Enter their ID:" << endl;
    cin >> ID_to_remove;

    for (int i = 0; i < num_courses; i++) {
        if (courses[i].get_name() == course_to_remove_student) {
            for (int j = 0; j < courses[i].get_current_enrollment(); j++) {
                if (courses[i].get_roster(j) == to_string(ID_to_remove)) {
                    courses[i].get_roster(j) = " ";
                }       
            }
        }
    }
}

/*********************************************************************
** Function: view_enrollment_and_address()
** Description: allows a teacher to view the universities enrollment and addrss
** Parameters: university object refernce
** Pre-Conditions: n/a 
** Post-Conditions: displays the universities total enrollment and address
*********************************************************************/
void University::view_enrollment_and_address(University &U1) {
    int total_enrollment = 0;
    
    for (int i = 0; i < num_courses; i++) {
        total_enrollment += courses[i].get_current_enrollment();
    }
    cout << "The total enrollment at this university is: " << total_enrollment << endl;
    cout << "The address of this university is " << U1.get_address() << endl;
}
