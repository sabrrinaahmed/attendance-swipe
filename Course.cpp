#include <iostream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"
#include <sstream>
#include <fstream>
#include <vector>
//#include "School.h"

using std::string, std::ostream, std::ifstream, std::istringstream, std::endl, std::cout;

AttendanceRecord::AttendanceRecord(std::string course_id, std::string student_id, Date time):course_id(course_id), student_id(student_id), time(time){;}
Course::Course(std::string id, std::string title, Date startTime, Date endTime): id(id), title(title), startTime(startTime), endTime(endTime){;}
//School::School(){;}

void Course::addAttendanceRecord(AttendanceRecord ar){
	string courseID = ar.getCourseID();
	string studentID = ar.getStudentID();
	string strTime = ar.getDate().getTime(true);

	istringstream ss(strTime);
	string strHour;
	string strMin;
	string strSec;
	getline(ss, strHour, ':');
	getline(ss, strMin, ':');
	getline(ss, strSec);

	int hour = stoi(strHour);
    int min = stoi(strMin);
    int sec = stoi(strSec);

    Date time(hour, min, sec);
    AttendanceRecord add(courseID, studentID, time);

    attendanceRecords.push_back(add);
}

void Course::outputAttendance(std::ostream& os, std::string course_id) const{
	if(attendanceRecords.size() == 0){
		os << "No Records" << '\n';
	} else {
		int intCourseID = std::stoi(course_id);
		for(unsigned int i = 0; i < attendanceRecords.size(); i++){
			int intVectorCourseID = std::stoi(attendanceRecords[i].getCourseID());
			if(intCourseID == intVectorCourseID){
				string strDateTime = attendanceRecords[i].getDate().getDateTime();

				istringstream ss(strDateTime);

				string strYear;
		        string strMonth;
		        string strDay;
		        string strHour;
		        string strMin;
		        string strSec;

		        getline(ss, strYear, '/');
		        getline(ss, strMonth, '/');
		        getline(ss, strDay, ' ');
		        getline(ss, strHour, ':');
		        getline(ss, strMin, ':');
		        getline(ss, strSec, ',');


				os << strMonth << "/" << strDay << "/" << strYear << " " << strHour << ":" << strMin << ":" << strSec << "," << course_id << "," << attendanceRecords[i].getStudentID() << '\n'; 
			}
		}
	}
}	
  
void Course::outputStudentAttendance(std::ostream& os, std::string student_id, std::string course_id) const{
	if(attendanceRecords.size() == 0){
		os << "No Records" << '\n';
	} else {
		bool none = true;
		int intCourseID = std::stoi(course_id);
		int intStudentID = std::stoi(student_id);
		for(unsigned int i = 0; i < attendanceRecords.size(); i++){
			int intVectorCourseID = std::stoi(attendanceRecords[i].getCourseID());
			int intVectorStudentID = std::stoi(attendanceRecords[i].getStudentID());
			if(intCourseID == intVectorCourseID && intStudentID == intVectorStudentID){
				none = false;
				string strDateTime = attendanceRecords[i].getDate().getDateTime();

				istringstream ss(strDateTime);

				string strYear;
		        string strMonth;
		        string strDay;
		        string strHour;
		        string strMin;
		        string strSec;

		        getline(ss, strYear, '/');
		        getline(ss, strMonth, '/');
		        getline(ss, strDay, ' ');
		        getline(ss, strHour, ':');
		        getline(ss, strMin, ':');
		        getline(ss, strSec, ',');

				os << strMonth << "/" << strDay << "/" << strYear << " " << strHour << ":" << strMin << ":" << strSec << "," << course_id << "," << attendanceRecords[i].getStudentID() << '\n'; 
			}
		}
		if(none){
			os << "No records" << '\n';
		}
	}
}
