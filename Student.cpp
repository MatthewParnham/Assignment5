#include <iostream>
#include "GenBST.h"
#include "GenStack.h"
#include "Faculty.h"
#include "Menu.h"
#include "Person.h"
#include "Student.h"
#include "GenTreeNode.h"

Student::Student() {
  ID = 0;
  name = "NULL";
  level = "NULL";
  major = "NULL";
  advisor = 0;
}

Student::Student(int id, string n, string l, string m, int a)
{
  ID = id;
  name = n;
  level = l;
  major = m;
  advisor = a;
}

Student::~Student() {

}

string Student::getMajor() {
  return major;
}
void Student::setMajor(string m) {
  major = m;
}

int Student::getAdvisor() {
  return advisor;
}
void Student::setAdvisor(int a) {
  advisor = a;
}

//operator overloading
bool operator>(Student& s1, Student& s2) {
  return s1.getID() > s2.getID();
}
bool operator<(Student& s1, Student& s2) {
  return s1.getID() < s2.getID();
}
bool operator==(Student& s1, Student& s2) {
  return s1.getID() == s2.getID();
}
bool operator!=(Student& s1, Student& s2) {
  return s1.getID() != s2.getID();
}
bool operator>(Student& s1, int i) {
  return s1.getID() > i;
}
bool operator<(Student& s1, int i) {
  return s1.getID() < i;
}
bool operator==(Student& s1, int i) {
  return s1.getID() == i;
}
bool operator!=(Student& s1, int i) {
  return s1.getID() != i;
}
ostream& operator<<(ostream& os, const Student& s1) {
  os << "ID: " << s1.ID << " Name: " << s1.name << " Level: " << s1.level << " Major: " << s1.major << " Advisor: " << s1.advisor;
  return os;
}
