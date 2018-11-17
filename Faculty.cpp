#include "Faculty.h"
#include <iostream>

using namespace std;

Faculty::Faculty() {
  ID = 0;
  name = "NULL";
  level = "NULL";
  department = "NULL";
  adviseeList = new GenDoublyLL<Student>();
}
Faculty::Faculty(int id, string n, string l, string d) {
  ID = id;
  name = n;
  level = l;
  department = d;
  adviseeList = new GenDoublyLL<Student>();
}
Faculty::~Faculty() {
  delete adviseeList;
}

string Faculty::getDepartment() {
  return department;
}
void Faculty::setDepartment(string d) {
  department = d;
}


//operator overloading
bool Faculty::operator>(Faculty* other) {
  return this->getID() > other->getID();
}
bool Faculty::operator<(Faculty* other) {
  return this->getID() < other->getID();
}
bool Faculty::operator==(Faculty* other) {
  return this->getID() == other->getID();
}
int Faculty::operator<<(Faculty* p) {
  return p->ID;
}
