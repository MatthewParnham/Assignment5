#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include "Person.h"
#include "Student.h"
#include "GenDoublyLL.h"

using namespace std;

class Faculty : public Person {
public:
  Faculty();
  Faculty(int id, string n, string l, string d);
  ~Faculty();

  string getDepartment();
  void setDepartment(string d);

  GenDoublyLL<Student> *adviseeList;

  friend bool operator>(Faculty& s1, Faculty& s2);
  friend bool operator<(Faculty& s1, Faculty& s2);
  friend bool operator==(Faculty& s1, Faculty& s2);
  friend ostream& operator<<(ostream& os, const Faculty& s1);
private:
  string department;

};


#endif
