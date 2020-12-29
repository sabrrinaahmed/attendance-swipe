#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <ostream>
#include "School.h"
#include "AttendanceRecord.h"

using std::string, std::ostream, std::ifstream, std::istringstream, std::endl, std::cout;

// one method is provided to students; students implement all other methods
Course::Course(){;}
Date::Date(){;}
Student::Student(): id(id), name(name){;}
School::School(){;}
//AttendanceRecord::AttendanceRecord(std::string course_id, std::string student_id, Date time):course_id(course_id), student_id(student_id), time(time){;}


void School::addStudents(string filename) {
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::invalid_argument("addStudents: can't open file");
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    istringstream ss(line);
    string uin;
    getline(ss, uin, ',');
    string name;
    getline(ss, name);
    if (!ss.fail()) {
        Student student(uin, name);
        bool exists = false;
        for (Student s : students) {
            if (s == student) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            students.push_back(student);
        }
    }
  }
}

bool School::isEnrolled(std::string student_id) const{
    for(unsigned int i = 0; i < students.size(); i++){
        string id = students[i].get_id();
        if(id == student_id){
            return true;
        }
    }
    return false;

}
void School::listStudents(std::ostream& os) const{
    if(students.size() == 0){
        os << "No students" << "\n";
    } else {
        for(unsigned int i = 0; i < students.size(); i++){
            os << students[i].get_id() << "," << students[i].get_name() << "\n";
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Student& s){
    return os << s;
}

std::ostream& operator<<(std::ostream& os, const Course& c){
    return os << c;
}

std::ostream& operator<<(std::ostream& os, const Date& d){
    return os << d;
}

void School::addCourses(std::string filename){
  std::ifstream ifs(filename);
  if (!ifs.is_open()) {
    throw std::invalid_argument("addCourses: can't open file");
  }
  while (!ifs.eof()) {
    string line;
    getline(ifs, line);
    if(line == ""){
        break;
    }
    std::istringstream ss(line);

    string courseNum;
    getline(ss, courseNum, ',');

    string stringstartHour;
    string stringstartMin;
    getline(ss, stringstartHour, ':');
    getline(ss, stringstartMin, ',');
    int startHour = stoi(stringstartHour);
    int startMin = stoi(stringstartMin);

    string stringendHour;
    string stringendMin;
    getline(ss, stringendHour, ':');
    getline(ss, stringendMin, ',');
    int endHour = stoi(stringendHour);
    int endMin = stoi(stringendMin);

    Date startTime(startHour,startMin,0);
    Date endTime(endHour, endMin, 0);

    string title;
    getline(ss, title);
    Course course(courseNum, title, startTime, endTime);
    courses.push_back(course);
  }
}

void School::listCourses(std::ostream& os) const{
    //cout << courses.size() << endl;
    if(courses.size() == 0){
        os << "No courses" << "\n";
    } else {
        for(unsigned int i = 0; i < courses.size(); i++){
            os << courses[i].getID() << "," << courses[i].getStartTime().getTime(false) << "," << courses[i].getEndTime().getTime(false) << "," << courses[i].getTitle() << "\n";
        }
    }
}

unsigned int School::addAttendanceData(std::string filename){
    unsigned int invalid = 0;
    bool invalidBool = false;
    //Course c;
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        throw std::invalid_argument("addAttendanceData: can't open file");
    }
    while (!ifs.eof()) {
        invalidBool = false;
        string line;
        getline(ifs, line);
        if(line == ""){
            break;
        }
        istringstream ss(line);

        string strMonth;
        string strDay;
        string strYear;
        string strHour;
        string strMin;
        string strSec;
        string strCourseID;
        string strStudentID;

        getline(ss, strMonth, '-');
        getline(ss, strDay, '-');
        getline(ss, strYear, ' ');
        getline(ss, strHour, ':');
        getline(ss, strMin, ':');
        getline(ss, strSec, ',');
        getline(ss, strCourseID, ',');
        getline(ss, strStudentID, ',');

        int month = stoi(strMonth);
        int day = stoi(strDay);
        int year = stoi(strYear);
        int hour = stoi(strHour);
        int min = stoi(strMin);
        int sec = stoi(strSec);
        
        Date date(year, month, day, hour, min, sec);

        bool studentBool = false;
        for(unsigned int i = 0; i < students.size(); i++){
            string studentID = students[i].get_id();
            if(studentID == strStudentID){
                studentBool = true;
                i = students.size() - 1;
            }
        }
        if(studentBool == false){
            invalidBool = true;
        }

        bool courseBool = false;
        for(unsigned int i = 0; i < courses.size(); i++){
            string course = courses[i].getID();
            if(course == strCourseID){
                courseBool = true;
                i = courses.size() - 1;
            }
        }
        if(courseBool == false){
            invalidBool = true;
        }

        if(date.isValid()){
            invalidBool = true;
        }

        if(invalidBool){
            invalid++;
        }
        
        if(invalidBool == false){
            AttendanceRecord ar(strCourseID, strStudentID, date);
            c.addAttendanceRecord(ar);
        }
    }
    return invalid;
}

void School::outputCourseAttendance(std::ostream& os, std::string course_id) const{
    c.outputAttendance(cout, course_id);
}

void School::outputStudentAttendance(std::ostream& os, std::string student_id, std::string course_id) const{
    c.outputStudentAttendance(cout, student_id, course_id);
}