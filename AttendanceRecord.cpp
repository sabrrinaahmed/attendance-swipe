#include <string>
#include <iostream>
#include "AttendanceRecord.h"
#include "Date.h"

using std::string, std::ostream, std::endl, std::cout;

//AttendanceRecord::AttendanceRecord(std::string course_id, std::string student_id, Date time):course_id(course_id), student_id(student_id), time(time){;}

std::ostream& operator<<(std::ostream& os, const AttendanceRecord& ar){
	return os << ar;
}
