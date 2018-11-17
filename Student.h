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
private:
  string major;
  int advisor;

};

#endif
