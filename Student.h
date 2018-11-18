#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person {
public:
  Student();
  Student(int id, string n, string l, string m, int a);
  ~Student();

  string getMajor();
  void setMajor(string m);

  int getAdvisor();
  void setAdvisor(int a);

  friend bool operator>(Student& s1, Student& s2);
  friend bool operator<(Student& s1, Student& s2);
  friend bool operator==(Student& s1, Student& s2);
  friend ostream& operator<<(ostream& os, const Student& s1);
private:
  string major;
  int advisor;

};

#endif
