#include <iostream>
#include "GenBST.h"
#include "GenStack.h"
#include "Faculty.h"
#include "Menu.h"
#include "Person.h"
#include "Student.h"
#include "GenTreeNode.h"
#include "GenDoublyLL.h"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  //Testing

  //program start

  ///*

  // Declare Tables
  GenBST<Student> masterStudent;
  GenBST<Faculty> masterFaculty;

  // Check if save file exists

  ifstream in;
  in.open("masterStudent");
  if(in) {
    string line;
    while(getline(in, line)) {
      int ID = stoi(line.substr(4,(line.find("Name")-5)));
      string name = line.substr(line.find("Name")+6,line.find("Level")-1-line.find("Name")+6);
      string level = line.substr(line.find("Level")+7,line.find("Major")-1-line.find("Level")+7);
      string major = line.substr(line.find("Major")+7,line.find("Advisor")-1-line.find("Major")+7);
      int advisor = stoi(line.substr(line.find("Advisor")+9,string::npos));
      masterStudent.insert(*(new Student(ID,name,level,major,advisor)));
    }
  }
  in.close();
  masterStudent.printTree();
  // // Load save files
  // if(saveFound) {
  //
  // }

  //else - generate new empty tables
  // else {
  //   masterStudent = new GenBST();
  //   masterFaculty = new GenBST();
  // }
  masterStudent.insert(*(new Student(10,"Matthew Parnham","Sophomore","Software Engineering",1)));
  // Menu loop
  //while(true) {
    Menu menu;
    int ans;
    menu.printMenu();
    cin >> ans;
    menu.prompt(ans);
  //}

  //*/

  // Save
  ofstream out;
  out.open("masterStudent");
  masterStudent.saveTree(out, masterStudent.getRoot());
  out.close();

  return 0;
}
