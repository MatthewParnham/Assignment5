#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include "Person.h"
#include "Student.h"
#include "GenDoublyLL.h"

using namespace std;

class Faculty : public Person {
public:
  Faculty(); //advisee list is left empty in both constructors
  Faculty(int id, string n, string l, string d); //takes ID, name, level, and department as args
  ~Faculty();

  string getDepartment();
  void setDepartment(string d);

  GenDoublyLL<int> *adviseeList;

//comparison operators overloaded
  friend bool operator>(Faculty& s1, Faculty& s2);
  friend bool operator>(Faculty& s1, int i);
  friend bool operator<(Faculty& s1, Faculty& s2);
  friend bool operator<(Faculty& s1, int i);
  friend bool operator==(Faculty& s1, Faculty& s2);
  friend bool operator==(Faculty& s1, int i);
  friend bool operator!=(Faculty& s1, Faculty& s2);
  friend bool operator!=(Faculty& s1, int i);
  friend ostream& operator<<(ostream& os, const Faculty& s1);
private:
  string department;

};


#endif
