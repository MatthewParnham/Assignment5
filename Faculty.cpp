#include "Faculty.h"
#include <iostream>

using namespace std;

Faculty::Faculty() {
  ID = 0;
  name = "NULL";
  level = "NULL";
  department = "NULL";
  adviseeList = new GenDoublyLL<int>();
}
Faculty::Faculty(int id, string n, string l, string d) {
  ID = id;
  name = n;
  level = l;
  department = d;
  adviseeList = new GenDoublyLL<int>();
}
Faculty::~Faculty() {

}

string Faculty::getDepartment() {
  return department;
}
void Faculty::setDepartment(string d) {
  department = d;
}


//operator overloading
bool operator>(Faculty& t1, Faculty& t2) {
  return t1.getID() > t2.getID();
}
bool operator>(Faculty& t1, int i) {
  return t1.getID() > i;
}
bool operator<(Faculty& t1, Faculty& t2) {
  return t1.getID() < t2.getID();
}
bool operator<(Faculty& t1, int i) {
  return t1.getID() < i;
}
bool operator==(Faculty& t1, Faculty& t2) {
  return t1.getID() == t2.getID();
}
bool operator==(Faculty& t1, int i) {
  return t1.getID() == i;
}
bool operator!=(Faculty& t1, Faculty& t2) {
  return t1.getID() != t2.getID();
}
bool operator!=(Faculty& t1, int i) {
  return t1.getID() != i;
}
ostream& operator<<(ostream& os, const Faculty& t1) {
  os << "ID: " << t1.ID << " Name: " << t1.name << " Level: "
  << t1.level << " Department: " << t1.department << " Advisees: ";

  ListNode<int> *curr = t1.adviseeList->getFront();

  while(curr != NULL)
  {
    os << *curr->data << " ";
    curr = curr->next;
  }
  return os;
}
