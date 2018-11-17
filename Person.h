#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

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

protected:
  int ID;
  string name;
  string level;
};

#endif
