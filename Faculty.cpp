#include "Faculty.h"
#include <iostream>

using namespace std;

Faculty::Faculty() {

}
Faculty::~Faculty() {

}

string Faculty::getDepartment() {
  return department;
}
void Faculty::setDepartment(string d) {
  department = d;
}
