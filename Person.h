#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "BST.h"
#include "GenStack.h"
#include "Faculty.h"
#include "Menu.h"
#include "Student.h"
#include "TreeNode.h"

class Person {
public:
  Person();
  Person(int id, string n, string l);
  ~Person();

  int getID();
  void setID(int id);

  string getName();
  void setName(string n);

  string getLevel();
  void setLevel(string l);
private:
  int ID;
  string name;
  string level;
};

#endif
