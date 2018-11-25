#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person {
public:
  Student();
  Student(int id, string n, string l, string m, double g, int a); //takes ID, name, level, major, and advisor's ID as args
  ~Student();

  string getMajor();
  void setMajor(string m);

  int getAdvisor();
  void setAdvisor(int a);

  double getGPA();
  void setGPA(double g);

  friend bool operator>(Student& s1, Student& s2);
  friend bool operator<(Student& s1, Student& s2);
  friend bool operator==(Student& s1, Student& s2);
  friend bool operator!=(Student& s1, Student& s2);
  friend bool operator>(Student& s1, int i);
  friend bool operator<(Student& s1, int i);
  friend bool operator==(Student& s1, int i);
  friend bool operator!=(Student& s1, int i);
  friend ostream& operator<<(ostream& os, const Student& s1);

  int advisor;
private:
  string major;

  double GPA;

};

#endif
