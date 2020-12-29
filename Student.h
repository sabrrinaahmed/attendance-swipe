#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>

class Student {
  std::string id;
  std::string name;
  std::vector<std::string> course_ids = {};
  
public:
  Student();
  Student(std::string student_id, std::string name):id(student_id), name(name){}
  std::string get_id() const {return id;}
  std::string get_name() const {return name;}
  std::string get_courseID(unsigned int index) const {return course_ids[index];}
  void addCourse(std::string course_id);
  void listCourses(std::ostream& os) const;
  bool operator==(const Student& other) { 
  	return name == other.name && id == other.id;
  }
};

std::ostream& operator<<(std::ostream& os, const Student& s);

#endif