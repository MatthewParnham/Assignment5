#include "Faculty.h"
#include <iostream>

using namespace std;

Faculty::Faculty() {
  ID = 0;
  name = "NULL";
  level = "NULL";
  department = "NULL";
}
Faculty::Faculty(int id, string n, string l, string d) {
  ID = id;
  name = n;
  level = l;
  department d;
}
Faculty::~Faculty() {
  delete adviseeList;
}

string Faculty::getDepartment() {
  return department;
}
void Faculty::setDepartment(string d) {
  department = d;
}
