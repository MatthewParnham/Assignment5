#include "Person.h"

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

//operator overloading
bool Person::operator>(Person* other) {
  return this->getID() > other->getID();
}
bool Person::operator<(Person* other) {
  return this->getID() < other->getID();
}
bool Person::operator==(Person* other) {
  return this->getID() == other->getID();
}
int Person::operator<<(Person* p) {
  return p->ID;
}
