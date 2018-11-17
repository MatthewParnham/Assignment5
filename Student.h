#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "BST.h"
#include "GenStack.h"
#include "Faculty.h"
#include "Menu.h"
#include "Person.h"
#include "TreeNode.h"

class Student : public Person {
public:
  Student();
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
