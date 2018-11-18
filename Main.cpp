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
  Student s1;
  Student s2;
  s1.setID(5);
  s2.setID(2);
  cout << s1 << endl;
  s2.setName("Rene German");
  s2.setLevel("Freshman");
  s2.setMajor("Computer Science");
  cout << s2 << endl;
  cout << "\n\n";
  if (s1 > s2)
    cout << s1 << endl;
  else
    cout << s2 << endl;

  cout << (s1 == s2) << endl;
  s2.setID(5);
  cout << (s1 == s2) << endl;

  cout << "=========================================================\n\n";
  //program start

  /*

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
  while(true) {
    Menu menu;
    int ans;
    menu.printMenu();
    cin >> ans;
    menu.prompt(ans);
  }

  //*/

  // Save
  return 0;
}
