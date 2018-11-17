#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include "GenDoublyLL.h"

using namespace std;

class Faculty : public Person {
public:
  Faculty();
  ~Faculty();

  string getDepartment();
  void setDepartment(string d);

  GenDoublyLL adviseeList;
private:
  string department;

};


#endif
