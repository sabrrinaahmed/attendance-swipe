#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using std::cout, std::endl, std::string;

void Student::addCourse(std::string course_id){
	for(unsigned int i = 0; i < course_ids.size(); i++){
		if(course_ids[i] == course_id){
			throw std::invalid_argument("invalid argument");
		}
	}
	course_ids.push_back(course_id);
}

void Student::listCourses(std::ostream& os) const{
	os << "Courses for " << id << "\n";
	if(course_ids.size() == 0){
		os << "No courses" << "\n";
	} else {
		for(unsigned int i = 0; i < course_ids.size(); i++){
			os << course_ids[i] << "\n";
		}
	}
}

/*int main(){
	Student s("123456789", "Namey McNameerson");
	cout << s.get_id() << endl;
	cout << s.get_name() << endl;
	s.addCourse("121");
	s.addCourse("222");
	//s.addCourse("121");
	//cout << s.get_courseID(0) << endl;
	//cout << s.get_name() << " " << s.get_id() << endl;
	s.listCourses(cout);

}*/
