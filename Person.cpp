#include <iostream>
#include "BST.h"
#include "GenStack.h"
#include "Faculty.h"
#include "Menu.h"
#include "Person.h"
#include "Student.h"
#include "TreeNode.h"

Person::Person() {
  ID = 0;
  name = "NULL";
  level = "NULL";
}

Person::Person(int id, string n, string l) {
  ID = id;
  name = n;
  level = l;
}

Person::~Person() {

}

int Person::getID() {
  return ID;
}
void Person::setID(int id) {
  ID = id;
}

string Person::getName() {
  return name;
}
void Person::setName(string n) {
  name = n;
}

string Person::getLevel() {
  return level;
}
void Person::setLevel(string l) {
  level = l;
}
