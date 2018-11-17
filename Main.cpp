#include <iostream>
#include "GenBST.h"
#include "GenStack.h"
#include "Faculty.h"
#include "Menu.h"
#include "Person.h"
#include "Student.h"
#include "GenTreeNode.h"
#include "GenDoublyLL.h"

using namespace std;

int main(int argc, char const *argv[]) {
  //Testing
  Student* s1 = new Student();
  Student* s2 = new Student();
  s1->setID(5);
  s2->setID(2);
  cout << (s1) << endl;

  // Declare Tables
  GenBST<Student> masterStudent;
  GenBST<Faculty> masterFaculty;

  // Check if save file exists

  // // Load save files
  // if(saveFound) {
  //
  // }

  //else - generate new empty tables
  // else {
  //   masterStudent = new GenBST();
  //   masterFaculty = new GenBST();
  // }

  // Menu loop
  Menu menu;
  int ans;
  menu.printMenu();
  cin >> ans;
  menu.prompt(ans);

  // Save
  return 0;
}
