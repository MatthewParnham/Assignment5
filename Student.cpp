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
